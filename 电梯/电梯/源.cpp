#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n<12)
		printf("2");
	else
		printf("%d", n / 12 * 4 + 2);
}