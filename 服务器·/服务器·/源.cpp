#define _CRT_SECURE_NO_WARNINGS 1
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{

	int socketfd = socket(AF_INET, SOCK_STREAM, 0);//��ʾ��IPV4��ַ�� //����ʽ�׽���//��ָ��Э�����ͣ�ϵͳ�Զ��������ָ��
	struct sockaddr_in serveraddr;//һ��ͨ�õ�ַ�ṹ
	memset(&serveraddr, 0, sizeof(serveraddr));//��ʼ��
	serveraddr.sin_family = AF_INET;//�����׽���ʱ���ø��ֶ�ָ����ַ���壬����TCP/IPЭ��ģ���������ΪAF_INET��
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");//server�����ö˿ں�ip
	serveraddr.sin_port = htons(8888);//server�����ö˿ں�ip
	int connectfd = connect(socketfd, (struct sockaddr*)(&serveraddr), sizeof(serveraddr));//�ͻ���socket���ص��ļ�������.
	//�����˷������˵�������Ϣ.����sin_add�Ƿ���˵ĵ�ַ
	//�ͻ�������ͬ��������ӵ�.�ɹ�ʱ����0, sockfd��ͬ�����ͨѶ���ļ�������ʧ��ʱ���� - 1
	char buffer[1024] = { 0 };
	char recvbuffer[1024] = { 0 };
	if (fork == 0)//�ӽ���
	{

		recvfrom(socketfd, recvbuffer, sizeof(buffer), 0, (struct sockaddr*)(&serveraddr), sizeof(serveraddr));//���յ�ַ
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