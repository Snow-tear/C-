#include<stdio.h>
#pragma warning(disable:4996)
void reverse(double ar[]);

int main(void) {
	double ar[7];
	printf("Please input 7 double numbers and I will reverse them.\n");
	for (int i = 0; i < 7; i++) {
		scanf("%lf", &ar[i]);
	}
	reverse(ar);
	puts("Reverse it!");
	for (int i = 0; i < 7; i++) {
		printf("%.3f\t", ar[i]);
	}
	puts("\n");
}

void reverse(double* ar) {
	double tmp[7];
	for (int i = 0; i < 7; i++) {
		tmp[i] = ar[i];
	}
	for (int i = 0; i < 7; i++) {
		ar[i] = tmp[6 - i];
	}
}
