#define _CRT_SECURE_NO_WARNINGS 1
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serveraddr.sin_port = htons(8888);
	int connectfd = connect(socketfd, (struct sockaddr*)(&serveraddr), sizeof(serveraddr));
	char buffer[1024] = { 0 };
	char mybreak[] = "break";
	char recvbuffer[1024] = { 0 };
	if (fork() == 0)
	{
		while (1)
		{

			fgets(buffer, 1024, stdin);
			write(socketfd, buffer, sizeof(buffer));
			if (buffer[0] == 'b'&&buffer[1] == 'r'&&buffer[2] == 'e'&&buffer[3] == 'a'&&buffer[4] == 'k')
			{

				break;
			}
		}
		close(socketfd);
		exit(0);
	}
	read(socketfd, recvbuffer, sizeof(recvbuffer));
}