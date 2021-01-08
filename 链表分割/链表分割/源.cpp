#define _CRT_SECURE_NO_WARNINGS 1
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		//将X位置划分为两派 小的放一起 大的放一起然后链接
		ListNode* lesshead, *lesstail, *greaterhead, *greatertail;
		ListNode* cur = pHead;
		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode*));//哨兵
		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode*));
		lesstail->next = NULL;//防止随机值
		greatertail->next = NULL;
		while (cur != NULL)//终止条件
		{
			if (cur->val<x)
			{
				lesstail->next = cur;//将此时的值连在小的集合上
				lesstail = cur;//然后尾巴指向此时的值
			}
			else
			{
				greatertail->next = cur;
				greatertail = cur;
			}
			cur = cur->next;//继续往后判断
		}
		lesstail->next = greaterhead->next;//链接在一起
		greatertail->next = NULL;//将最后一个置为NULL
		pHead = lesshead->next;//将头指针指向小的第一个结点
		free(lesshead);
		free(greaterhead);
		return pHead;
	}
};