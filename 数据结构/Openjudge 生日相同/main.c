#include"main.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{char N[20];char M;char D;};cmp(struct s* O, struct s* T) { if (O->M > T->M)return 1;if (O->M < T->M) return -1;if (O->D > T->D) return 1;if (O->D < T->D) return -1;if (strlen(O->N) > strlen(T->N)) return 1;if (strlen(O->N) < strlen(T->N)) return -1;return strcmp(O->N, T->N); }main() {int n;struct s t[180];scanf("%d", &n);for (int i = 0; i < n; i++) {scanf("%s %hhd %hhd", t[i].N, &t[i].M, &t[i].D);}qsort(t, n, sizeof t[0], cmp);int y = 0, r = 0, Q = 0, q = 0;for (int i = 0; i < n; i++) { if (y != t[i].M || r != t[i].D) { if (q)putchar('\n');q = 0; } else { if (q == 0) { printf("%d %d", t[i].M, t[i].D);i--; }printf(" %s", t[i].N);q = 1;Q++; }y = t[i].M;r = t[i].D; }if (!Q) puts("None");}