#include"main.h"

#define a "ab alksdjflk"	//������ע��, �����"������"
#define b(x) "aslkjdf"#x"asdfj"	//���"�ຯ����"
#define b(x) "aslkjdf"#x"asdf"	//һ��������������ض����, ����һģһ��. VS����Ḳ�ǵ�����
#define c(x,y) #x #y	//���Զ����
#define XNAME(n)	x ## n	//##�����: Ԥ�������ϼ�
#define d(x)	x*x

int main(int argc, char* argv[]) {
	printf("%s\n", a);
	printf("a\n");	//��������ĺ겻������
	printf("%s\n", b(0));	//�ຯ������,#����������ò�����ɴ�˫���ŵ��ַ���. �˴���Ϊ0���"0". ���"�ַ�����"(stringizing)
	printf("%s\n", c(3  9, 3));
	int XNAME(1) = 3;		//��չ��x1	��#define XNAME(n) xn, �����չ��xn
	printf("%d\n", XNAME(1));
	int num = d(4);
}