#define _CRT_SECURE_NO_WARNINGS 1
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;
	Node *cur = head;
	while (cur)
	{
		Node *copycur = (Node *)malloc(sizeof(Node));
		copycur->next = NULL;
		copycur->random = NULL;
		copycur->val = cur->val;
		Node *next = cur->next;
		cur->next = copycur;
		copycur->next = next;
		cur = next;
	}
	cur = head;
	while (cur)
	{
		Node *copycur = cur->next;
		if (cur->random)
		{
			copycur->random = cur->random->next;
		}
		else
		{
			copycur->random = NULL;
		}
		cur = cur->next->next;
	}
	cur = head;
	Node* copyhead = head->next;
	while (cur)
	{
		Node* copycur = cur->next;
		Node* next = cur->next->next;
		if (next)
		{
			copycur->next = next->next;
		}
		else
		{
			copycur->next = NULL;
		}
		cur = next;
	}
	return copyhead;
}