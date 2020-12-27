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
    struct input_event event;//事件源
    int ret = 0;

    if((fd = open("/dev/input/event1", O_RDONLY)) < 0) {
        perror("open error");
        exit(1);
    }

    //EVIOCGNAME 宏的作用是获得 IO 设备的名称
    if(ioctl(fd, EVIOCGNAME(sizeof(name)), name) < 0) {
        perror("evdev ioctl error\n");
        exit(1);
    }

    printf("The device says its name is %s\n", name);

    //读写打开的设备文件
    while(1) {
        ret = read(fd, &event, sizeof(event));
        if(ret < 0) {
            perror("read event error\n");
        }

        if(EV_KEY == event.type) {
            //如果事件是一个按键码
            printf("key code is %d\n", event.code);

            if(event.code == 16) {
                //按 q 退出此应用程序
                break;
            }
        }
    }

    close(fd);

    return 0;
}