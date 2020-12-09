#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int m, language, math, english, sum = 0, people = 0;
	scanf("%d", &m);
	for (int i = 0; i<m; i++)
	{
		scanf("%d%d%d", &language, &math, &english);
		sum = (language + math + english) / 3;
		if (sum<60)
		{
			people++;
		}
	}
	printf("%d", people);
	return 0;
}