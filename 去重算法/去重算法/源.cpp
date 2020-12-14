#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(){
	int n, i, input, max = 0;
	int a[100001] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i< n; i++)
	{
		scanf("%d", &input);
		a[input] = input;      // 把相同的数存进相同的数组元素中， 
		if (input >= max)
		{            // 这样该数组元素只会保留一个相同的数
			max = input;
		}
	}
	for (i = 1; i <= max; i++)
	{
		if (a[i])
		{             //按序输出非零元素
			printf("%d ", a[i]);
		}
	}
	return 0;
}