#include"main.h"

int main(int argc, char* argv[]) {
	FILE* ifile, * ofile;
	char ch;
	if (argc != 2) {
		printf("Error: ��������Ҫ�������ļ�! ��������˳�\n");
		getchar();
		exit(1);
	}
	if ((ifile = fopen(argv[1], "r")) == NULL) {
		printf("Error: ���ļ�ʧ��\n");
		getchar();
		exit(2);
	}

	strcat(argv[1], ".cp");
	ofile = fopen(argv[1], "w");
	printf("���ڿ�����...\n");
	while ((ch = getc(ifile)) != EOF) {
		putc(ch,ofile);
	}
	printf("�������,��������˳�\n");
	getchar();
}