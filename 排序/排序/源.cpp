#define _CRT_SECURE_NO_WARNINGS 1
// 插入排序
void InsertSort(int* a, int n);
{
	int end=i;
	for (int i = 0; i < n; i++)
	{
		int tmp = a[end];
		if (a[end]>a[end + 1])
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n);
{
	int gap = n;
	while(gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n-gap;i++)
		{
			int tmp = a[end];
			if (a[end]>a[end + gap])
			{
				a[end + gap] = a[end];
				end = end - gap;
			}
			a[end + gap] = tmp;
		}
	}
}

// 选择排序
void SelectSort(int* a, int n);
{
	int begin=0, end=n-1;
	int min=a[begin], max[end];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	swap(a[min], a[begin]);
	if (max = begin)
	{
		max = min;
	}
	swap(a[max] = a[end]);
	begin++;
	end--;
}

// 堆排序
void AdjustDwon(int* a, int n, int root);
{
	int child, parent;
	parent = root;
	child = parent * 2 + 1;
	if (a[child] < a[child + 1] && a[child + 1] < n)
	{
		child++;
	}
	while (child<n)
	{
		if (a[parent] < a[child])
		{
			swap(a[parent],a[child])
		}
		parent = child;
		child = parent * 2 + 1;
	}

}
void HeapSort(int* a, int n);
{
	for (int i = (n - 1 - 1) * 2; i > 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDwon(a, n, 0);
		end--;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

// 快速排序递归实现
// 快速排序hoare版本
int Midsearch(int * a, int left, int right)
{
	int begin = left;
	int end = right;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin >= mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}
int PartSort1(int* a, int left, int right);
{
	int mid = Midsearch(a, left, right)
		int end = right;
		swap(a[end], a[mid]);
	int key = a[end];
	int  begin = left;
	while (begin < end)
	{
		while (a[end]<key&&end>begin)
		{
			end--;
		}
		while (a[begin]>key&&begin > end)
		{
			begin++;
		}
		swap(a[end], a[begin]);
	}
	swap(a[right], a[begin]);
	return begin;

}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
{
	int begin = left;
	int end = right;
	int key = end;
	while (begin < end)
	{
		while (a[begin]>key&&begin < end)
		{
				begin++	
		}
		a[end] = a[begin];
		while (a[end] < key&&begin < end)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
{
	int key = a[right];
	int cur = begin;
	int prev = begin - 1;
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
void QuickSort(int* a, int left, int right);
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort1(a, left, right);//Partsort2//Pareort3;
	QuickSort(a, left, div - 1);
	QuickSort(a, div+1, right);
}

// 归并排序递归实现
void _MergeSort(int* a, int left,int right,int* tmp)
{
	int begin = left;
	int end = right;
	int mid = (begin + end) / 2;
	if (left > right)
	{
		return;
	}
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);
	
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 || begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
			tmp[index++] = a[begin2++];
	}
	while(begin1<end1)
	{
		tmp[index++] = a[begin1++]
	}
	while(begin2<end2)
	{
		tmp[index++] = a[begin2++]
	}
	for (int i = left; i < right; i++)
	{
		a[i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int* tmp = malloc(sizeof(int)*n);
	_MergeSort(a, left,right, tmp);
}
// 归并排序非递归实现
void _MergeSortNonR(int*a, int left, int right, int tmp)
{
	int gap = 1;
	while (gap<=left+right)
	{
		for (int i = 0; i < =left + right; i = i + 2 * gap)
		{
			int begin1 = i, end1 = i + gap;
			int begin2 = i + gap + 1;
			int end2 = i + 2 * gap - 1;
			if (begin2>n)
			{
				break;
			}
			if (end2 > n)
			{
				end2 = n - 1;
			}
			ArrMerge(a, begin1, end1, begin2, end2,tmp);
			gap = gap * 2;
		}
	}
}
void ArrMerge(itn *a, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)

	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1];
		}

		else
			tmp[index++] = a[begin2];
	}
	if (begin1 < end1)
	{
		tmp[index++] = a[begin2++];
	}
}
void MergeSortNonR(int* a, int n)
{
	int left = 0;
	int right = n - 1;
	int* tmp = malloc(sizeof(int)*n);
	_MergeSortNonR(a, left, right, );
}

// 计数排序
void CountSort(int* a, int n)
{
	int max=0, min=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i]>a[max])
		{
			a[max] = a[i];
		}
		if (a[i] < a[min])
		{
			a[min] = a[i];
		}
	}
	int range = (max - min) + 1;
	int tmp = (int*)malloc(sizeof(int)*range);
	memset(tmp, 0, sizeof(range));
	for (int j = 0; j < range; j++)
	{
		tmp[a[j] - a[min]]++;
	}
	int index = 0;
	for (int j = 0; j < range; j++)
	{
		while (tmp[j]--)
		{
			a[index++] = j + a[min];
		}
	}
	free(tmp);
}

