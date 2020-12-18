#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	//思路快指针先跑K步然后和慢指针继续遍历直到fast指向NULL返回slow的位置
	struct ListNode* fast = pListHead; //定义俩快指针
	struct ListNode* slow = pListHead;
	while (k--)
	{
		if (fast == NULL)//如果K的长度大于链表长度
		{
			return NULL;
		}
		else//指向下一个
		{
			fast = fast->next;
		}
	}
	while (fast)//
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
	// write code here
}