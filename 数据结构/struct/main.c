#include"main.h"



int main(int argc, char* argv[]) {

	struct human0 {			//����һ���ṹ
		char name[20];
		int age;
		bool sex;
		float height;
		float weight;
	};

	struct human0 Jerry0;				//����ṹ����
	strcpy(Jerry0.name, "�����");
	Jerry0.age = 17;
	printf("0: %s's age is %d\n", Jerry0.name, Jerry0.age);

	struct human0 Jerry2 = {			//��ʼ���ṹ����  �ṹ��������������,ֻ���ڳ�ʼ���ṹ������ʱ������ô����Ÿ�ֵ
		"�����",
		17,
		1,
		183,
		72
	};
	printf("2: %s's age is %d\n", Jerry2.name, Jerry2.age);

	struct human1 {			
		char name[20];
		int age;
		bool sex;
		float height;
		float weight;
	}Jerry1;				 //�����ṹ��ͬʱ����ṹ����

	strcpy(Jerry1.name, "�����");
	Jerry1.age = 17;
	printf("1: %s's age is %d\n", Jerry1.name, Jerry1.age);

	struct human0 *Jerry3;	//����ָ��ṹ��ָ��
	Jerry3 = &Jerry0;
	strcpy((*Jerry3).name, "sjx");
	(*Jerry3).age = 17;
	printf("3: %s's age is %d\n", Jerry3->name,Jerry3->age);


}