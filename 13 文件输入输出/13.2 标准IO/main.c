#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int �߼�(int argc, char* argv[]) {
	int ch;	//��ȡ�ļ�ʱ, �洢ÿ���ֽڵĵط�
	FILE* fp;	//"�ļ�ָ��"
	unsigned long int count=0;
	if (argc != 2) {
		puts("�������ļ���");
		getchar();
		return 1;
	}
	if ((fp = fopen(argv[1], "r"))==NULL) {
		printf("�Ҳ����ļ�%s\n", argv[1]);
		getchar();
		return 2;
	}
	while ((ch=getc(fp))!=EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("�ļ�%s����%lu�ַ�", argv[1], count);
	getchar();
	return 0;
}