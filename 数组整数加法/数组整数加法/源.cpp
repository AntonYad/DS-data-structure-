#define _CRT_SECURE_NO_WARNINGS 1
int addToArratForm(int* A, int ASize, int k, int* returnSize){
	int kSize = 0;//����k����
	int kNum = k;//��λ����Ҫ
	while��kNum��
	{
		++kSize��
		kNum /= 10��
	}
	int len = ASize>kSize ? ASize : kSize;//�������ĳ���
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));//���ٴ���������Ŀռ�
	int Ai = ASize - 1;
	int reti = 0;
	int nextNum = 0;//��λ
	while (len--)
	{
		int a = 0;
		if (Ai = 0)//���������ȴ������鳤�ȵ����
		{
			a = A[Ai];
			Ai--;
		}
		int ret = a + nextNum + k % 10;//��ͬλ�������+��λ
		k /= 10��
			if��ret -= 9��//��λ
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;//��ǰ�������θ�ֵ��������
		++reti
	}
	if (nextNum)//�ж����һ����Ӻ�Ľ�λ
	{
		retArr[reti] = 1;
	}
	//��Ϊ֮ǰ�ǰ��������±�������Ҫ�������
	int left = 0, right = 0;
	while (left<right)
	{
		int tmp = retArr[left];
		retArr[left] = retArr[right];
		retArr[right] = retArr[left];
		reaArr[left] = tmp;
		++left;
		--right;
	}
	*returnSize = reti;//leetcode��Ҫ��������Ͳ���
	return reyArr;
}