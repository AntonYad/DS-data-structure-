#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i, j, flog = 1;
	int a[15][15];
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
			if (i>j&&a[i][j] != 0)
				flog = 0;
		}
	}
	if (flog)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}