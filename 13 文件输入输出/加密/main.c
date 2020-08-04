#include "main.h"

int main(void) {
	FILE* storage;
	char ch;
	char pass[20];


	printf("请输入密码:\n");
	scanf("%s", pass);
	while (getchar() != '\n')
	{
		continue;
	}
	if (strcmp(pass, TOKEN)) {
		printf("Error: 密码错误,按任意键退出\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("密码正确\n");
	}

	if ((storage = fopen("storage.txt", "r")) == NULL) {
		printf("Error: 程序错误,按任意键退出\n");
		getchar();
		exit(EXIT_FAILURE);
	}   
	//尝试打开程序

	while ((ch=getc(storage))!=EOF)
	{
		putc(ch, stdout);
	}

	printf("\n请输入添加内容, CTRL+Z结束输入:\n");

	storage = fopen("storage.txt", "a");

	while ((ch = getc(stdin)) != EOF) {
		putc(ch, storage);
	}
}