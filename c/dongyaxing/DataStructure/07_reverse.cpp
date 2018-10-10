#include<iostream>

using namespace std;

//结点构造
struct NODE
{
	int data;
	struct NODE* next;
};

//添加元素--压栈
void push(NODE** head, int dat)
{
	struct NODE* new_node = new NODE();
	new_node->data = dat;
	new_node->next = *head;
	*head = new_node;
}

//添加元素--添加
void add(NODE** head, int dat)
{
	struct NODE* new_node = new NODE();
	new_node->data = dat;
	new_node->next = NULL;
	if(*head != NULL)
	{
		struct NODE* temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
	else
	{
		*head = new_node;
	}
}

//反转列表
void reverse(NODE** head)
{
	struct NODE* pre = NULL;
	struct NODE* cur = *head;
	struct NODE* nxt;
	while(cur != NULL)
	{
		//反转指针
		nxt = cur->next;
		cur->next = pre;
		//移动指针
		pre = cur;
		cur = nxt;
	}
	*head = pre;
}

//反转列表--复制原表返回反转表
NODE* reverse(NODE* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	NODE* new_head = reverse(head->next);
	//反转指针
	head->next->next = head;
	head->next = NULL;
	return new_head;
}

//打印队列
void print(NODE* head)
{
	NODE* temp = head;
	while(temp != NULL)
	{
		std::cout<<temp->data<<std::endl;
		temp = temp->next;
	}
}

int main()
{
	struct NODE* n= NULL;
	add(&n, 1);
	add(&n, 2);
	add(&n, 3);
	n = reverse(n);
	print(n);
	
	return 0;
}
