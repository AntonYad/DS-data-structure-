#define _CRT_SECURE_NO_WARNINGS 1
bool canConstruct(char * ransomNote, char * magazine)
{
	int i = 0, j = 0, k = 0, flag = 0;
	int lenran = strlen(ransomNote);
	int lenmag = strlen(magazine);

	for (i = 0; i < lenran; i++){
		for (j = 0; j < lenmag; j++) {
			if (ransomNote[i] == magazine[j]) {
				magazine[j] = '1';
				k++;
				break;
			}
			if (j == (lenmag - 1)) {
				flag = 1;
			}
		}
		if (flag == 1)
			break;
	}
	return  k == lenran ? true : false;
}