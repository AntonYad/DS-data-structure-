#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i, j, a[1000];
	for (i = 0; i<n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i<n; i++)
	{
		for (j = i + 1; j<n; j++)
		{
			if (a[i] == a[j])
			{
				a[j] = 0;
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		if (a[i] != 0)
			printf("%d ", a[i]);
	}
	return 0;
}