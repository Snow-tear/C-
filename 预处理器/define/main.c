#include"main.h"
#if __STDC_VERSION__ < 201112L	
	#error NO C11
#endif

#define a "ab alksdjflk"	//可以用注释, 这里叫"类对象宏"
#define b(x) "aslkjdf"#x"asdfj"	//这叫"类函数宏"
#ifndef b
	#define b(x) "aslkjdf"#x"asdf"	//一般编译器不允许重定义宏, 除非一模一样. VS好像会覆盖的样子
#endif
#define c(x,y) #x #y	//尝试多参数
#define XNAME(n)	x ## n	//##运算符: 预处理器黏合剂
#define d(x)	x*x
//#define DEBUG

int main(int argc, char* argv[]) {
	printf("%s\n", a);
	printf("a\n");	//在引号里的宏不起作用
	printf("%s\n", b(0));	//类函数宏中,#运算符可以让参数变成带双引号的字符串. 此处即为0变成"0". 这叫"字符串化"(stringizing)
	printf("%s\n", c(3  9, 3));
	int XNAME(1) = 3;		//扩展到x1	若#define XNAME(n) xn, 则会扩展到xn
	printf("%d\n", XNAME(1));
	int num = d(4);

#ifdef DEBUG
	printf("Now in the debug mode\n");
#else
	printf("Release mode\n");
#endif // DEBUG
#line 14 "file??"
	printf("This is file %s\n", __FILE__);
	printf("The date is %s\n", __DATE__);
	printf("The time is %s\n", __TIME__);
	printf("Now at line %d\n", __LINE__);
	printf("Whether support C standard? %d\n",__STDC__);//这里VS不支持, 要用gcc或者clang
	printf("C standard version is %ld\n",__STDC_VERSION__);	
	printf("Local envionment? %d\n", __STDC_HOSTED__);
	printf("Now in the function %s\n", __func__);
}