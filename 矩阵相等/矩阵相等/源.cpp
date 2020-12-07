#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int a[15][15], b[15][15];
	int i, j, n, m, flag = 1;
	scanf("%d%d", &n, &m);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("%d", &b[i][j]);
			if (a[i][j] != b[i][j])
				flag = 0;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}