#include"main.h"

int main(int argc, char* argv[]) {
	char a = 0b10011011;
	char b = 0b11001001;
	printf("a\t%x\n~a\t%x\na&b\t%x\na|b\t%x\na^b\t%x\na<<2\t%x\na>>2\t%x\n",
		a, ~a, a & b, a | b, a ^ b, a << 2, a >> 2);

	struct bitfields
	{
		unsigned int switch0 : 1;
		unsigned int switch1 : 1;
		unsigned int switch2 : 1;
		unsigned int toobig : 32;
	}bitfield0;

	bitfield0.switch0 = 0b0;
	bitfield0.switch1 = 0b1;

	printf("%d %d\n", bitfield0.switch0, bitfield0.switch1);

	bitfield0.switch0 = 0b111111;	//如果赋值超过字段大小,会截取最后一位

	printf("%d %d", bitfield0.switch0, bitfield0.switch1);
}