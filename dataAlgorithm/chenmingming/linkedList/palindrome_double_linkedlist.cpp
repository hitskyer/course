//
// Created by mingm on 2019/3/16.
//
#include <iostream>
#include <math.h>
using namespace std;
struct Node //节点
{
    char data;
    Node *prev, *next;
    Node():prev(NULL),next(NULL){}
    Node(char &ch):data(ch),prev(NULL),next(NULL){}
    ~Node(){}
};
class SLinkedList   //链表
{
    Node* p_head;
public:
    SLinkedList()   //构造函数
    {
        p_head = new Node;  //带头链表
//        cout << "new 1" << endl;
    }
    ~SLinkedList(){ erase(); }  //析构函数
    void erase()
    {
        Node *del_tempNode, *tempNode;
        del_tempNode = p_head;
        while(del_tempNode != NULL) 
        {
            tempNode = del_tempNode -> next;
            delete del_tempNode;
//            cout << "delete 1" << endl;
            del_tempNode = tempNode;
        }
    }
    void set_head(Node* p)
    {
        p_head = p;
    }
    Node* get_head()
    {
        return p_head;
    }
    Node* get_tail()    //求链表尾节点
    {
        Node* p = p_head;
        if(p_head == NULL)
            return NULL;
        while(p->next)
        {
            p = p->next;
        }
        return p;
    }
    void delHeadSentinel()  //删除链表表头哨兵
    {
        Node* del = p_head;
        p_head = p_head->next;
        p_head->prev = NULL;
        delete del; //删除链表的表头哨兵
//        cout << "delete head 1" << endl;
    }
};

int main()
{
    while(true)
    {
        cout << "-----------------------------------" << endl;
        char ch;
        cin.clear();
        cout << "enter a word, is it a palindrome ?" << endl;
        if((ch = cin.get()) && ch == '\n')
        {
            cout << "empty word !" << endl;
            continue;
        }
        SLinkedList charList;   //链表
        Node* tempNode = charList.get_head();
        while(ch != '\n')   //把单词存进链表charList
        {
            Node* newNode = new Node(ch);
//            cout << "new insert 1" << endl;
            tempNode->next = newNode;   //前面节点后指针指向后面
            newNode->prev = tempNode;   //后面节点前置指针指向前面
            tempNode = newNode;
            ch = cin.get();
        }
        charList.delHeadSentinel();     //链表空表头删除
        Node *front = charList.get_head();  //定义一个从头开始的指针
        Node *back = charList.get_tail();   //定义一个从尾部开始的指针
        bool answer = false;
        if(front == back)    //说明只有一个字符
            answer = true;
        else
        {
            while(front != back)   //比较数据是否相同
            {
                if(front->data != back->data)
                {
                    answer = false;
                    break;
                }
                else
                {
                    answer = true;
                    front = front->next;
                    back = back->prev;
                }
            }
        }
        if(answer)
            cout << "the word is a palindrome." << endl;
        else
            cout << "the word is not a palindrome." << endl;
        char conti;
        cout << "continue to check? (y/n)" << endl;
        cin >> conti;
        cin.get();
        if(conti == 'y' || conti == 'Y')
        {
            continue;
        }
        else
            break;
    }
    return 0;   
}