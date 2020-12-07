#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int a[m][m];
	for (i = 0; i<n; i++)
	for (j = 0; j<m; j++)
	{
		scanf("%d ", &a[i][j]);
	}
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
}