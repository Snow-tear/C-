#include <stdio.h>
void fun1(int*);
void fun2(int[]);

int main(void) {
	int sz[] = { 0,1,2,3,4,5,6}; //¹²Æß¸öÖµ
	printf("The size of array sz is %zd\n", sizeof sz);
	fun1(&sz[0]);
	fun2(&sz[0]);
}

void fun1(int* a) {
	printf("%zd\n", sizeof a);
}

void fun2(int a[]) {
	printf("%zd\n", sizeof a);
}