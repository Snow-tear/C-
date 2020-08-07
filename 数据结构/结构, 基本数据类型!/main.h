#pragma once
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phone {
	char *name;
	float size;
	int value;
};

void changeMix2name(struct phone* mix2p);
void printMix2name(struct phone mix2f);

