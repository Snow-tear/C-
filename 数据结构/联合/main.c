#include"main.h"

int main(int argc, char* argv[]) {
	union a {
		int score;
		float fscore;
		double dscore;
	};

	union a s = { 9 };
	s.fscore = 6.4;
	printf("s\t%lf\n", s.dscore);
}