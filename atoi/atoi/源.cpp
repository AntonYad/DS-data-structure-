#define _CRT_SECURE_NO_WARNINGS 1
int myAtoi(char * str)
{
	while (*str == ' ')
	{
		str++;
	}
	int flag = 1;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	long long res = 0;
	while ((*str >= '0') && (*str <= '9'))
	{

		res = res * 10 + (*str - '0');
		if ((int)res != res) {
			return (flag == 1) ? (INT_MAX) : (INT_MIN);
		}
		str++;
	}
	return flag*res;
}