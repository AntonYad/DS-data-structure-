#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DELAY_TIME		3
int main(void)
{
	pid_t result;
	int sem_id;
	sem_id = semget(ftok(".", 'a'),  1, 0666|IPC_CREAT); 
	init_sem(sem_id, 0);	
	result = fork();
	if(result ==  -1) {	perror("Fork\n");	 }
	else if (result == 0)  /*返回值为0代表子进程*/
	{   printf("Child process will wait for some seconds...\n");
	    sleep(DELAY_TIME);
	    printf("The returned value is %d in the child process(PID=%d)\n", result, getpid());
	   sem_v(sem_id);
	}
	else /*返回值大于0代表父进程*/
	{
	  sem_p(sem_id);
printf("The returned value is %d in the father process(PID=%d)\n", result, getpid());
	  sem_v(sem_id);
	  del_sem(sem_id);
	}	
	exit(0);
}
