#include<stdio.h>
#include<stdlib.h>
extern unsigned int rann(void);


int 外部变量;	//静态外部链接存储类别
extern int 我也是外部变量;	//extern用来指出此变量定义在别的翻译单元中,见extern.c
static int 内部链接的静态变量;	//静态内部链接存储类别

int main() {
	int 自动变量;	//自动存储类别
	auto int 我也是自动变量;	//auto用来强调自动变量存储类别
	register int 寄存器变量;	//寄存器存储类别
	static int 局部静态变量;	//静态无链接存储类别
	srand(78);
	for(int i=0;i<9;i++)printf("%d: %d\n",i, rand());
}

