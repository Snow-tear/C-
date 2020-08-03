#include<stdio.h>
#include<time.h>
int 我也是外部变量=2333;
static unsigned int ranseed;

unsigned int rann(void) {
	static flag;
	if(flag==0){
		ranseed = (unsigned)time(0);
		flag++;
	}
	ranseed = ranseed * 1103515245+12345;
	printf("flag = %d\n", flag);
	return (unsigned int)(ranseed / 65536) % 32768;
	
}