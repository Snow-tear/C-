#include"main.h"
void goodbye(void);
inline void goodbye2(void);

int main(int argc, char* argv[]) {
	atexit(goodbye);
}

void goodbye(void) {
	printf("�������, �����˳�");
	goodbye2();
}

inline void goodbye2(void) {	//����һ��ע��
	getchar();
}