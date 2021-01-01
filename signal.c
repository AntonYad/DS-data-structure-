#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void my_fun(int signo)
{
if(sign_no==SIGINT)
{
printf("I have got SIGINT\n");
}
else if(sign_no==SIGQUIT)
{
printf("I have got SIGQUIT\n");
}
}
int main()
{
printf("Waiting for signal SIGINT or SIGQUIT...\n");
signal(SIGINT,my_fun);
signal(SIGQUIT,my_fun);
pause();
exit(0);
}