#define _CRT_SECURE_NO_WARNINGS 1
int removeDuplicates(int* nums, int numsSize)
{
	int k = 0;
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (nums[j] == nums[i])
			{
				nums[j] = -1;
			}
		}
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] >= 0)
		{
			k++;
		}

	}
	return k;

}