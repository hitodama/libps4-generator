#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <unistd.h>

#define IP(a, b, c, d) (((a) << 0) + ((b) << 8) + ((c) << 16) + ((d) << 24))
#define htonll(x) ((1==htonl(1)) ? (x) : ((uint64_t)htonl((x) & 0xFFFFFFFF) << 32) | htonl((x) >> 32))
#define ntohll(x) ((1==ntohl(1)) ? (x) : ((uint64_t)ntohl((x) & 0xFFFFFFFF) << 32) | ntohl((x) >> 32))

#define MessageSize 128

size_t argString(char *res, size_t length, int argc, char **argv)
{
	int i, j, k;

	if(res == NULL || length == 0)
		return -1;

	if(argc == 0 || argv == NULL)
	{
		res[0] = '\0';
		return 0;
	}

	i = j = k = 0;
	while(i < argc && j < length)
	{
		if(argv[i][k] == '\0')
		{
			res[j++] = ' ';
			++i;
			k = 0;
		}
		if(i >= argc || j >= length)
			break;
		res[j++] = argv[i][k++];
	}
	res[j - 1] = '\0';

	return j - 1;
}

char *argStringAlloc(char **res, size_t *length, int argc, char **argv)
{
	int i;
	char *r;
	size_t l = 0;

	if(argc == 0 || argv == NULL)
		return NULL;

	for(i = 0; i < argc; ++i)
		l += strlen(argv[i]) + 1;

	r = malloc(l);
	if(r == NULL)
		return NULL;

	argString(r, l, argc, argv);

	if(length != NULL)
		*length = l;

	if(res != NULL)
		*res = r;

	return r;
}

int main(int argc, char **argv)
{
	int client;
	struct sockaddr_in clientAddress;

	char message[MessageSize];

	memset(&clientAddress, 0, sizeof(clientAddress));
	clientAddress.sin_family = AF_INET;
	clientAddress.sin_addr.s_addr = IP(192, 168, 178, 45);
	clientAddress.sin_port = htons(9025);

	client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(client < 0)
		return EXIT_FAILURE;

	if(connect(client, (struct sockaddr *)&clientAddress, sizeof(clientAddress)) < 0)
	{
		close(client);
		return EXIT_FAILURE;
	}

	argString(message, MessageSize, argc - 1, argv + 1);

	if(write(client, message, MessageSize) <= 0)
	{
		close(client);
		return EXIT_FAILURE;
	}

	if(read(client, message, MessageSize) <= 0)
	{
		close(client);
		return EXIT_FAILURE;
	}

	printf("%s", message);

	close(client);
}
