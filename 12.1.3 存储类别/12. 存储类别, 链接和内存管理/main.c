#include<stdio.h>
#include<stdlib.h>
extern unsigned int rann(void);


int �ⲿ����;	//��̬�ⲿ���Ӵ洢���
extern int ��Ҳ���ⲿ����;	//extern����ָ���˱��������ڱ�ķ��뵥Ԫ��,��extern.c
static int �ڲ����ӵľ�̬����;	//��̬�ڲ����Ӵ洢���

int main() {
	int �Զ�����;	//�Զ��洢���
	auto int ��Ҳ���Զ�����;	//auto����ǿ���Զ������洢���
	register int �Ĵ�������;	//�Ĵ����洢���
	static int �ֲ���̬����;	//��̬�����Ӵ洢���
	srand(78);
	for(int i=0;i<9;i++)printf("%d: %d\n",i, rand());
}

