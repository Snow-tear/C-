#include <stdio.h>
#include <conio.h>

void __getchar(void);	//缓冲&&回显
void __getche(void);	//不缓冲&&回显
void __getch(void);		//不缓冲&&不回显

int main(void) {

	
	//__getchar();
	//__getche();
	//__getch();
	char ch;

	while ((ch = getchar()) != EOF)
	{
		printf("还没到结尾\n");
	}
	printf("我结束了");
}

void __getchar(void) {
	char ch;
	while ((ch = getchar()) != '|') putchar(ch);
}

void __getche(void) {
	char ch;
	while ((ch = getche()) != '|') putchar(ch);
}

void __getch(void) {
	char ch;
	while ((ch = getch()) != '|') putchar(ch);
}