#include"main.h"

int main(int argc, char* argv[]) {

	

	while (true)
	{
		time_t si = time(NULL);
		while ((time(NULL)-si<2))
		{
			continue;
		}
		printf("%ld\n", si);
	}

	

}