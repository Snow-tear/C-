#include"main.h"
int bigger(int a, int b);
int smaller(int a, int b);
void compare(int method(int, int));

int main(int argc, char* argv[]) {
	compare(bigger);

	printf("bigger:\t\t%p\n&bigger:\t%p\n*bigger:\t%p\n*********bigger:%p\n",
		bigger, &bigger, *bigger, *********bigger);
}

int bigger(int a, int b)
{
	return (a > b) ? a : b;
}

int smaller(int a, int b)
{
	return (a < b) ? a : b;
}

void compare(int method(int, int))
{
	printf("method:\t\t%p\n&method:\t%p\n*method:\t%p\n*********method:%p\n", method,&method,*method,*********method);
}
