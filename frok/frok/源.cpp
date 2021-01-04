#define _CRT_SECURE_NO_WARNINGS 1
#include<sys/types.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return  -1;
	}
	else if (pid == 0)
	{
		printf("The return value is %d  In child process!!  My PID is %d,  My PPID is %d\n", pid, getpid(), getppid());
	}
	else
	{
		printf("The return value is %d  In parent process!!  My PID is %d,  My PPID is %d\n", pid, getpid(), getppid());
	}
	return  0;