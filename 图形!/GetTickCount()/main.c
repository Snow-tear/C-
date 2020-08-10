#include"main.h"

int main(int argc, char* argv[]) {

	int t;

	while (1) {
		t = GetTickCount();
		while (GetTickCount()-t <=500 )continue;
		printf("%d\n", GetTickCount());
	}


}