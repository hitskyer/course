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
                listLength--;
                delnode = tempnode;
            }
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
            while(temp->data != ch)
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
        if(delnode)
        {
            while(tempnode->next != delnode)
            {
                tempnode = tempnode->next;
            }
            tempnode->next = delnode->next;
            delete delnode;
            listLength--;
        }
    }
};

int main()
{
    list beds,waitlist;
    node *tempnode = NULL;
    size_t numsofbed, walkedaway = 0;
    char ch;
    cin >> numsofbed;
    while(cin >> ch)
    {
        tempnode = beds.find(ch);
        if(tempnode)
        {
            beds.delNode(ch);
        }
        else
        {
            if(beds.listLength < numsofbed)
            {
                beds.push_front(ch);
            }
            else
            {
                if(waitlist.find(ch))
                {
                    waitlist.delNode(ch);
                    walkedaway++;
                }
                else
                {
                    waitlist.push_front(ch);
                }
            }
        }
    }
    if(walkedaway = 0)
    {
        cout << "All customers tanned successfully." << endl;
    }
    else
    {
        cout << walkedaway << " customer(s) walked away." << endl;
    }

    return 0;
}