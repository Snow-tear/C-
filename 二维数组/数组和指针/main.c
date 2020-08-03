#include <stdio.h>
int m ;
m = 3;

int main(void) {
	float sz[3][2] = { [1] = {1.0 , 1.1} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("sz[%d][%d] = %.1f\t",i ,j,*(*(sz+i)+j));
		}
		printf("\n");
		m = 4;
	}
}