#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode* curA = headA;
	struct ListNode* curB = headB;
	int lenA = 0, lenB = 0;
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}
	while (curA->next)
	{
		lenA++;
		curA = curA->next;
	}
	while (curB->next)
	{
		lenB++;
		curB = curB->next;
	}
	if (curA != curB)
	{
		return NULL;
	}
	int gap = abs(lenA - lenB);
	struct ListNode* longlist = headA;
	struct ListNode* shortlist = headB;
	if (lenA<lenB)
	{
		longlist = headB;
		shortlist = headA;
	}
	while (gap--)
	{
		longlist = longlist->next;
	}
	while (longlist != shortlist)
	{
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
	return longlist;
}