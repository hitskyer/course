/**
 * @description: poj1577,告知一层层的叶子节点，求二叉查找树
 * @author: michael ming
 * @date: 2019/5/18 23:24
 * @modified by: 
 */
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    char ch;
    node *left, *right;
    node(char &ch):ch(ch),left(NULL),right(NULL){}
};
class BST
{
public:
    node* root;
    BST():root(NULL){}
    void insert(char &ch)
    {
        node *p = root, *prev;
        while(p != NULL)
        {
            prev = p;
            if(ch < p->ch)
                p = p->left;
            else
                p = p->right;
        }
        if(root == NULL)
        {
            root = new node(ch);
            return;
        }
        if(ch < prev->ch)
            prev->left = new node(ch);
        else
            prev->right = new node(ch);
    }
    void del()
    {
        del(root);
    }
    void del(node* p)
    {
        if(p != NULL)
        {
            del(p->left);
            del(p->right);
            delete p;
        }
    }
    void preOrderPrint(node* p)
    {
        if(p != NULL)
        {
            cout << p->ch;
            preOrderPrint(p->left);
            preOrderPrint(p->right);
        }
    }
};
bool saveChToStr(string& str)
{
    bool flag;
    char ch;
    while(cin.get(ch))
    {
        if(ch == '*')
        {
            flag = true;
            break;
        }
        else if(ch == '$')
        {
            flag = false;
            break;
        }
        if(ch == '\n')
            continue;
        str.push_back(ch);
    }
    return flag;
}
int main()
{
    bool flag;
    do
    {
        string str;
        BST tree;
        flag = saveChToStr(str);
        for(int i = str.length()-1; i >= 0; --i)
        {
            tree.insert(str[i]);
        }
        tree.preOrderPrint(tree.root);
        cout << endl;
        tree.del();
    }
    while(flag);
    return 0;
}