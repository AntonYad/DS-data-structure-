#define _CRT_SECURE_NO_WARNINGS 1
#include<curses.h>//��Ļ���洦���Լ�I/O����
#include<stdlib.h>
#include<unistd>//����linux/unixϵͳ�ĵ��á�
#include<pthread.h>


#define UP     1//�����ж�
#define DOWN  -1
#define LEFT   2
#define RIGHT -2

struct snake//����
{
	int hang;
	int lie;
	struct snake *next;
};

struct snake *head = NULL;//�ߵ�ͷβ
struct snake *tall = NULL;

int key;
int dir;


struct snake food;

void initfood()//���ˢ�µ�
{
	int x = rand() % 19;//ȡ19�������
	int y = rand() % 19;

	food.hang = x;
	food.lie = y;
}


void initncurse()//��ʼ��
{
	initscr();//�趨��ֵcurses.h�����棩
	keypad(stdscr, 1);
	noecho();//�ǻ���ģʽ�°���ͨ������������Ļ�Ĳ������������������ַ�����
}

int hassnakenode(int i, int j)
{
	struct snake *p;
	p = head;

	while (p != NULL){
		if (p->hang == i && p->lie == j){
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int hasfood(int i, int j)//���food����
{
	if (food.hang == i && food.lie == j){
		return 1;
	}
	return 0;

}
void gamepic()//��Ϸ����ģ��
{
	int hang;
	int lie;

	move(0, 0);

	for (hang = 0; hang<20; hang++){

		if (hang == 0){

			for (lie = 0; lie<20; lie++){

				printw("--");
			}

			printw("\n");
		}
		if (hang >= 0 || hang <= 19){

			for (lie = 0; lie <= 20; lie++){

				if (lie == 0 || lie == 20){
					printw("|");
				}
				else if (hassnakenode(hang, lie)){
					printw("[]");
				}
				else if (hasfood(hang, lie)){
					printw("##");
				}
				else{
					printw("  ");
				}
			}
			printw("\n");
		}


		if (hang == 19){
			for (lie = 0; lie<20; lie++){
				printw("--");
			}

			printw("\n");
			printw("By PYZ,food.hang=%d,food.lie=%d\n", food.hang, food.lie);
		}

	}
}


void addnode()//�ɹ��Ե� ��ӳ���
{
	struct snake *new = (struct snake *)malloc(sizeof(struct snake));//�����ռ����malloc��stdlib��
	new->next = NULL;

	switch (dir){

	case UP:
		new->hang = tall->hang - 1;
		new->lie = tall->lie;
		break;
	case DOWN:
		new->hang = tall->hang + 1;
		new->lie = tall->lie;
		break;
	case LEFT:
		new->hang = tall->hang;
		new->lie = tall->lie - 1;
		break;
	case RIGHT:
		new->hang = tall->hang;
		new->lie = tall->lie + 1;
		break;
	}
	tall->next = new;
	tall = new;
}

void initsnake()
{
	struct snake *p;
	dir = RIGHT;
	while (head != NULL){
		p = head;
		head = head->next;
		free(p);
	}
	initfood();

	head = (struct snake *)malloc(sizeof(struct snake));
	head->hang = 1;
	head->lie = 1;
	head->next = NULL;

	tall = head;


	addnode();
	addnode();
	addnode();
	addnode();

}

void delenode()
{
	struct snake *p;
	p = head;
	head = head->next;

	free(p);
}

int ifsnakedie()
{
	struct snake *p;
	p = head;
	if (tall->hang< 0 || tall->lie == 0 || tall->hang == 20 || tall->lie == 20){
		return 1;
	}

	while (p->next != NULL){
		if (p->hang == tall->hang && p->lie == tall->lie){
			return 1;
		}
		p = p->next;
	}
	return 0;

}


void movesnake()
{
	addnode();
	if (hasfood(tall->hang, tall->lie)){
		initfood();
	}
	else {
		delenode();
	}
	if (ifsnakedie()){
		initsnake();
	}


}

void *refreshjiemian()
{
	while (1){

		movesnake();
		gamepic();
		refresh();
		usleep(100000);

	}
}

void turn(int direction)
{
	if (abs(dir) != abs(direction)){
		dir = direction;
	}
}
void *changedir()
{
	while (1){
		key = getch();
		switch (key){
		case KEY_DOWN:
			turn(DOWN);
			break;
		case KEY_UP:
			turn(UP);
			break;
		case KEY_LEFT:
			turn(LEFT);
			break;
		case KEY_RIGHT:
			turn(RIGHT);
			break;

		}
	}

}


int main()
{
	pthread_t t1;
	pthread_t t2;

	initncurse();
	initsnake();
	gamepic();

	pthread_create(&t1, NULL, refreshjiemian, NULL);
	pthread_create(&t2, NULL, changedir, NULL);

	while (1);
	getch();
	endwin();//�ָ�ԭ����״̬
	return 0;
}

