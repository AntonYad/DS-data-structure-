#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void)
{
pid_t cpid1,cpid2,pid;
cpid1=fork();
if(cpid1==-1)
{
printf("fork error\n");
exit(1);
}
else if(cpid1==0)
{
printf("In child1:execute 'ps -l'\n");
if(execlp("ps","ps","-l",NULL)<0)
{
printf("child1 execlp error\n");
}
}
else
{
cpid2=fork();
if(cpid2==-1)
{
printf("fork2 error!\n");
exit(1);
}
else if(cpid2==0)
{
printf("In child2:sleep for 3s and exit\n");
sleep(5);
exit(0);
}
printf("In father:\n");
pid=waitpid(cpid1,NULL,0);/*zu sai deng dai*/
if(pid=cpid1)
{
printf("Get child1 exit code\n");
}
else
{
printf("Error\n");
}
do
{
pid=waitpid(cpid2,NULL,WNOHANG);
if(pid==0)
{
printf("The child2 process has not exited!\n");
sleep(1);
}
}while(pid==0);
if(pid==cpid2)
{
printf("Get child2 exit code\n");
}
else
{
printf("Error\n");
}
}
exit(0);
}
