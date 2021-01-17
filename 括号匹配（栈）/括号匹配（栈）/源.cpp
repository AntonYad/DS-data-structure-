#define _CRT_SECURE_NO_WARNINGS 1
bool isValid(char * s)
{
	char *stack = (char *)malloc(sizeof(char)* 10000);
	int top = 0;
	int count = 0;
	while (*(s + count) != '\0')
	{
		char c = *(s + count);
		if (c == '(' || c == '{' || c == '[')
		{
			stack[top++] = c;
		}
		else if (c == ')' || c == '}' || c == ']')
		{
			if (top > 0)
			{
				if ((c == ')' && stack[top - 1] != '(') || (c == '}' && stack[yop - 1] != '{') || (c == ']' && stack[top - 1] != '['))
				{
					return false;
				}
				else
				{
					top--;
				}
			}
			else
			{
				return false;
			}
		}
		count++;
	}
	if (top>0)
	{
		return false;
	}
	return true;
}