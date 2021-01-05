#define _CRT_SECURE_NO_WARNINGS 1
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);//表示用IPV4地址族 //用流式套接字//不指定协议类型，系统自动根据情况指定
	struct sockaddr_in serveraddr;//一个通用地址结构
	memset(&serveraddr, 0, sizeof(serveraddr));//初始化
	serveraddr.sin_family = AF_INET;//创建套接字时，用该字段指定地址家族，对于TCP/IP协议的，必须设置为AF_INET。
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");//server端设置端口和ip
	serveraddr.sin_port = htons(8888);//server端设置端口和ip
	int connectfd = connect(socketfd, (struct sockaddr*)(&serveraddr), sizeof(serveraddr));//客户端socket返回的文件描述符.
	//储存了服务器端的连接信息.其中sin_add是服务端的地址
	//客户端用来同服务端连接的.成功时返回0, sockfd是同服务端通讯的文件描述符失败时返回 - 1
	char buffer[1024] = { 0 };
	char recvbuffer[1024] = { 0 };
	if (fork == 0)//子进程
	{

		recvfrom(socketfd, recvbuffer, sizeof(buffer), 0, (struct sockaddr*)(&serveraddr), sizeof(serveraddr));//接收地址
		printf("%s", recvbuffer);
		exit(0);
	}
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
}