#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in myaddr;
	memset(&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;////表示采用Ipv4网络协议
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//转换为二进制地址
	myaddr.sin_port = htons(8888);//表示端口号为8888，通常是大于1024的一个值
	int bindfd = bind(socketfd, (struct sockaddr*)(&myaddr), sizeof(myaddr));
	//是由上一步socket调用返回的文件描述符.
	//bind将本地的端口同socket返回的文件描述符捆绑在一起.成功是返回0,失败的情况和socket相同
	listen(socketfd, 20);//使服务器的这个端口和IP处于监听状态，
	                                //  等待网络中某一客户机的连接请求。如果客户端有连接请求，端口就会接受这个连接。
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	while (1)
	{
		int acceptfd = accept(socketfd, (struct sockaddr*)(&clnt_addr), &clnt_addr_size);//接受连接请求，代码默认阻塞。accept实际上是在从内核listen维护的就绪队列中取描述符。
		if (fork() == 0)
		{
			if (fork() == 0)
			{
				char buffer[1024] = { 0 };
				while (1)
				{
					read(acceptfd, buffer, sizeof(buffer));
					if (buffer[0] == 'b'&&buffer[1] == 'r'&&buffer[2] == 'e'&&buffer[3] == 'a'&&buffer[4] == 'k')
					{
						break;
					}
					else
					{
						printf("%s\n", buffer);
					}

					memset(&buffer, 0, sizeof(buffer));
				}
				exit(0);
			}
			wait(NULL);
			char mybuff[] = "Already receive";
			write(acceptfd, mybuff, sizeof(mybuff));
			close(acceptfd);
			exit(0);
		}
		close(acceptfd);
	}
}
