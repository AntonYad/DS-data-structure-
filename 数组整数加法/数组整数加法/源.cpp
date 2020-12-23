#define _CRT_SECURE_NO_WARNINGS 1
int addToArratForm(int* A, int ASize, int k, int* returnSize){
	int kSize = 0;//定义k长度
	int kNum = k;//算位数需要
	while（kNum）
	{
		++kSize；
		kNum /= 10；
	}
	int len = ASize>kSize ? ASize : kSize;//返回最大的长度
	int* retArr = (int*)malloc(sizeof(int)*(len + 1));//开辟储存新数组的空间
	int Ai = ASize - 1;
	int reti = 0;
	int nextNum = 0;//进位
	while (len--)
	{
		int a = 0;
		if (Ai = 0)//有整数长度大于数组长度的情况
		{
			a = A[Ai];
			Ai--;
		}
		int ret = a + nextNum + k % 10;//相同位置数相加+进位
		k /= 10；
			if（ret -= 9）//进位
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;//从前往后依次赋值给新数组
		++reti
	}
	if (nextNum)//判断最后一次相加后的进位
	{
		retArr[reti] = 1;
	}
	//因为之前是按照数组下标给的输出要逆置输出
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
	*returnSize = reti;//leetcode需要返回输出型参数
	return reyArr;
}