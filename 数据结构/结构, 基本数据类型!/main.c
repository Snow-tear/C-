#include"main.h"




int main(int argc, char* argv[]) {
	

	struct phone mix2s = {
		"polaris",
		5.99,
		3499
	};

	printf("mix2s has its value of %d\n", mix2s.value);
	struct phone mix2 = mix2s;
	printf("mix2 has its size of %.2f\n", mix2.size);
	changeMix2name(&mix2);
	printf("mix2 has its name of %s\n", mix2.name);
	printMix2name(mix2);

}

void changeMix2name(struct phone* mix2p)
{
	strcpy(mix2p->name, "chiron");
}

void printMix2name(struct phone mix2f)
{
	printf("mix2's value: %d\n", mix2f.value);
}