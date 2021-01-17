#define _CRT_SECURE_NO_WARNINGS 1
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			ListNode *pos = head;

			while (pos != fast)
			{
				pos = pos->next;
				fast = fast->next;
			}
			return pos;
		}
	}
	return false;



}