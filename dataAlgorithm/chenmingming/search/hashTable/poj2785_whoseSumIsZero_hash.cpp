/**
 * @description: 4个数和为0的方案数，哈希法
 * @author: michael ming
 * @date: 2019/5/9 22:30
 * @modified by: 
 */
#include <iostream>
#include <math.h>
using namespace std;
struct linkedNode   //链表节点
{
    pair<int, int> data;
    linkedNode *next;
    linkedNode():next(NULL), data(make_pair(0,0)){}
};
class linkedList    //链表
{
public:
    linkedNode *head;
    linkedList()
    {
        head = new linkedNode();  //表头哨兵
    }
    ~linkedList()
    {
        delete head;
    }
};
class linkedHash
{
private:
    linkedList *htList; //散列表链表数组
    int bucket;  //散列表桶个数
public:
    linkedHash(int m):bucket(m)
    {
        htList = new linkedList [bucket] ();
    }
    ~linkedHash()
    {
        for(int i = 0; i < bucket; ++i)
        {
            linkedNode *p = htList[i].head->next, *q = p;
            while(q != NULL)
            {
                p = q;
                q = q->next;
                delete p;
            }
        }
        delete [] htList;
    }
    int hash(const int &key) const
    {
        return abs((key%bucket + key/bucket)%bucket);   //留余数法
    }
    linkedNode* find(const int &x) const
    {
        int i = hash(x);
        linkedNode *p = htList[i].head->next, *q = htList[i].head;
        while(p && p->data.first != x)
        {
            q = p;
            p = p->next;
        }
        return q;   //返回找到元素的前一个节点，或者没有找到,返回最后一个元素
    }
    linkedNode* insert(const int &x)
    {
        int i = hash(x);
        linkedNode *p = htList[i].head, *q = p;
        while(q != NULL)
        {
            p = q;
            q = q->next;
            if(q && q->data.first == x)
            {
                q->data.second++;
                return q;
            }
        }
        p->next = new linkedNode();
        p->next->data.first = x;
        p->next->data.second++;
        return p->next;
    }
};
int a[4001], b[4001], c[4001], d[4001];
int ab[4000*4000+1], cd[4000*4000+1];   //存储a+b，c+d
int main()
{
    linkedHash ht(16000057);
    int line, k=0;
    cin >> line;
    for(int i = 0; i < line; ++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    for(int i = 0; i < line; ++i)
    {
        for(int j = 0; j < line; ++j)
        {
            ab[k] = a[i]+b[j];
            ht.insert(ab[k]);
            cd[k++] = -(c[i]+d[j]);
        }
    }
    int result = 0;
    linkedNode* p;
    for(int i = 0; i < k; ++i)
    {
        p = ht.find(cd[i])->next;
        if(p && p->data.first == cd[i])
            result += p->data.second;
    }
    cout << result << endl;
    return 0;
}
