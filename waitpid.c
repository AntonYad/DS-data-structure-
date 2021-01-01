#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
pid_t pc,pr;
pc=fork();
if (pc<0)/* fork����*/
{
printf("fork error\n");
exit(1);
}
else if(pc==0)/*���ӽ�����*/
{
sleep(10);
exit(0);
}
else
{
do {/* ʹ����WNOHANG������waitpid����������ȴ� */
pr=waitpid(pc,NULL,WNOHANG);
if (pr==0)
{
printf("No child exit\n");
sleep(1);
}
}while (pr==0);
if (pr==pc)
printf("successfully get child %d\n",pr);
else
printf("wait child error\n");
}
return 0;
}