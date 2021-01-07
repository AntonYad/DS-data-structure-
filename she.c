#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/input.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct DOP
{
    int x;
    int y;
    int stuat;
    struct DOP *next;
}*DOP,dopp;


int all_num = 1;
int stuat = 1;

int set_color(int x, int y,int w, int h,int color)
{
    int fd = open("/dev/fb0",O_RDWR);
    if(fd == -1)
    {
        perror("open fd error!!");
        return -1;
    }
    int *lcd = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    int i=0;
    int j=0;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++){
            *(lcd+(j+x)+(i+y)*800) = color;
        }
    }


    munmap(lcd, 800*480*4);
    close(fd);
    return 0;
}

int get_xy(int *x,int *y)
{
    	//打开文件 
	int fd = open("/dev/input/event0",O_RDWR);
	if(fd == -1)
	{
		perror("/dev/input/event0");
		return -1;
	}
	struct input_event ie;
	
	while(1)
	{
		read(fd, &ie, sizeof(ie));	//读取触摸数据 屏幕阻塞作用
	
		//printf("type=%d code=%d value=%d\n",ie.type, ie.code, ie.value);
		if(ie.type==3 && ie.code == 0)//x轴的坐标就能获取了
		{
			*x=ie.value;
		}
		else if(ie.type==3 && ie.code == 1)//y轴的坐标就能获取了
		{
			*y = ie.value;
		}
		else if(ie.type==1 && ie.code == 330 && ie.value== 0)//松开的时候打印出坐标
		{
			break;
		}
	}
	
	close(fd);
    return 0;
}


DOP create_head()//头结点 和背景节点
{
    DOP head = malloc(sizeof(dopp));
	if(!head)
	{
		printf("cteate null\n");
		exit(-1);
	}
	head->x=-1;
	head->y=-1;
	head->stuat=-1;
    return head;
}
//计算节点数 不包括头结点
int count_port(DOP head)
{
	int num=0;
	int i=0;
	DOP p=head->next;
	for(i=0;head->next!=NULL;i++);
	
	return num; 
}

//显示蛇身
void show_color(DOP head)
{
	if(!head)
	{
		printf("show_color error\n");
		exit(-1);
	}
	DOP p=head->next;
	while(p->next!=NULL)
	{
		
		set_color(p->x,p->y,8,8,0xff);
		p = p->next;
	}
	set_color(p->x,p->y,8,8,0xffffff);//显示最后一个节点的颜色 背景色
}

//添加节点
int add_port(DOP head, int x, int y, int stuat)
{
	if(!head)
	{
		printf("add_port error\n");
		exit(-1);
	}
	DOP add_p=malloc(sizeof(dopp));
	if(!add_p)
	{
		printf("add_port malloc error\n");
		exit(-1);
	}
	add_p->x=x;
	add_p->y=y;
	add_p->stuat=stuat;
	if(count_port(head) == 0)
	{
		head->next=add_p;
		//在创建尾巴
		add_p->next=malloc(sizeof(dopp));
		if(!add_p->next)
		{
			printf("add_port add_p->next error\n");
			exit(-1);
		}
		add_p->next->x=x-8;
		add_p->next->y=y;
		add_p->stuat=stuat;
	}
	else//头插法
	{
		DOP p=head->next;
		head->next=add_p;
		add_p->next=p;
	}
	return 0;
}

void* pthread_func(void* arg)
{
    while(1)
    {
        sleep(1);
        printf("pthread_func\n");
    }

}

int move_port(DOP head,int stuat)
{
	int num=0;
	if(!head)
	{
		printf("move_port error\n");
		exit(-1);
	}
	DOP p = head->next;
	for(;p!=NULL;p = p->next)
	{
		if(stuat==1)//右
		{
			p->x+=8;
			if(p->x>=400)
				num=-1;
		}
		else if(stuat==2)//下
		{
			p->y+=8;
			if(p->y>=400)
				num=-1;
		}
		else if(stuat==3)//左
		{
			p->y-=8;
			if(p->x<=0)
				num=-1;
		}
		else if(stuat==4)//上
		{
			p->y-=8;
			if(p->x<=0)
				num=-1;
		}
		
	}
	return num;
}


int main(int argc, char **argv)
{
	DOP head=create_head();

	add_port(head,2*8, 0,1);

	set_color(0,0,800,480,0xffffff);
	printf("hello\n");
	pthread_t thread;
	pthread_create(&thread,NULL,pthread_func,NULL);
	int i=0;
	int j=0;


	while(1)
	{
		show_color(head);//显示
		if(move_port(head,1)==-1)
		{
			printf("game over\n");
			break;
		}
		sleep(1);
	}
	
	//移动
	all_num++;

	pthread_join(thread,NULL);
	return 0;
}
