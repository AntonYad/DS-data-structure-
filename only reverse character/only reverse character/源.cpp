#define _CRT_SECURE_NO_WARNINGS 1
char * reverseOnlyLetters(char * S)
{
	if (S == NULL)
	{
		return NULL;
	}

	int size = strlen(S);
	int begin = 0;
	int end = size - 1;
	while (begin<end)
	{
		if ((S[begin] >= 'a'&&S[begin] <= 'z') || (S[begin] >= 'A'&&S[begin] <= 'Z'))
		{
			if ((S[end] >= 'a'&&S[end] <= 'z') || (S[end] >= 'A'&&S[end] <= 'Z'))
			{
				char tmp = S[begin];
				S[begin] = S[end];
				S[end] = tmp;
				begin++;
				end--;
			}
			else
			{
				end--;
			}
		}
		else if ((S[end] >= 'a'&&S[end] <= 'z') || (S[end] >= 'A'&&S[end] <= 'Z'))
		{
			begin++;
		}
		else
		{
			begin++;
			end--;
		}
	}
	return S;
}