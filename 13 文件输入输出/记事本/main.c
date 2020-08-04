#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	FILE* note;
	char ch;
	note = fopen("note.txt", "w+");
	while ((ch = getchar()) != EOF) {
		putc(ch, note);
	}
}