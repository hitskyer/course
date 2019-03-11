#include <iostream>
using namespace std;
struct node
{
    char data;
    node* next;
    node():data('\0'),next(NULL){}
    node(char ch):data(ch),next(NULL){}
    ~node(){ }
};
struct list
{
    node* p_head;
    size_t listLength;
    list():p_head(NULL),listLength(0){}
    ~list(){ eraseAll();}
    void eraseAll()
    {
        if(p_head)
        {
            node *delnode = p_head, *tempnode = p_head;
            while(tempnode->next != NULL)
            {
                tempnode = delnode->next;
                delete delnode;
                delnode = tempnode;
            }
            listLength = 0;
        }

    }
    void push_front(char &ch)
    {
        node *tempNode = new node(ch);
        listLength++;
        tempNode->next = p_head;
        p_head = tempNode;
    }
    node* find(char& ch)
    {
        node* temp = p_head;
        if(p_head)
        {
            while(temp != NULL && temp->data != ch)
            {
                temp = temp->next;
            }
        } else
        {
            temp = NULL;
        }
        return temp;
    }
    void delNode(char &ch)
    {
        node* tempnode = p_head, *delnode;
        delnode = find(ch);
        if(delnode && delnode != p_head)
        {
            while(tempnode->next != delnode)
            {
                tempnode = tempnode->next;
            }
            tempnode->next = delnode->next;
            delete delnode;
            listLength--;
        }
        else
        {
            if(delnode == p_head && delnode)
            {
                p_head = delnode->next;
                delete delnode;
                listLength--;
            }
        }
    }
};

int main()
{
    list beds,waitlist; //床位队列，等待队列
    node *tempnode = NULL;
    size_t numsofbed, walkedaway = 0;
    char ch;
    while(cin >> numsofbed && numsofbed)    //输入床位数，且不为0
    {
        cin.get();  //拿掉空格
        while(cin.get(ch) && ch != '\n')    //输入每个人
        {
            tempnode = beds.find(ch);   //去床位队列查找人
            if(tempnode)    //找到了这个人，床位上这个人离店
            {
                beds.delNode(ch);
            }
            else    //没有在床位上找到该人，则该人需要住店
            {
                if(beds.listLength < numsofbed) //床位有空余
                {
                    beds.push_front(ch);    //这个人住下
                }
                else    //床位满了
                {
                    if(waitlist.find(ch))   //这个人已经在等待队列里
                    {
                        waitlist.delNode(ch);   //等不了了，离开等待队列
                        walkedaway++;
                    }
                    else    //这个人不在等待队列里，可以等待
                    {
                        waitlist.push_front(ch);
                    }
                }
            }
        }
        if(walkedaway == 0)
        {
            cout << "All customers tanned successfully." << endl;
        }
        else
        {
            cout << walkedaway << " customer(s) walked away." << endl;
        }
        beds.eraseAll();
        waitlist.eraseAll();
        walkedaway = 0;
        numsofbed = 0;
    }
    return 0;
}