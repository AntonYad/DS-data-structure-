#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode  *cur, *prev;
	cur = head;
	prev = NULL;
	while (cur)
	{
		struct ListNode *next = cur->next;
		if (cur->val = val)
		{
			if (prev == NULL)
			{
				head = cur->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(cur);
			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}