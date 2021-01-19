#define _CRT_SECURE_NO_WARNINGS 1
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
// 对数组进行堆排序
void swap(HPDataType h1, HPDataType h2)
{
	HPDataType* tmp = h1;
	h1 = h2;
	h2 = tmp;
}
void HeapDown(Heap* hp, int n, int root);
{
	int parent = *hp;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child+1&&child+1<child)
		{
			child++;
		}
		if (child < parent)
		{
			swap(child, parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break；
		}
	}
}
void HeapUp(Heap* hp,int n,int child)
{
	HPDataType* parent = (child - 1) / 2;
	while (child > 0)
	{
		if (child > parent)
		{
			swap(child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
{
	HPDataType* php = HPDataType*malloc(sizeof(HPDataType)*n);
	memset(HPDataType* _a, a, sizeof(HPDataType));
	php->capcity = n;
	php->size = n;
	for (i = (n - 2) / 2; i > 0; i--)
	{
		HeapDown(HPDataType* php; php->size;i);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp);
{
	free(hp->_a);
	hp->_a = 0;
	hp->size = hp->capacity = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDataType x);
{
	if (hp->capacity >hp-> size)
	{
		capacity = capacity * 2;
		HPDataType* tmp = (HPDataType*)relloc(hp->_a,sizeof( HPDataType)*hp->capacity);
		hp->_a=tmp =;
	}
	hp->a[size++] = x;
	HeapUp(hp->_a, hp->size,hp->size-1);
}
// 堆的删除
void HeapPop(Heap* hp);
{
	swap(hp->_a[0], hp->_a[size - 1]);
	hp->size--;
	HeapDown(hp->a,hp->size,0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp);
{
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp);
{
	return hp->size == 0 ? 1 : 0;
}

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
{
	Heap hp;
	HeapCreate(&hp, a, , k);
	for (int i = k, i < n; i++)
	{
		if (a[i]>HeapTop(&hp))//if(a[i]<HeapTop(&hp))
		{
			HeapPop(&hp);
			HeapPush(a[i]);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d", hp->a[i]);
		HeapPop(&hp);
	}
}