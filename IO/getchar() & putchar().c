#include <stdio.h>
#include <conio.h>

void __getchar(void);	//����&&����
void __getche(void);	//������&&����
void __getch(void);		//������&&������

int main(void) {

	
	//__getchar();
	//__getche();
	//__getch();
	char ch;

	while ((ch = getchar()) != EOF)
	{
		printf("��û����β\n");
	}
	printf("�ҽ�����");
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