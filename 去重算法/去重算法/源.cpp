#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(){
	int n, i, input, max = 0;
	int a[100001] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i< n; i++)
	{
		scanf("%d", &input);
		a[input] = input;      // ����ͬ���������ͬ������Ԫ���У� 
		if (input >= max)
		{            // ����������Ԫ��ֻ�ᱣ��һ����ͬ����
			max = input;
		}
	}
	for (i = 1; i <= max; i++)
	{
		if (a[i])
		{             //�����������Ԫ��
			printf("%d ", a[i]);
		}
	}
	return 0;
}