#define _CRT_SECURE_NO_WARNINGS 1
#include<unistd.h>   
#include<signal.h>   
#include<sys/param.h>   
#include<sys/types.h>   
#include<sys/stat.h>   
void init_daemon(void)
{
	int pid, fdtablesize;
	int i;
	if (pid = fork())
		exit(0);
	else if (pid< 0)
		exit(1);
	setsid();
	if (pid = fork())
		exit(0);
	else if (pid< 0)
		exit(1);
	fdtablesize = getdtablesize();
	for (i = 0; i<fdtablesize; ++i)
		close(i);
	chdir("/tmp");
	umask(0);
	return;
}