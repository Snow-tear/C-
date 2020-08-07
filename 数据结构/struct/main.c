#include"main.h"



int main(int argc, char* argv[]) {

	struct human0 {			//声明一个结构
		char name[20];
		int age;
		bool sex;
		float height;
		float weight;
	};

	struct human0 Jerry0;				//定义结构变量
	strcpy(Jerry0.name, "孙际翔");
	Jerry0.age = 17;
	printf("0: %s's age is %d\n", Jerry0.name, Jerry0.age);

	struct human0 Jerry2 = {			//初始化结构变量  结构变量和数组类似,只有在初始化结构变量的时候才能用大括号赋值
		"孙际翔",
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
	}Jerry1;				 //声明结构的同时定义结构变量

	strcpy(Jerry1.name, "孙际翔");
	Jerry1.age = 17;
	printf("1: %s's age is %d\n", Jerry1.name, Jerry1.age);

	struct human0 *Jerry3;	//声明指向结构的指针
	Jerry3 = &Jerry0;
	strcpy((*Jerry3).name, "sjx");
	(*Jerry3).age = 17;
	printf("3: %s's age is %d\n", Jerry3->name,Jerry3->age);


}