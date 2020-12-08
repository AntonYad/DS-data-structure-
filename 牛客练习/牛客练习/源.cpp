#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, x, sum = 0;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &x);

	for (int j = 0; j<n; j++)
	if (a[j] == x)
		++sum;
	printf("%d", sum);
	return 0;
}