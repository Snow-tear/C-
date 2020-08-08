#include"main.h"
int bigger(int a, int b);
int smaller(int a, int b);
void compare(int method(int, int), int x, int y);

int main(int argc, char* argv[]) {
	compare(bigger, 15, 7);

	int larger(int a, int b);
	larger = bigger;


}

int bigger(int a, int b)
{
	return (a > b) ? a : b;
}

int smaller(int a, int b)
{
	return (a<b)?a:b;
}

void compare(int method(int, int), int x, int y)
{
	printf("%d", method(x, y));
}
