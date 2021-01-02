#define _CRT_SECURE_NO_WARNINGS 1
#include <sys/types.h>
#include <sys/socket.h>                         // �����׽��ֺ�����
#include <stdio.h>
#include <netinet/in.h>                         // ����AF_INET��ؽṹ
#include <arpa/inet.h>                          // ����AF_INET��ز����ĺ���
#include <unistd.h>
#include<string.h>
#include<time.h>

#define  PORT 8888
#define  IP_ADDR "192.168.1.116"

#define SIZE 10240

int main()
{

	struct tm *timeptr;
	time_t timeval;
	char tm[50];
	//(void)time(&timeval);

	//printf("the date is %s\n",ctime(&timeval));
	// printf("The time is %s\n",tm);

	int sockfd;                                 // ���ڱ���ͻ��׽��ֱ�ʶ��
	int len;                                    // ���ڿͻ���Ϣ����
	struct sockaddr_in address;                 // ����ͻ��׽��ֵ�ַ

	int result;


	sockfd = socket(AF_INET, SOCK_STREAM, 0);    // �����׽�������
	address.sin_family = AF_INET;               // �����׽��ֵ�ַ�е���

	address.sin_addr.s_addr = inet_addr(IP_ADDR);                           // �����׽��ֵ�ַ

	address.sin_port = htons(PORT);                 // �����׽��ֶ˿�
	char buf[100];                              // ����Ҫ���͵���Ϣ
	memset(buf, 0, 100);
	char str[90];                       //������������

	char shmaddr[SIZE];                    //���ܷ��������͵�ȫ���������� 
	int i = 0;

	char myname[100];
	char say[10] = { "˵��" };
	printf("��ӭ���������ң��������������:\n");
	scanf("%s", myname);



	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len); // ��������

	if (result == -1)
	{
		perror("Connect failed");
		return 1;
	}
	printf("%s�ɹ���¼������:\n", myname);


	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		printf("fork failed");
	}

	int sendbytes = 0;

	if (pid == 0)              //�ӽ������ڷ�������
	{
		while (1)
		{
			printf("���������:\n");

			scanf("%s", str);

			(void)time(&timeval);
			strcpy(tm, ctime(&timeval));

			strcpy(buf, myname);             //��������buf��
			strcat(buf, tm);                 //ʱ�䴫��buf��
			strcat(buf, say);
			strcat(buf, str);                //��䴫��bufz��

			//read(0,buf,strlen(buf));

			// send(sockfd,buf,strlen(buf),0);
			// getchar();

			if ((sendbytes = write(sockfd, buf, 100)) == -1)
			{
				perror("send to server failed:");
			}  // �������������Ϣ

			// printf("sendbytes=%d\n",sendbytes);
			//  printf("buf=%s\n",buf);
			//   printf("input buf=%s\n",buf);   
			usleep(1000);

			memset(buf, 0, 100);
			memset(tm, 0, 50);
		}
	}

	if (pid>0)               //���������ڽ�����Ϣ����ȡ
	{
		while (1)
		{
			read(sockfd, shmaddr, SIZE);
			// printf("server send shmaddr=%s\n",shmaddr);

			if (*(shmaddr + i * 100) != 0)
			{
				printf("%s\n", (shmaddr + i * 100));
				i++;

			}

			usleep(1000);
		}


	}


	close(sockfd);
	return 0;


}

