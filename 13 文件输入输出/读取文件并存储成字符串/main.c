#include"main.h"

int main(int argc, char* argv[]) {
	FILE* fp;
	register unsigned long int count = 1;
	register char ch;
	if (argc != 2) {
		puts("ERROR: 请将文件拖入");
		getchar();
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL) {
		puts("ERROR: 未找到指定文件");
		getchar();
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		count++;
	}
	char* string = calloc(count, sizeof(char));
	fseek(fp, 0L, SEEK_SET);
	fgets(string, count, fp);
	string[count + 1] = '\0';
	printf("%s", string);
	getchar();
	exit(EXIT_FAILURE);
}