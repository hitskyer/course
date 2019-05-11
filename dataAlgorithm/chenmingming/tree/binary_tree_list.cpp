/**
 * @description: 二叉树，链表实现
 * @author: michael ming
 * @date: 2019/5/11 18:03
 * @modified by: 
 */
#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T> *father, *left, *right;
    node<T>():father(NULL), left(NULL), right(NULL){}
};
template <class T>
class binary_tree
{
private:
    int nodelen;
    node<T> *root;
public:
    binary_tree():nodelen(0), root(NULL){}
    node<T>* getRoot()const
    {
        return root;
    }
    void insert(T &data)
    {
        if (root == NULL)
        {
            root = new node<T>();
            root->data = data;
            nodelen++;
        }
        else
        {
            if(th)
        }
    }
    void preOrderPrint(size_t index = 1)
    {
        if (tree_arrlen < 1 || index > tree_arrlen)
            return;
        cout << tree[index].data << " ";
        preOrderPrint(index * 2);
        preOrderPrint(index * 2 + 1);
    }
};