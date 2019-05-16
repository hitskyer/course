/**
 * @description: 二叉查找树
 * @author: michael ming
 * @date: 2019/5/16 23:48
 * @modified by: 
 */
#include <iostream>
using namespace std;
template <class T>
class BSTNode
{
public:
    T data;
    BSTNode<T> *left, *right;
    BSTNode():left(NULL), right(NULL){}
    BSTNode(const T& d, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL)
    {
        data = d;   left = l;   right = r;
    }
};
template <class T>
class BST
{
private:
    BSTNode<T>* root;
    int nodeLen;
public:
    BST():root(NULL){}
    ~BST()
    {
//        clear(root);
        root = NULL;
    }
    void clear(BSTNode<T>* nodeP);
    bool isEmpty() const {  return root == NULL;    }
    T* search(const T& d) const
    {
        return search(d, root);
    }
    T* search(const T& d, BSTNode<T>* p) const
    {
        while(p != NULL)
        {
            if(d == p->data)
                return &(p->data);
            else if(d < p->data)
                p = p->left;
            else
                p = p->right;
        }
        return 0;
    }
    T* get_max_data()
    {
        if(root == NULL)
            return NULL;
        BSTNode<T>* temp = root;
        while(temp->right != NULL)
            temp = temp->right;
        return &temp->data;
    }
    T* get_min_data()
    {
        if(root == NULL)
            return NULL;
        BSTNode<T>* temp = root;
        while(temp->left != NULL)
            temp = temp->left;
        return &temp->data;
    }
    void insert(const T& d)
    {
        BSTNode<T> *p = root, *prev = NULL;
        while(p != NULL)
        {
            prev = p;
            if(d < p->data)
                p = p->left;
            else
                p = p->right;
        }
        if(root == NULL)
            root = new BSTNode<T>(d);
        else if(d < prev->data)
            prev->left = new BSTNode<T>(d);
        else
            prev->right = new BSTNode<T>(d);
    }
};

int main()
{
    BST<int> intBST;
    return 0;
}