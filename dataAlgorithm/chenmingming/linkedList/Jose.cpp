#include <iostream>
using namespace std;

struct NodeType
{
    int num;
    char name[20];
    NodeType* next;
};
class Jose
{
private:
    NodeType* p_head;
public:
    Jose()
    {
        p_head = new NodeType;
        p_head->next = p_head;  //空的循环链表
    }
    ~Jose(){}
    void creat();
    void print();
};
void Jose::creat()
{
    int i = 0, n;
    NodeType *newp, *tempNode;
    tempNode = p_head;
    cout << "\n enter total nums of people: ";
    cin >> n;
    for(i = 0; i < n; ++i)
    {
        newp = new NodeType;
        newp->num = i+1;
        cout << "\n enter name: ";
        cin >> newp->name;
        newp->next = p_head;    //此处p_head为尾部哨兵
        tempNode->next = newp;   //不断地往尾部插入节点
        tempNode = newp;
    }
    tempNode->next = p_head->next;
    delete p_head;  //删除哨兵节点
    p_head = tempNode->next;    //头结点指向第一个节点
}
void Jose::print()
{
    int m,i;
    NodeType *del = p_head, *tempNode;
    cout << "\n enter value m(m>=2):";
    cin >> m;
    cout << "\n start:" << endl;
    while(del->next != del)
    {
        for(i = 1; i < m; ++i)
        {
            tempNode = del;
            del = del->next;
        }
        cout << del->num << " " << del->name << endl;
        tempNode->next = del->next;
        delete del;
        del = tempNode->next;
    }
    cout << del->num << " " << del->name << endl;
    delete del;
}

int main()
{
    Jose game;
    game.creat();
    game.print();
    cout << "press any key to exit!" ;
    cin.get();
    return 0;
}