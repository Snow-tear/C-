#include"main.h"

int main(int argc, char* argv[]) {

	

	while (true)
	{
		time_t si = time(NULL);
		while (si==time(NULL))
		{
			continue;
		}
		printf("%ld\n", si);
	}

	

}