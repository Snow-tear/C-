#include <stdio.h>

int main(int argc, char* argv[]) {
	char ch;
	FILE* file;
	unsigned long int count = 0;
	if (argc != 2) {
		printf("Error: 请将文件拖入图标, 不要直接打开!");
		getchar();
		return 1;
	}
	if ((file=fopen(argv[1],"r+"))==NULL) {
		printf("Error: 打开文件失败!");
		getchar();
		return 2;
	}
	while ((ch = getc(file)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	printf("\n本文件共有%d个字符", count);
	getchar();
	return 0;
}