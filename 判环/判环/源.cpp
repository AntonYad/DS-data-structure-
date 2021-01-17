#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *slow = head;;
		while (fast&&fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				return true;
			}
		}
		return false;
	}
};