#define _XOPEN_SOURCE 700
#define __BSD_VISIBLE 1
#define _DEFAULT_SOURCE 1

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

#define MessageSize 128

int main(void)
{
	int server, client;
	struct sockaddr_in serverAddress, clientAddress;

	char message[MessageSize];

	char m1[] = "libSceLibcInternal.sprx";
	char m2[] = "libkernel.sprx";
	char m3[] = "librt.sprx";
	char *modules[] = {m1, m2, m3};

	int run = 1;

	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_len = sizeof(serverAddress);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(9025);

	memset(&clientAddress, 0, sizeof(clientAddress));

	server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(server < 0)
		return EXIT_FAILURE;

	setsockopt(server, SOL_SOCKET, SO_REUSEADDR, (char *)&(int){ 1 }, sizeof(int));
	setsockopt(server, SOL_SOCKET, SO_REUSEPORT, (char *)&(int){ 1 }, sizeof(int));

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

	while(run)
	{
		client = accept(server, NULL, NULL);

		if(client < 0)
			continue;

		while(1)
		{
			char moduleName[128];
			char symbolName[128];
			int module = 0;
			void *symbol = NULL;
			int state = 0; // sym - base could be 0
			int i;
			PS4ResolveStatus r;

			SceKernelModuleInfo info;
			info.size = sizeof(SceKernelModuleInfo);

			if(read(client, message, MessageSize) <= 0)
				break;

			if(strncmp(message, "exit\0", 5) == 0)
			{
				run = 0;
				break;
			}

			if(sscanf(message, "%s %s", moduleName, symbolName) < 2)
				break;

			module = sceKernelLoadStartModule(moduleName, 0, NULL, 0, NULL, NULL);
			r = sceKernelDlsym(module, symbolName, &symbol);
			/* should use dlsym and lsm from kernel instead */
			for(i = 0; i < sizeof(modules) / sizeof(modules[0]) && r != 0; ++i)
			{
				if(strcmp(modules[i], moduleName) == 0)
					continue;
				module = sceKernelLoadStartModule(modules[i], 0, NULL, 0, NULL, NULL);
				r = sceKernelDlsym(module, symbolName, &symbol);
				if(r == 0)
					strcpy(moduleName, modules[i]);
			}

			if(symbol != 0)
			{
				state = 1;
				if(sceKernelGetModuleInfo(module, &info) == 0)
					symbol = (void *)((uintptr_t)symbol - (uintptr_t)(info.segmentInfo[0].address));
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

	return EXIT_SUCCESS;
}
