#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct students
{
	char name[20];
	char month;
	char date;
};

int cmp(struct students* student1, struct students* student2);

int main(int argc, char* argv[]) {
	int student_number;
	struct students student[180];
	scanf("%d", &student_number);

	for (int i = 0; i < student_number; i++) {
		scanf("%s %d %d", student[i].name, &student[i].month, &student[i].date);
	}
	qsort(student, student_number, sizeof student[0], cmp);

	int nmonth = 0, ndate = 0, flag = 0, hlag=0;

	for (int i = 0; i < student_number; i++) {
		if (nmonth != student[i].month || ndate != student[i].date) {
			if (hlag)putchar('\n');
			hlag = 0;
		}
		else
		{
			if (hlag == 0) {

				printf("%d %d", student[i].month, student[i].date);
				i--;
			}
			printf(" %s", student[i].name);
			hlag = 1;
			flag++;
		}
		nmonth = student[i].month;
		ndate = student[i].date;
	}
	if (!flag) puts("None");
}

int cmp(struct students* student1, struct students* student2) {
	if (student1->month > student2->month)return 1;
	if (student1->month < student2->month) return -1;
	if (student1->date > student2->date) return 1;
	if (student1->date < student2->date) return -1;
	if (strlen(student1->name) > strlen(student2->name)) return 1;
	if (strlen(student1->name) < strlen(student2->name)) return -1;
	return strcmp(student1->name, student2->name);
}