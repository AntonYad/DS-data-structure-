#define _CRT_SECURE_NO_WARNINGS 1
char isbig(char a)
{
	if (a >= 'A'&&a <= 'Z')
	{
		return a = a + 32;
	}
	return a;
}
bool istrue(char a)
{
	if (a >= '0'&&a <= '9')
		return true;
	else if (a >= 'a'&&a <= 'z')
		return true;
	else if (a >= 'A'&&a <= 'Z')
		return true;
	else
		return false;
}
bool isPalindrome(char * s){
	int begin = 0;
	int size = strlen(s);
	int end = size - 1;
	if (size <= 1)
	{
		return true;
	}
	while (begin<end)
	{

		while (begin<end&&!istrue(s[begin]))
		{
			begin++;
		}
		while (begin<end&&!istrue(s[end]))
		{
			end--;
		}
		if (begin<end&&isbig(s[begin]) != isbig(s[end]))
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}