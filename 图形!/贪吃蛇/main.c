#include"main.h"

#define HEIGHT 15
#define LENGTH 20
#define INITLENGTH 3
#define TIME_INTERVAL 400	//刷新时间间隔

int bonus = 0;
struct dots
{
	char display;
	int TTL;

};
struct dots mapdot[HEIGHT + 2][LENGTH + 2];
enum velocity { left, right, up, down };
struct sprite {
	int y_pos;
	int x_pos;
	int velocity;
};
struct sprite snake = { .y_pos = 3,.x_pos = 3,.velocity = right };
struct sprite fruit = { .y_pos = 2,.x_pos = 2 };

void initmap(void);
void move(void);
void getfruit(void);
void snakeCover(void);
void dead(void);
void snakeFade(void);
void refresh(void);





int main(int argc, char* argv[]) {


	bool unlock = true;
	initmap();		//初始化地图为四周边界,中间空心


	while (true)
	{
		int t = GetTickCount();;
		while (GetTickCount() - t <= TIME_INTERVAL)		// 一秒钟的输入窗口期, 只能输入一个键
		{
			if (unlock)move();		//移动snake
			unlock = false;
		}
		getfruit();					//将fruit显示在地图上.如果吃到水果,bonus++,并随机生成新的.
		snakeFade();				//TTL减少,弱TTL归零则显示空白
		dead();						//判断是否gameover
		snakeCover();				//将snake的位置显示在地图上, 并设置该点的TTL
		refresh();
		unlock = true;
	}
}


void initmap(void) {
	for (int y = 0; y < HEIGHT + 1; y++) {
		for (int x = 0; x < LENGTH + 1; x++) {
			mapdot[y][x].display = '*';
			mapdot[y][x].TTL = -1;
		}
	}
	for (int y = 1; y <= HEIGHT; y++) {
		for (int x = 1; x <= LENGTH; x++) {
			mapdot[y][x].display = ' ';
			mapdot[y][x].TTL = 0;
		}
	}
}

void move(void) {
	int ch;
	if (kbhit())ch = getch(); else ch = ' ';
	switch (ch)
	{
	case('w'):
		if (snake.velocity != down)snake.velocity = up;
		break;
	case('s'):
		if (snake.velocity != up)snake.velocity = down;
		break;
	case('a'):
		if (snake.velocity != right)snake.velocity = left;
		break;
	case('d'):
		if (snake.velocity != left)snake.velocity = right;
		break;
	default:
		break;
	}

	switch (snake.velocity)
	{
	case(up):
		snake.y_pos--;
		break;
	case(down):
		snake.y_pos++;
		break;
	case(left):
		snake.x_pos--;
		break;
	case(right):
		snake.x_pos++;
		break;
	default:
		break;
	}
}

void getfruit(void) {
	if (snake.y_pos == fruit.y_pos && snake.x_pos == fruit.x_pos) {
		srand(time(NULL));
		fruit.y_pos = rand() % HEIGHT + 1;
		fruit.x_pos = rand() % LENGTH + 1;
		bonus++;
	}
	mapdot[fruit.y_pos][fruit.x_pos].display = '$';
	mapdot[fruit.y_pos][fruit.x_pos].TTL = -1;
}

void snakeCover(void) {
	mapdot[snake.y_pos][snake.x_pos].display = '*';
	mapdot[snake.y_pos][snake.x_pos].TTL = INITLENGTH + bonus - 1;
}

void dead(void) {
	if ((mapdot[snake.y_pos][snake.x_pos].display == '*') || snake.y_pos > HEIGHT|| snake.x_pos > LENGTH) {
		printf("你死了,共吃到%d个果子.\n按任意键退出.\n",bonus);
		getchar();
		exit(1);
	}
}

void snakeFade(void) {
	static int bonus_before = 0;	//用来判断bonus有木有改变
	for (int y = 1; y <= HEIGHT; y++) {
		for (int x = 1; x <= LENGTH; x++) {
			if (mapdot[y][x].TTL) {
				if (bonus_before != bonus)bonus_before = bonus;
				else mapdot[y][x].TTL--;
			}
			else
			{
				mapdot[y][x].display = ' ';
			}
		}
	}
}

void refresh(void) {
	system("cls");
	for (int i = 0; i < LENGTH + 1; i++) printf("--");
	putchar('\n');
	for (int y = 1; y <= HEIGHT; y++) {
		putchar('|');
		for (int x = 1; x <= LENGTH; x++) {
			printf("%c ", mapdot[y][x].display);
		}
		putchar('|');
		putchar('\n');
	}
	for (int i = 0; i < LENGTH + 1; i++) printf("--");
	putchar('\n');
}