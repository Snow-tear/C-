#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define SIZE 50
#define NEIGHBOR 3

void print(bool ban[SIZE + 2][SIZE + 2]);
void survive(bool the_origin_ban[SIZE + 2][SIZE + 2], bool the_new_ban[SIZE + 2][SIZE + 2]);
bool judge(bool ban[SIZE + 2][SIZE + 2],int i ,int j);
void newban(bool ban[SIZE + 2][SIZE + 2]);

int main(void) {
	bool ban1[SIZE + 2][SIZE + 2];
	bool ban2[SIZE + 2][SIZE + 2] = { 0 };
	newban(ban1);

	int layer = 0;
	while (layer<500) {
		printf("layer = %d\n", layer);
		if (layer % 2 == 0) {
			print(ban1);
			survive(ban1, ban2);			
		}
		else {
			print(ban2);
			survive(ban2, ban1);			
		}
		layer++;
	}
}

void print(bool ban[SIZE + 2][SIZE + 2]) {
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			if (ban[i][j]) printf("* "); else printf("  ");
		}
		printf("\n");
	}
	printf("\n");
}

void survive(bool ban1[SIZE + 2][SIZE + 2], bool ban2[SIZE + 2][SIZE + 2]) {
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			ban2[i][j] = judge(ban1, i, j);
		}
	}
}

//1． 如果一个细胞周围有3个细胞为生（一个细胞周围共有8个细胞），则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变） 。
//2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变；
//3． 在其它情况下，该细胞为死（即该细胞若原先为生，则转为死，若原先为死，则保持不变）
bool judge(bool ban[SIZE + 2][SIZE + 2], int i, int j)
{
	int neighbor = 0;
	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			neighbor += (int)(ban[i+y][j+x]==true);
		}
	}
	neighbor -= ban[i][j];
	if (neighbor == NEIGHBOR)return true;
	else if (neighbor == (NEIGHBOR - 1))return ban[i][j];
	else return false;
}

void newban(bool ban[SIZE + 2][SIZE + 2])
{
	srand((unsigned)time(NULL));
	for (int i = 1; i <= SIZE; i++) {
		for (int j = 1; j <= SIZE; j++) {
			ban[i][j] = rand() % 2;
		}
	}
}