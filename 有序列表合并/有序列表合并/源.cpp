#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j, tmp;
	int a[100000], b[5000];
	for (i = 0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = n; i<n + m; i++)
	{
		scanf("%d", &b[i]);
		a[i] = b[i];
	}
	for (i = 0; i<n + m; i++)
	for (j = i + 1; j<n + m; j++)
	{
		if (a[i]>a[j])
		{
			tmp = a[j];
			a[j] = a[i];
			a[i] = tmp;
		}
	}
	for (i = 0; i<n + m; i++)
		printf("%d ", a[i]);
	return 0;
}