#define _CRT_SECURE_NO_WARNINGS 1
int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int i;
	int sum = 0;
	*returnSize = 2;
	int *pos = (int*)malloc(sizeof(int)* 2);
	for (i = 0; i < numsSize; i++)
	{
		sum ^= nums[i];
	}
	int ret;
	for (i = 0; i < 32; i++)
	{
		if (sum & 1 << i)
		{
			ret = i;
			break;
		}
	}
	pos[0] = 0;
	pos[1] = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] & 1 << ret)
		{
			pos[0] ^= nums[i];
		}
		else
		{
			pos[1] ^= nums[i];
		}
	}
	return pos;
}