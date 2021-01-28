#define _CRT_SECURE_NO_WARNINGS 1
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int* tmp = malloc(sizeof(int)*ASize);
	int* tmp1 = malloc(sizeof(int)*ASize);
	int* tmp2 = malloc(sizeof(int)*ASize);
	int j = 0;
	int k = 0;
	for (int i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			tmp1[j++] = A[i];
		}
		else
		{

			tmp2[k++] = A[i];
		}
	}

	for (int i = 0; i<k; i++)
	{
		tmp1[j++] = tmp2[i];
	}
	*returnSize = ASize;
	return tmp1;
}