#include<stdio.h>

int 精简(int argc, char* argv[]) {
	char ch;	//读取文件时, 存储每个字符的地方
	FILE* fp;	//"文件指针"
	fp = fopen(argv[1], "r");
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
}