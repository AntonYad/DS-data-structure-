#define _CRT_SECURE_NO_WARNINGS 1
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int* head = (int*)malloc(sizeof(int)* 2);
	head[0] = -1;
	head[1] = -1;
	int i;
	for (i = 0; i<numsSize; i++)
	{
		if (nums[i] == target)
		{
			head[0] = i;
			break;
		}
	}

	for (i; i<numsSize; i++)
	{
		if (nums[i] == target)
		{
			head[1] = i;
		}
		else
			break;
	}

	*returnSize = 2;
	return head;
}