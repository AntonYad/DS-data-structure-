#define _CRT_SECURE_NO_WARNINGS 1
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int tmp;
	for (int i = 0; i<n; i++)
	{
		nums1[m + i] = nums2[i];
	}
	for (int i = 0; i<m + n; i++)
	{
		for (int j = i; j<m + n; j++)
		{
			if (nums1[i]>nums1[j])
			{
				tmp = nums1[j];
				nums1[j] = nums1[i];
				nums1[j] = tmp;
			}


		}
	}
}