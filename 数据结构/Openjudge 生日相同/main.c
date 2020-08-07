#include"main.h"

int main(int argc, char* argv[]) {
	struct people
	{
		char name[20];
		int month;
		int date;
	};

	struct people student[180];

	int number;

	scanf("%d", &number);

	for (int i = 0; i < number; i++) {
		scanf("%s %d %d", student[i].name, &student[i].month, &student[i].date);
	}

	

}