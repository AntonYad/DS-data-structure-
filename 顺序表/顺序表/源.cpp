#define _CRT_SECURE_NO_WARNINGS 1
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(*ps);//���Ƿ���ߵ�ָ�봫�����п�
	assert(pos < p->size && pos >= 0);//�жϲ���λ��
	if (ps->size>ps->capacity)//����Ƿ��������ڿ��ٿռ�  ���
	{
		ps->capacity = ps->capacity * 2;
		ps->a = (int*)realloc(ps->a,sizeof(int)*ps->capacity);
	}
	int end = p->size - 1;// endλ��Ϊ˳����ĩ��
	while��end>pos��//���end��λ���Ǵ��ڲ���λ�þͿ��Լ���ѭ��
	{
		ps->a[end+1] = ps->a[end ];//��˳�������ƶ�һλ����
		end--;//��ǰɨ������
	}
	ps->a[pos]=x;//��ʱend��λ�������洢����λ�� ��Ϊ�Ѿ�����ƶ���
	size++��//������+1
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(*ps);//�п�
	assert(pos < ps->size);//˳��������size֮��
	int start = pos + 1��
	while��start < ps->size - 2��//-2����Ϊ������ĩ����size-1 ��Ϊǰ�ƾ��൱��startָ��size-1��ǰһλ�ƶ�
	{
		ps->[start] = ps->[start + 1];
		start++;
	}
	size--;
}
