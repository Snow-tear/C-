#include"main.h"

struct students
{
	char name[20];
	float score;
};

int main(int argc, char* argv[]) {
	char *ptr;
	ptr = (char[]){ "abc" };
	puts(ptr);

	struct students student0;
	student0 = (struct students){ "Jerry",95.0 };
	printf("%s's score is %.1f", student0.name, student0.score);


}