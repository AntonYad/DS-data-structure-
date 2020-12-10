#define _CRT_SECURE_NO_WARNINGS 1
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(*ps);//看是否将外边的指针传进来判空
	assert(pos < p->size && pos >= 0);//判断插入位置
	if (ps->size>ps->capacity)//检查是否容量大于开辟空间  溢出
	{
		ps->capacity = ps->capacity * 2;
		ps->a = (int*)realloc(ps->a,sizeof(int)*ps->capacity);
	}
	int end = p->size - 1;// end位置为顺序表的末端
	while（end>pos）//如果end的位置是大于插入位置就可以继续循环
	{
		ps->a[end+1] = ps->a[end ];//将顺序表向后移动一位用来
		end--;//往前扫描数据
	}
	ps->a[pos]=x;//此时end的位置用来存储插入位置 因为已经向后移动了
	size++；//将容量+1
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(*ps);//判空
	assert(pos < ps->size);//顺出数据在size之内
	int start = pos + 1；
	while（start < ps->size - 2）//-2是因为本来是末端是size-1 因为前移就相当于start指向size-1的前一位移动
	{
		ps->[start] = ps->[start + 1];
		start++;
	}
	size--;
}
