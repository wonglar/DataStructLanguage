#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

struct ListNode
{
	int val;
	struct ListNode* next;
};

/*
����һ�������ͷ�ڵ�head ��һ������val������ɾ����������������
Node.val == val�Ľڵ㣬�������µ�ͷ�ڵ㡣

*/
struct ListNode* removeElement(struct ListNode* head, int val)
{
	struct ListNode* prev = NULL, *cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			// 1.ͷɾ
			// 2.�м�ɾ��
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
			// ����������
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