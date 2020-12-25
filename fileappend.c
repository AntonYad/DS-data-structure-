#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "io.h"

int main(int argc, char *argv[])
{
    if(argc < 3) {
        fprintf(stderr, "usage: %s content destfile\n", argv[0]);
        exit(1);
    }

    int fd;
    int ret;
    size_t size;

    fd = open(argv[2], O_WRONLY);

    //����׷�ӵ��ļ�״̬��־
    set_fl(fd, O_APPEND);

    //���׷���ļ�״̬��־
    //clr_fl(fd, O_APPEND);
    /*
    fd = open(argv[2], O_WRONLY | O_APPEND);
    if(fd < 0){
        perror("open error");
        exit(1);
    }

    */
/*
    //��λ���ļ�β��
    ret = lseek(fd, 0L, SEEK_END);
    if(ret == -1) {
        perror("lseek error");
        close(fd);
        exit(1);
    }
*/    
    sleep(10); //˯�� 10s

    //���ļ���׷������
    size = strlen(argv[1]) * sizeof(char);
    if(write(fd, argv[1], size) != size) {
        perror("write error");
        close(fd);
        exit(1);
    }

    return 0;
}