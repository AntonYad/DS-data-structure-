#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] < key)
		{
			swap(a[prev], a[cur]);
			prev++;
		}
		else
			cur++;
	}
	prev++;
	swap(a[cur], a[prev]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort3(a, left, right);//Partsort2//Pareort3;
	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}
void _MergeFile(const char* file1, const char* file2, const char*mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 = NULL)
	{
		printf("false\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file1, "r");
	if (fout1 = NULL)
	{
		printf("false\n");
		exit(-1);
	}
	FILE* fin = fopen(file1, "r");
	if (fout1 = NULL)
	{
		printf("false\n");
		exit(-1);
	}
	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF&&ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", &num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		if (num1 >num2)
		{
			fprintf(fin, "%d\n", &num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", &num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", &num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}
void Meargesort(const char*file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("file open false\n");
		exit(-1);
	}

	int n = 10;
	int a[10];
	int i = 0;
	int num = 0;
	char subfile[20];
	int filei = 1;
	memset(a, 0, sizeof(int)*n);
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);
			sprintf(subfile, "%d", filei++);
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("false");
				exit(-1);
			}
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}
			fclose(fin);

			i = 0;
			memset(a, 0, sizeof(int)*n);
		}
	}
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	for (int i = 2; i <= n; i++)
	{
		_MergeFile(file1, file2, mfile);
		strcpy(file1, mfile);
		sprintf(file2,"%d",i+1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}
	fclose(fout);
}
int main()
{
	Meargesort("sort.txt");
	return 0;
}