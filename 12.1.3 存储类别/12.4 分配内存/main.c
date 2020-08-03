#include<stdio.h>
#include<stdlib.h>

int ar[10] = { 9,5,4,7,3,5,1,4,9,7 };
void en(void);
int main(void) {
	char* bigMem[8];
	for (int i = 0; i < 8; i++) {
		bigMem[i] = malloc(1024*1024*1024 * sizeof(char));
		printf("i: %p\n", bigMem[i]);
		if (bigMem[i] == NULL) {
			puts("Oh I don't have enough memory!");
			exit(EXIT_FAILURE);
		}
	}
	getchar();
}

void en(void) {
	int sz_auto[19];
	static int sz_static[20];
	
}