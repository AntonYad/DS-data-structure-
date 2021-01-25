#define _CRT_SECURE_NO_WARNINGS 1
int lengthOfLastWord(char * s){
	int size = strlen(s);
	int flag = 0;
	int count = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (count == 0)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		count++;
	}
	return count;
}
