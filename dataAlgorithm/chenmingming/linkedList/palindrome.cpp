//
// Created by mingm on 2019/3/13.
//
#include <iostream>
#include <math.h>
using namespace std;
struct Node //节点
{
    char data;
    Node* next;
    Node():next(NULL){}
    Node(char &ch):data(ch),next(NULL){}
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
    size_t get_len()    //求链表长度
    {
        size_t len = 0;
        Node* p = p_head;
        while(p)
        {
            len++;
            p = p->next;
        }
        return len;
    }
    void delHeadSentinel()  //删除链表表头哨兵
    {
        Node* del = p_head;
        p_head = p_head->next;
        delete del; //删除链表的表头哨兵
//        cout << "delete head 1" << endl;
    }
    Node* reverse() //链表反转
    {
        if(p_head == NULL || p_head->next == NULL)
            return NULL;
        else
        {
            Node *prevNode, *nextNode, *tempNode;
            prevNode = p_head;
            nextNode = prevNode->next;
            prevNode->next = NULL;
            while(nextNode != NULL)
            {
                tempNode = nextNode->next;
                nextNode->next = prevNode;
                prevNode = nextNode;
                nextNode = tempNode;
            }
            p_head = prevNode;
            return p_head;
        }
    }
    Node* findMiddle()  //查找链表中点
    {
        size_t len = get_len();
        Node* tempNode = p_head;
        size_t n = ceil(double(len)/2);
        for(size_t i = 1; i < n; ++i)
        {
            tempNode = tempNode->next;
        }
        return tempNode;
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
        SLinkedList charList, backHalfOfList;   //链表(前半部分链表)，后半部分链表
        Node* tempNode = charList.get_head();
        while(ch != '\n')   //把单词存进链表charList
        {
            Node* newNode = new Node(ch);
//            cout << "new insert 1" << endl;
            tempNode->next = newNode;
            tempNode = newNode;
            ch = cin.get();
        }
        charList.delHeadSentinel();     //链表表头删除
        backHalfOfList.delHeadSentinel();   //把空表头哨兵节点删除
        Node* endOfFrontList = charList.findMiddle();   //链表的中点是前一半的结束节点
        Node* backListHead = endOfFrontList->next;  //中点的下一个节点是后半部分的开始
        endOfFrontList->next = NULL;    //把前半部分链表断开
        backHalfOfList.set_head(backListHead);  //把后半部分的链表表头地址设置好
        backHalfOfList.reverse();   //后半部分链表反转
        size_t n = backHalfOfList.get_len();    //求后半部分链表长度
        Node *frontList = charList.get_head();  //找到前半部分的开头
        Node *backList = backHalfOfList.get_head(); //后半部分的开头（反转后的）
        bool answer = false;
        if(backList == NULL)    //如果后半部分为空，说明只有一个字符
            answer = true;
        else
        {
            for(size_t i = 0; i < n; ++i)   //比较数据是否相同
            {
                if(frontList->data != backList->data)
                {
                    answer = false;
                    break;
                }
                else
                {
                    answer = true;
                    frontList = frontList->next;
                    backList = backList->next;
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