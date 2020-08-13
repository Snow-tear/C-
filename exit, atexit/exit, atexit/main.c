#include"main.h"
void goodbye(void);
inline void goodbye2(void);

int main(int argc, char* argv[]) {
	atexit(goodbye);
}

void goodbye(void) {
	printf("程序结束, 即将退出");
	goodbye2();
}

inline void goodbye2(void) {	//这是一行注释
	getchar();
}