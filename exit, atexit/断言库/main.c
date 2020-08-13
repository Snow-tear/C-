#include"main.h"
#define SQUARE(x)  ((x)*(x))

//_Static_assert(1 + 1 != 2, "1 + 1 = 2!");



int main(int argc, char* argv[]) {
	int z = rand();
	//assert(SQUARE(z) < 0);
	(void)0;

	printf("%s\n", _Generic(" ",int:"zhengshu",float:"xiaoshu",double:"liaxiaoshu",default:"shawanyi"));
}
