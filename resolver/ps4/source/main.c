#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <unistd.h>

#include <kernel.h>

#include <ps4/internal/resolve.h>

#define IP(a, b, c, d) (((a) << 0) + ((b) << 8) + ((c) << 16) + ((d) << 24))
#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32))
#define ntohll(x) ((1==ntohl(1)) ? (x) : ((uint64_t)ntohl((x) & 0xFFFFFFFF) << 32) | ntohl((x) >> 32))

#define MessageSize 128

int64_t _main(void)
{
	int server, client;
	struct sockaddr_in serverAddress, clientAddress;

	char message[MessageSize];

	char m1[] = "libSceLibcInternal.sprx";
	char m2[] = "libkernel.sprx";
	/*char m3[] = "librt.sprx";*/
	char *modules[] = {m1, m2};

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_len = sizeof(serverAddress);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(9025);

	memset(&clientAddress, 0, sizeof(clientAddress));

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(server < 0)
		return EXIT_FAILURE;

	if(bind(server, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
	{
		close(server);
		return EXIT_FAILURE;
	}

	if(listen(server, 10) < 0)
	{
		close(server);
		return EXIT_FAILURE;
	}

	while(1)
	{
		client = accept(server, NULL, NULL);

		if(client < 0)
			continue;

		while(1)
		{
			char moduleName[128];
			char symbolName[128];
			int64_t module = 0;
			void *symbol = NULL;
			int state = 0; // sym - base could be 0
			int i;
			PS4ResolveStatus r;

			SceKernelModuleInfo info;
			info.size = sizeof(SceKernelModuleInfo);

			if(read(client, message, MessageSize) <= 0)
				break;

			if(sscanf(message, "%s %s", moduleName, symbolName) < 2)
				break;

			/* should use dlsym and lsm from kernel instead */
			r = ps4ResolveModuleAndSymbol(moduleName, symbolName, &module, &symbol);
			for(i = 0; i < sizeof(modules) / sizeof(modules[0]) && r != PS4ResolveStatusSuccess; ++i)
			{
				if(strcmp(modules[i], moduleName) == 0)
					continue;
				module = 0;
				r = ps4ResolveModuleAndSymbol(modules[i], symbolName, &module, &symbol);
				if(r == 0)
					strcpy(moduleName, modules[i]);
			}

			if(symbol != 0)
			{
				state = 1;
				if(sceKernelGetModuleInfo(module, &info) == 0)
					symbol = (void *)((uintptr_t)symbol - (uintptr_t)info.codeBase);
				else
					state = 2;
			}

			memset(message, 0, MessageSize);
			if(sprintf(message, "%s %"PRIxPTR" %i", moduleName, symbol, state) < 0)
				break;

			if(write(client, message, MessageSize) <= 0)
				break;
		}

		close(client);
	}

	close(server);
}
