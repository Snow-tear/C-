#include "main.h"

int main(void) {
	FILE* storage;
	char ch;
	char pass[20];


	printf("����������:\n");
	scanf("%s", pass);
	while (getchar() != '\n')
	{
		continue;
	}
	if (strcmp(pass, TOKEN)) {
		printf("Error: �������,��������˳�\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("������ȷ\n");
	}

	if ((storage = fopen("storage.txt", "r")) == NULL) {
		printf("Error: �������,��������˳�\n");
		getchar();
		exit(EXIT_FAILURE);
	}   
	//���Դ򿪳���

	while ((ch=getc(storage))!=EOF)
	{
		putc(ch, stdout);
	}

	printf("\n�������������, CTRL+Z��������:\n");

	storage = fopen("storage.txt", "a");

	while ((ch = getc(stdin)) != EOF) {
		putc(ch, storage);
	}
}