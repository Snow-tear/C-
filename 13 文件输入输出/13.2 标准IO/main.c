#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int 高级(int argc, char* argv[]) {
	int ch;	//读取文件时, 存储每个字节的地方
	FILE* fp;	//"文件指针"
	unsigned long int count=0;
	if (argc != 2) {
		puts("请输入文件名");
		getchar();
		return 1;
	}
	if ((fp = fopen(argv[1], "r"))==NULL) {
		printf("找不到文件%s\n", argv[1]);
		getchar();
		return 2;
	}
	while ((ch=getc(fp))!=EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("文件%s共有%lu字符", argv[1], count);
	getchar();
	return 0;
}