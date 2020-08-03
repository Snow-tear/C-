#include"life_game.h"

int main(void) {
	bool ban[2][SIZE + 2][SIZE + 2] = { false };
	newban(ban[0]);

	
	for (register int layer = 0; getchar()=='\n'; layer++) {
		printf("第%d层\n", layer+1);
		print(ban[layer % 2]);
		survive(ban[layer % 2], ban[1 - (layer % 2)]);
	}
	printf("GAME OVER\n");
}

void print(bool ban[SIZE + 2][SIZE + 2]) {
	for (register int i = 0; i <= SIZE; i++)printf("--");
	printf("\n");
	for (register int i = 1; i <= SIZE; i++) {
		printf("|");
		for (register int j = 1; j <= SIZE; j++)printf("%c ", (ban[i][j]) ? '*' : ' ');
		printf("|\n");
	}
	for (register int i = 0; i <= SIZE; i++)printf("--");
	printf("\n");
}

void survive(bool ban1[SIZE + 2][SIZE + 2], bool ban2[SIZE + 2][SIZE + 2]) {
	for (register int i = 1; i <= SIZE; i++)for (register int j = 1; j <= SIZE; j++) ban2[i][j] = judge(ban1, i, j);
}

//1． 如果一个细胞周围有3个细胞为生（一个细胞周围共有8个细胞），则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变） 。
//2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变；
//3． 在其它情况下，该细胞为死（即该细胞若原先为生，则转为死，若原先为死，则保持不变）
bool judge(bool ban[SIZE + 2][SIZE + 2], int i, int j)
{
	register int neighbor = 0;
	for (register int y = -1; y <= 1; y++) for (register int x = -1; x <= 1; x++)neighbor += ban[i + y][j + x];
	neighbor -= ban[i][j];
	if (neighbor == NEIGHBOR)return true;
	else if (neighbor == (NEIGHBOR - 1))return ban[i][j];
	else return false;
}

void newban(bool ban[SIZE + 2][SIZE + 2])
{
	srand(time(NULL));
	for (register int i = 1; i <= SIZE; i++) for (register int j = 1; j <= SIZE; j++) ban[i][j] = rand() % 2;
}