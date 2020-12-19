#define _CRT_SECURE_NO_WARNINGS 1
int removeElement(int* nums, int numsSize, int val)
{
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] = val)
			nums[i] = nums[i + 1];
		numsSize--;
	}
	return numsSize;
}