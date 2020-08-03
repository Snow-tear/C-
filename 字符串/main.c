#include<stdio.h>

int main(void) {
	char ar[] = "I am a string";
	char* pt = "I am a string";
	printf("The value of \"I am a string\" is %p.\n", "I am a string");
	printf("ar: %p	pt: %p\n", ar, pt);
	ar[7] = 'b';
	ar[8]  = '\0';
	puts("Now I changed the value of \"I am a string\", It's now:");
	printf("%s\n", ar);
	gets(ar);
	printf("%s\n", ar);


}