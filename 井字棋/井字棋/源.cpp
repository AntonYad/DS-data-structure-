#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() {
	int i, j;
	char a[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%c ", &a[i][j]);
		}
	}

	if (a[0][0] == 'K' && a[0][1] == 'K' && a[0][2] == 'K' || a[1][0] == 'K' && a[1][1] == 'K' && a[1][2] == 'K' || a[2][0] == 'K' && a[2][1] == 'K' && a[2][2] == 'K') {
		printf("KiKi wins!");
	}
	else  if (a[0][0] == 'K' && a[1][0] == 'K' && a[2][0] == 'K' || a[0][1] == 'K' && a[1][1] == 'K' && a[2][1] == 'K' || a[0][2] == 'K' && a[1][2] == 'K' && a[2][2] == 'K') {
		printf("KiKi wins!");
	}
	else  if ((a[0][0] == 'K' && a[1][1] == 'K' && a[2][2] == 'K') || (a[0][2] == 'K' && a[1][1] == 'K' && a[2][0] == 'K')) {
		printf("KiKi wins!");
	}
	else  if (a[0][0] == 'B' && a[0][1] == 'B' && a[0][2] == 'B' || a[1][0] == 'B' && a[1][1] == 'B' && a[1][2] == 'B' || a[2][0] == 'B' && a[2][1] == 'B' && a[2][2] == 'B') {
		printf("BoBo wins!");
	}
	else  if (a[0][0] == 'B' && a[1][0] == 'B' && a[2][0] == 'B' || a[0][1] == 'B' && a[1][1] == 'B' && a[2][1] == 'B' || a[0][2] == 'B' && a[1][2] == 'B' && a[2][2] == 'B') {
		printf("BoBo wins!");
	}
	else  if (a[0][0] == 'B' && a[1][1] == 'B' && a[2][2] == 'B' || a[0][2] == 'B' && a[1][1] == 'B' && a[2][0] == 'B') {
		printf("BoBo wins!");
	}
	else {
		printf("No winner!");
	}
	return 0;
}