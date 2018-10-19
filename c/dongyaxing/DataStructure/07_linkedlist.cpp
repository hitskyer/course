#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/*
 * 1) 单链表反转
 * 2）链表中环的检测
 * 3）两个有序的链表合并
 * 4）删除链表倒数第n个结点
 * 5）求链表的中间结点
*/

typedef struct SinglyLinkedNode
{
	int data;
	strcut SinglyLinkedNode *next;
} SinglyLinkedNode;

void insertNode(SinglyLinkedNode **head_ref, int data);
void printLinkedList(SinglyLinkedNode *head);

/* 反转单链表 */
void reverse(SinglyLinkedNode **head_ref)
{
	if(*head_ref == NULL)
		return ;

	SinglyLinkedNode *prve = NULL;
	SinglyLinkedNode *current = *head_ref;
	while(current)
	{
		SinglyLinkedNode *next = current->next;
		if(!next)
		{
			*head_ref = current;
		}
		current->next = prev;
		prev = current;
		current = next;
	}
}

void test_reverse()
{
	SinglyLinkedNode *head = Null;
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);
	
	reverse(&head);
	printLinkedList(head);

}

/* 检测单链表是否有环*/
int checkCitcle(SinglyLinkedNode **head_ref)
{
	if(*head_ref == NULL)
		return 0;
	SinglyLinkedNode *slow = *head_ref, *fast = *head_ref;
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast)
			return 1;
	}
	return 0;
}

void test_checkCircle()
{
	SinglyLinkedNode *head = NULL;
	insertNode(&head, 3);
	insertNode(&head, 2);
	insertNode(&head, 1);

	int result1 = checkCircle(&head);
	prinft("has circle: %d\n", result1);

	SinglyLinkedNode *current = malloc(sizeof(SinglyLinkedNode));
	current->data = 0;
	SinglyLinkedNode *h = current;
	for(int i = 1; i < 4; ++i)
	{
		SinglyLinkedNode *node = malloc(sizeof(SinglyLinkedNode));
		node->next = i;
		current->next = node;
	}
	current->next = h;

	int result2 = checkCircle(&h);
	printf("has circle: %d\n", result2);
}

/* 有序链表合并*/
void moveNode(SinglyLinkedNode ** dest_ref, SinglyLinkedNode **src_ref);

SinglyLinkedNode *mergeSortedLinkedList(SinglyLinkedNode *la, SinglyLinkedNode *lb)
{
	SinglyLinkedNode dummy;  //辅助结点，next指针持有合并后的有序链表
	SinglyLinkedNode *tail = &dummy;  //有序链表的尾结点

	while(1)
	{
		//如果有一个链表为空，直接与另一个链表接起来
		if(!la)
		{
			tail->next = lb;
			break;
		}
		else if(!lb)
		{
			tail->next = la;
			break;
		}
		
		//将头结点较小的优先添加到tail
		if(la->next <= lb->next)
		{
			moveNode(&(tail->next), &la);
		} 
		else
		{
			moveNode(&(tail->next), &lb);
		}
		tail = tail->next;
	}
	return dummy.next;
}

//将src_ref 的头结点，添加到dest_ref 的头部
void moveNode(SinglyLinkedNode **dest_ref, SinglyLinkedNode **src_ref)
{
	if(*src_ref == NULL)
		return ;
	SinglyLinkedNode *new_node = *src_ref;

	*src_ref = new_node->next;
	
	new_node->next = *dest_ref;
	*dest_ref = new_node;
}

void test_mergeSortedLinkedList()
{
	SinglyLinkedNode *a = NULL;
	insertNode(&a, 10);
	insertNode(&a, 5);
	insertNode(&a, 0);

	SinglyLinkedNode *b = NULL;
	insertNode(&b, 8);
	insertNode(&b, 6);
	insertNode(&b, 3);
	
	SinglyLinkedNode *result = mergeSortedLinkedList(a, b);
	printLinkedList(result);

	SinglyLinkedNode *result2 = mergeSortedLinkedList(a, NULL);
	printLinkedList(result2)
}

/*删除倒数第K个结点*/
void deleteLastKth(SinglyLinkedNode **head_ref, int k)
{
	if(*head_ref == NULL || k == 0)
		return;

	//快指针向前移动k-1
	SinglyLinkedNode *fast = *head_ref;
	int i = 1;
	while(i < k && fast != NULL)
	{
		fast = fast->next;
		++i;
	}
	//如果快指针为空，说明结点个数小于k
	if(fast == NULL)
		return ;

	SinglyLinkedNode *slow = *head_ref;
	SinglyLinkedNode *prev = NULL;
	while(fast->next != NULL)
	{
		fast = fast->next;
		prev = slow;
		slow = slow->next;
	}
	//如果prev为空，头结点刚好是第k个结点
	if(!prev)
	{
		(*head_ref) = (*head_ref)->next;
	}
	else
	{
		prev->next = slow->next;
	}
	free(slow);
}

void test_deleteLastKth()
{
	SinglyLinkedNode *head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	insertNode(&head, 4);
	insertNode(&head, 5);

	//删除头结点
	deleteLastKth(&head, 5);
	printLinkedList(head);
	
	//删除中间结点
	deleteLastKth(&head, 2);
	printLinkedList(head);
}


SinglyLinkedNode* findMiddleNode(SinglyLinkedNode* head) 
{
	if (!head) return NULL;
	SinglyLinkedNode* slow = head;
	SinglyLinkedNode* fast = head;
	//慢指针走一步，快指针走两步
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


void test_findMiddleNode() 
{
	SinglyLinkedNode* head = NULL;
    	insertNode(&head, 1);
    	insertNode(&head, 2);
    	insertNode(&head, 3);
    	insertNode(&head, 4);
    	insertNode(&head, 5);
    
    	SinglyLinkedNode* middleNode = findMiddleNode(head);
    	printf("%d\n", middleNode->data);
    	printLinkedList(head);
}

//插入新结点到链表头部
void insertNode(SinglyLinkedNode** head_ref, int data) 
{
   	SinglyLinkedNode* new_node = malloc(sizeof(SinglyLinkedNode));
    	new_node->data = data;
    	new_node->next = *head_ref;
    	*head_ref = new_node;
}
//打印链表
void printLinkedList(SinglyLinkedNode* node) 
{
    	printf("--- start ---\n");
    	while (node) 
	{
        	printf("data: %d\n", node->data);
        	node = node->next;
    	}
    	printf("--- end ---\n");
}

//跑测试
void test()
{
	test_reverse();
	//test_checkCircle();
	//test_mergeSortedLinkedList();
	//test_deleteLastKth();
	//test_findMiddleNode();
}














