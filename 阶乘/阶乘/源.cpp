#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n;
	int st = 1;
	int sum = 0;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		st = st*i;
		sum = sum + st;
	}
	printf("%d\n", sum);
	return 0;
}