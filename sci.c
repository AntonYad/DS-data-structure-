#include <syscall.h>

#include <unistd.h>

#include <stdio.h>

#include <sys/types.h>

int main(void) {

long sci1,sci2;

//通过syscall调用SYS_getpid

sci1 = syscall(SYS_getpid);

printf("syscall(SYS_getpid)=%ld\n",sci1);

// C函数库调用

sci2=getpid();

printf("getpid()=%ld\n",sci2);

//用execve执行shell命令

char *argv[]={"ps","aux",NULL,NULL};//传递给执行文件的参数数组，这里包含执行文件的参数

char *envp[]={0,NULL};//传递给执行文件新的环境变量数组

execve("/bin/ps",argv,envp);

return (0);

}
