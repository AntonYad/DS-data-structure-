#define _CRT_SECURE_NO_WARNINGS 1
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		int a[900] = { 0 };
		int n = 0;
		while (A)
		{
			a[n++] = A->val;
			A = A->next;
		}
		int begin = 0;
		int end = n - 1;
		while (begin<end)
		{
			if (a[begin] != a[end])
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}
		}
		return true;
	}
};
