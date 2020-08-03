#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

#define SIZE 20
#define NEIGHBOR 3

void print(bool ban[SIZE + 2][SIZE + 2]);
static void survive(bool the_origin_ban[SIZE + 2][SIZE + 2], bool the_new_ban[SIZE + 2][SIZE + 2]);
static bool judge(bool ban[SIZE + 2][SIZE + 2], int i, int j);
static void newban(bool ban[SIZE + 2][SIZE + 2]);