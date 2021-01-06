#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>

int main()
{
	struct input_event buf;
	int fd,x,y;
	fd = open("/dev/input/event0",O_RDWR);
	
	while(1)
	{
		read(fd,&buf,sizeof(buf));
		
		if(buf.type == EV_ABS && buf.code == ABS_X)
		{
			x = buf.value;
		}
		
		if(buf.type == EV_ABS && buf.code == ABS_Y)
		{
			y = buf.value;
		}
		
		printf("(%d , %d)\n",x,y);
	}
	
	return 0;
}