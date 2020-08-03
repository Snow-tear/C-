#include <stdio.h>

int main(void) {
	const int a = 233;
	int* b = &a;
	printf("a = %d\n", a);
	*b = 123;
	printf("Now *b = %d, a = %d\n\n", *b, a);

	int const x[2] = { 1,2 };
	printf("x[1] = %d\n", x[1]);
	const int* px = x;
	printf("*(px+1) = %d\n", *(b + (px - b) + 1));
	*(b+(px-b)+1) = 3;
	printf("Now x[1] = %d, *(px+1) = %d\n\n",x[1], *(b + (px - b) + 1));

	//验证P301"只能把非const数据的地址赋给普通指针"
	const double locked[4] = { 0.1,0.2,0.3,0.4 };
	printf("locked[0] = %.1f\n", locked[0]);
	double* pnc = locked;
	*pnc = 1.0;
	printf("locked[0] = %.1f\n", locked[0]);

	int* p=&a;
	for (int c = 0; 1; c++)*(p + c) = 0;
}