#include"main.h"
#if __STDC_VERSION__ < 201112L	
	#error NO C11
#endif

#define a "ab alksdjflk"	//������ע��, �����"������"
#define b(x) "aslkjdf"#x"asdfj"	//���"�ຯ����"
#ifndef b
	#define b(x) "aslkjdf"#x"asdf"	//һ��������������ض����, ����һģһ��. VS����Ḳ�ǵ�����
#endif
#define c(x,y) #x #y	//���Զ����
#define XNAME(n)	x ## n	//##�����: Ԥ�������ϼ�
#define d(x)	x*x
//#define DEBUG

int main(int argc, char* argv[]) {
	printf("%s\n", a);
	printf("a\n");	//��������ĺ겻������
	printf("%s\n", b(0));	//�ຯ������,#����������ò�����ɴ�˫���ŵ��ַ���. �˴���Ϊ0���"0". ���"�ַ�����"(stringizing)
	printf("%s\n", c(3  9, 3));
	int XNAME(1) = 3;		//��չ��x1	��#define XNAME(n) xn, �����չ��xn
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
	printf("Whether support C standard? %d\n",__STDC__);//����VS��֧��, Ҫ��gcc����clang
	printf("C standard version is %ld\n",__STDC_VERSION__);	
	printf("Local envionment? %d\n", __STDC_HOSTED__);
	printf("Now in the function %s\n", __func__);
}