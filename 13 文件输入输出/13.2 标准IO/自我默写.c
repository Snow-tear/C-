#include <stdio.h>

int main(int argc, char* argv[]) {
	char ch;
	FILE* file;
	unsigned long int count = 0;
	if (argc != 2) {
		printf("Error: �뽫�ļ�����ͼ��, ��Ҫֱ�Ӵ�!");
		getchar();
		return 1;
	}
	if ((file=fopen(argv[1],"r+"))==NULL) {
		printf("Error: ���ļ�ʧ��!");
		getchar();
		return 2;
	}
	while ((ch = getc(file)) != EOF) {
		putc(ch, stdout);
		count++;
	}
	printf("\n���ļ�����%d���ַ�", count);
	getchar();
	return 0;
}