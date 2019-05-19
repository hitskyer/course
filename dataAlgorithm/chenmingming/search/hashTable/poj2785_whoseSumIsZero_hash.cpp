/**
 * @description: 4个数和为0的方案数，哈希法
 * @author: michael ming
 * @date: 2019/5/9 22:30
 * @modified by: 
 */
#include <iostream>
#include <math.h>
#include <random>
using namespace std;
class BSTNode
{
public:
    int data, count;
    BSTNode *left, *right;
    BSTNode():count(0), left(NULL), right(NULL){}
    BSTNode(const int& d, BSTNode *l = NULL, BSTNode *r = NULL)
    {
        data = d;   count = 0;   left = l;   right = r;
    }
};
class BST
{
private:
    BSTNode* root;
    int nodeLen;
public:
    BST():root(NULL){}
    ~BST()
    {
        clear(root);
        root = NULL;
    }
    void clear(BSTNode* nodeP)
    {
        if(nodeP == NULL)
            return;
        clear(nodeP->left);
        clear(nodeP->right);
        delete nodeP;
    }
    BSTNode* get_root() const {  return root;    }
    bool isEmpty() const {  return root == NULL;    }
    BSTNode* search(const int& d) const
    {
        return search(d, root);
    }
    BSTNode* search(const int& d, BSTNode* p) const
    {
        while(p != NULL)
        {
            if(d == p->data)
                return p;
            else if(d < p->data)
                p = p->left;
            else
                p = p->right;
        }
        return NULL;
    }
    void insert(const int& d)
    {
        BSTNode *p = root, *prev = NULL;
        while(p != NULL)
        {
            prev = p;
            if(d < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if(root == NULL)
            root = new BSTNode(d);
        else if(d < prev->data)
            prev->left = new BSTNode(d);
        else
            prev->right = new BSTNode(d);
    }
};

class linkedHash
{
private:
    BST** ht_bstree; //散列表二叉树数组
    int bucket;  //散列表桶个数
public:
    linkedHash(int m):bucket(m)
    {
        ht_bstree = new BST* [bucket] ();
    }
    ~linkedHash()
    {
        for(int i = 0; i < bucket; ++i)
        {
            ht_bstree[i]->clear(ht_bstree[i]->get_root());
        }
        delete [] ht_bstree;
    }
    int hash(const int &key) const
    {
        return abs(key%bucket);   //留余数法
    }
    int find(const int &x) const
    {
        int i = hash(x);
        BSTNode *p = ht_bstree[i]->search(x);
        if(p)
            return p->count;
    }
    void insert(const int &x)
    {
        int i = hash(x);
        BSTNode *p = ht_bstree[i]->search(x);
        if(p)
            p->count++;
        else
            ht_bstree[i]->insert(x);
    }
};
int a[4001], b[4001], c[4001], d[4001];
int ab[4000*4000+1], cd[4000*4000+1];   //存储a+b，c+d
int main()
{
    linkedHash ht(16001);
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
    for(int i = 0; i < k; ++i)
    {
        result += ht.find(cd[i]);
    }
    cout << result << endl;
    return 0;
}
