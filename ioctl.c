#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/input.h>

int main(int argc, const char *argv[])
{
    int fd = -1;
    char name[256] = "Unknown";
    struct input_event event;//�¼�Դ
    int ret = 0;

    if((fd = open("/dev/input/event1", O_RDONLY)) < 0) {
        perror("open error");
        exit(1);
    }

    //EVIOCGNAME ��������ǻ�� IO �豸������
    if(ioctl(fd, EVIOCGNAME(sizeof(name)), name) < 0) {
        perror("evdev ioctl error\n");
        exit(1);
    }

    printf("The device says its name is %s\n", name);

    //��д�򿪵��豸�ļ�
    while(1) {
        ret = read(fd, &event, sizeof(event));
        if(ret < 0) {
            perror("read event error\n");
        }

        if(EV_KEY == event.type) {
            //����¼���һ��������
            printf("key code is %d\n", event.code);

            if(event.code == 16) {
                //�� q �˳���Ӧ�ó���
                break;
            }
        }
    }

    close(fd);

    return 0;
}