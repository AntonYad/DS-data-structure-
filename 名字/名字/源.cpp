#define _CRT_SECURE_NO_WARNINGS 1
bool isLongPressedName(char * name, char * typed){
	int sizename = strlen(name);
	int sizetyped = strlen(typed);
	int i = 0, j = 0;
	while (j<sizetyped)
	{
		if (name[i] == typed[j])
		{
			i++;
			j++;
		}
		else if (j>0 && typed[j] == typed[j - 1])
		{
			j++;
		}
		else
			return false;
	}
	return i == sizename;

}