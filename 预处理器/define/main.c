#include"main.h"

#define a "ab alksdjflk"	//������ע��, �����"������"
#define b(x) "aslkjdf"#x"asdfj"	//���"�ຯ����"
#define b(x) "aslkjdf"#x"asdf"	//һ��������������ض����, ����һģһ��. VS����Ḳ�ǵ�����

int main(int argc, char* argv[]) {
	printf("%s\n", a);
	printf("a\n");	//��������ĺ겻������
	printf("%s\n",b(0));	//�ຯ������,#����������ò�����ɴ�˫���ŵ��ַ���. �˴���Ϊ0���"0". ���"�ַ�����"(stringizing)
}