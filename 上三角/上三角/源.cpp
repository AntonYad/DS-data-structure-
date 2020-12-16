#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a[15][15], b[15][15];
	int i, j, n, m, flag = 1;
	scanf("%d", &n);
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			scanf("%d", &a[i][j]);
			if (i>j&&a[i][j]){
				flag = 0;
			}
		}
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
}