#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	long n;
	scanf("%ld", &n);
	printf("%lld", ((1 + n)*n) / 2);
	return 0;
}