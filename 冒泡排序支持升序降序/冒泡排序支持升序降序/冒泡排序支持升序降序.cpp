#include<stdio.h>
int greater(int x1, int x2)
{
	return x1 > x2 ? 1 : 0;
}

int less(int x1, int x2)
{
	return x1 < x2 ? 1 : 0;
}
void bubble_sort(int* a, int n, int(*p_compreae)(int, int))
{
	for (int end = n - 1; end > 0; --end)
	{
		for (int i = 0; i < end; ++i)
		{
			if (p_compreae(a[i + 1], a[i]))
			{
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}
}
	int main()
	{
	int a[10] = { 9, 3, 2, 6, 5, 7, 1, 8, 0, 4 };
		bubble_sort(a, 10, less);
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	
		bubble_sort(a, 10, greater);
		for (int i = 0; i < 10; ++i)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	return 0;
}