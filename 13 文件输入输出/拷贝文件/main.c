#include"main.h"

int main(int argc, char* argv[]) {
	FILE* ifile, * ofile;
	char ch;
	if (argc != 2) {
		printf("Error: 请拖入需要拷贝的文件! 按任意键退出\n");
		getchar();
		exit(1);
	}
	if ((ifile = fopen(argv[1], "r")) == NULL) {
		printf("Error: 打开文件失败\n");
		getchar();
		exit(2);
	}

	strcat(argv[1], ".cp");
	ofile = fopen(argv[1], "w");
	printf("正在拷贝中...\n");
	while ((ch = getc(ifile)) != EOF) {
		putc(ch,ofile);
	}
	printf("拷贝完成,按任意键退出\n");
	getchar();
}