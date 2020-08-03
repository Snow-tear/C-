#include<stdio.h>
int ar[10] = { 9,5,4,7,3,5,1,4,9,7 };
void en(void);
int main(void) {
	for (int i = 0; i < 10; i++) { en(); };
}

void en(void) {
	static int* p1;
}