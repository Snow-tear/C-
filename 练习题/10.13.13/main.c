#include<stdio.h>
#pragma warning(disable:4996)
void average(double data[3][5]);
void max(double data[3][5]);

int main(void) {
	double data[3][5];
	printf("Please input 3*5 double numbers:\n");
	for (int i = 0; i < 3; i++){	
		for (int j = 0; j < 5; j++) {
			scanf("%lf", &data[i][j]);
		}
	}
	average(data);
	max(data);
}

void average(double data[3][5])
{
	double sum, sigma = 0;
	for (int i = 0; i < 3; i++,sum=0) {
		sum = 0;
		for (int j = 0; j < 5; j++) {
			sum += data[i][j];
			//printf("sum = %d\n", sum);
		}
		printf("average line %d = %.3f\n", i + 1, sum / 5);
		sigma += sum;
	}
	printf("The total average is %.3f\n", sigma / 15);
}

void max(double data[3][5]) {
	double max = data[0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			max = (max < data[i][j]) ? data[i][j] : max;
		}
	}
	printf("The max number is %.3f\n", max);
}