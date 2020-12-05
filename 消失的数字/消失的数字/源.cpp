#define _CRT_SECURE_NO_WARNINGS 1
int missingNumber(int* nums, int numsSize)
{
	int len = numsSize;//数组长度
	int n = len;
	for (int i = 0; i < len; i++)
		n = n + i - nums[i];
	return n;

}