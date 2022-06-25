#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

struct ListNode
{
	int val;
	struct ListNode* next;
};

/*
给你一个链表的头节点head 和一个整数val，请你删除链表中所有满足
Node.val == val的节点，并返回新的头节点。

*/
struct ListNode* removeElement(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, *cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			// 1.头删
			// 2.中间删除
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
			
		}
		else
		{
			// 迭代往后走
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}


//int main()
//{
//
//	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
//
//	n1->val = 7;
//	n2->val = 7;
//	n3->val = 7;
//	n4->val = 7;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//	n4->next = NULL;
//
//	struct ListNode* head = removeElement(n1, 7);
//
//	return 0;
//}