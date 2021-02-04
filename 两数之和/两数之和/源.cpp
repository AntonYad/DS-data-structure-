#define _CRT_SECURE_NO_WARNINGS 1
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int* array = (int*)malloc(sizeof(int)* 2);
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if (target == nums[i] + nums[j])
			{
				array[0] = i;
				array[1] = j;
				*returnSize = 2;
				return array;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}