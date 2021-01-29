#define _CRT_SECURE_NO_WARNINGS 1
int pivotIndex(int* nums, int numsSize)
{
	for (int i = 0; i<numsSize; i++)
	{
		int leftsum = 0;
		int rightsum = 0;
		for (int j = 0; j<i; j++)
		{
			leftsum += nums[j];
		}
		for (int k = numsSize - 1; k>i; k--)
		{
			rightsum += nums[k];
		}
		if (rightsum == leftsum)
			return i;
	}
	return -1;
}