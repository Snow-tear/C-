#include<stdio.h>

int ����(int argc, char* argv[]) {
	char ch;	//��ȡ�ļ�ʱ, �洢ÿ���ַ��ĵط�
	FILE* fp;	//"�ļ�ָ��"
	fp = fopen(argv[1], "r");
	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
}