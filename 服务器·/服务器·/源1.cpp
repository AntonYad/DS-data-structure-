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
	myaddr.sin_family = AF_INET;////��ʾ����Ipv4����Э��
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");//ת��Ϊ�����Ƶ�ַ
	myaddr.sin_port = htons(8888);//��ʾ�˿ں�Ϊ8888��ͨ���Ǵ���1024��һ��ֵ
	int bindfd = bind(socketfd, (struct sockaddr*)(&myaddr), sizeof(myaddr));
	//������һ��socket���÷��ص��ļ�������.
	//bind�����صĶ˿�ͬsocket���ص��ļ�������������һ��.�ɹ��Ƿ���0,ʧ�ܵ������socket��ͬ
	listen(socketfd, 20);//ʹ������������˿ں�IP���ڼ���״̬��
	                                //  �ȴ�������ĳһ�ͻ�����������������ͻ������������󣬶˿ھͻ����������ӡ�
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	while (1)
	{
		int acceptfd = accept(socketfd, (struct sockaddr*)(&clnt_addr), &clnt_addr_size);//�����������󣬴���Ĭ��������acceptʵ�������ڴ��ں�listenά���ľ���������ȡ��������
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
