#define _CRT_SECURE_NO_WARNINGS 1
int thirdMax(int* nums, int numsSize){
	if (numsSize == 0)
	{
		return 0;
	}
	if (numsSize == 1)
	{
		return nums[0];
	}
	if (numsSize == 2)
	{
		return nums[0]>nums[1] ? nums[0] : nums[1];
	}
	long long  first = -9223372036854775808, second = -9223372036854775808, third = -9223372036854775808;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i]>first)
		{
			third = second;
			second = first;
			first = nums[i];
		}
		if (nums[i]<first&&nums[i]>second)
		{
			third = second;
			second = nums[i];
		}
		if (nums[i]<second&&nums[i]>third)
		{
			third = nums[i];
		}
	}
	if (third == -9223372036854775808)
	{
		return first;
	}
	return third;

}