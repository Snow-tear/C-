#include <stdio.h>
#pragma warning(disable:4996)；


int main() {

	char ch[1000000];
	int count = 0;
	while ((ch[count] = getchar()) != EOF) {
		count++;
		if (count > 999999) break;
	}
	printf("文件结束了\n");

	for (int i = 0; i < count; i++) putchar(ch[i]);
	getchar();
}


//int strings(void) {
	
	char __json[1000000];
	scanf("%s", __json);
	printf("%s", __json);
}