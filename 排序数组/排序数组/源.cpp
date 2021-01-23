#define _CRT_SECURE_NO_WARNINGS 1
int* sortArray(int* nums, int numsSize, int* returnSize){

	int gap = 3;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i<numsSize - gap; i++)
		{
			int end = i;
			int tmp = nums[end + gap];
			while (end >= 0)
			{
				if (tmp<nums[end])
				{
					nums[end + gap] = nums[end];
					end = end - gap;
				}
				else
				{
					break;
				}
			}
			nums[end + gap] = tmp;
		}
	}
	*returnSize = numsSize;
	return nums;
}