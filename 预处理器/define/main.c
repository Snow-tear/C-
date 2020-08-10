#include"main.h"

#define a "ab alksdjflk"	//可以用注释, 这里叫"类对象宏"
#define b(x) "aslkjdf"#x"asdfj"	//这叫"类函数宏"
#define b(x) "aslkjdf"#x"asdf"	//一般编译器不允许重定义宏, 除非一模一样. VS好像会覆盖的样子

int main(int argc, char* argv[]) {
	printf("%s\n", a);
	printf("a\n");	//在引号里的宏不起作用
	printf("%s\n",b(0));	//类函数宏中,#运算符可以让参数变成带双引号的字符串. 此处即为0变成"0". 这叫"字符串化"(stringizing)
}