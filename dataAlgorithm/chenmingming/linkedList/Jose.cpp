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
        p_head = new NodeType;  //带空头的链表
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
        tempNode->next = newp;   //不断地往尾部（尾部哨兵之前）插入节点
        tempNode = newp;
    }
    tempNode->next = p_head->next;  //断开空头哨兵
    delete p_head;  //释放哨兵节点
    p_head = tempNode->next;    //头结点指向第一个节点
}
void Jose::print()
{
    int m,i;
    NodeType *del = p_head, *tempNode;
    cout << "\n enter value m(m>=2):";
    cin >> m;
    cout << "\n start:" << endl;
    while(del->next != del) //链表节点个数不为1
    {
        for(i = 1; i < m; ++i)  //del往后移动m位
        {
            tempNode = del;
            del = del->next;
        }
        cout << del->num << " " << del->name << endl;
        tempNode->next = del->next; //断开del节点
        delete del; //释放del节点
        del = tempNode->next;
    }
    cout << del->num << " " << del->name << endl;
    delete del; //链表只剩一个节点直接删除
}

int main()
{
    Jose gameList;
    gameList.creat();
    gameList.print();
    cout << "press any key to exit!" ;
    cin.get();
    return 0;
}