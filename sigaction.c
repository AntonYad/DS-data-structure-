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
struct sigaction action;
sigaction(SIGINT,0,&action);
action.sa_handler=my_fun;
sigaction(SIGINT,&action,0);
sigaction(SIGQUIT,0,&action);
action.sa_handler=my_fun;
sigaction(SIGQUIT,&action,0);
printf("Waiting for signal SIGINT or SIGQUIT...\n");
pause();
exit(0);
}