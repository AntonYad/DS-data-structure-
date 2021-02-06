#define _CRT_SECURE_NO_WARNINGS 1
char * addBinary(char * a, char * b)
{
	int i, j, carry = 0, k = 0;
	int length1 = strlen(a) - 1;
	int lenght2 = strlen(b) - 1;
	int sum;
	char* nums = malloc(sizeof(int)* 1000);
	for (i = length1, j = lenght2; i >= 0 || j >= 0 || carry; i--, j--)
	{
		int x = i<0 ? 0 : a[i] - '0';
		int y = j<0 ? 0 : b[j] - '0';
		sum = (x + y + carry) % 2;
		carry = (x + y + carry) / 2;
		nums[k++] = sum + '0';
	}
	nums[k] = '\0';
	for (i = 0, j = k - 1; i<j; i++, j--)
	{
		char tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
	return nums;
}