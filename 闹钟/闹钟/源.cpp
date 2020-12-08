#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int minute, hour = 0, k;
	scanf("%d:%d%d", &hour, &minute, &k);
	minute = minute + k;
	while (minute >= 60)
	{
		minute = minute - 60;
		hour++;
		if (hour >= 24)
		{
			hour = hour - 24;
		}
	}
	printf("%02d:%02d\n", hour, minute);
	return 0;
}