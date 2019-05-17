/**
 * @description: 二叉查找树
 * @author: michael ming
 * @date: 2019/5/16 23:48
 * @modified by: 
 */
#include <iostream>
#include <random>
#include <time.h>
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
        clear(root);
        root = NULL;
    }
    void clear(BSTNode<T>* nodeP)
    {
        if(nodeP == NULL)
            return;
        if (nodeP == NULL)
            return;
        clear(nodeP->left);
        clear(nodeP->right);
        delete nodeP;
    }
    BSTNode<T>* get_root() const {  return root;    }
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
    void del(T d)
    {
        if(root == NULL)
            return;
        BSTNode<T> *p = root, *pfather = NULL;
        while(p != NULL && p->data != d)
        {
            pfather = p;
            if(d > p->data)
                p = p->right;
            else
                p = p->left;
        }
        if(p == NULL)   //没找到d
            return;
        if(p->left != NULL && p->right != NULL)//要删除的节点有2个子节点
        {
            BSTNode<T> *minP = p->right, *minPFather = p;//找到右子树最小的跟要删的交换
            while(minP->left != NULL)   //右子树最小的肯定在左节点
            {
                minPFather = minP;
                minP = minP->left;
            }
            p->data = minP->data;   //把右子树最小的数付给要删除的节点data
            p = minP;   //minP付给p，删除p
            pfather = minPFather;
        }
        //要删除的是叶节点或者只有1个节点
        BSTNode<T>* child;
        if(p->left != NULL)
            child = p->left;
        else if(p->right != NULL)
            child = p->right;
        else
            child = NULL;
        if(pfather == NULL)//p是根节点
            root = child;
        else if(p == pfather->left)
            pfather->left = child;
        else
            pfather->right = child;
        delete p;
        p = NULL;
    }
    int get_height(BSTNode<T>* nodep)  //递归法, 求左右子树高度，较大的+1
    {
        if(nodep == NULL)
            return 0;
        int leftheight = get_height(nodep->left);
        int rightheight = get_height(nodep->right);
        return max(leftheight, rightheight) + 1;
    }
    void inOrderPrint(BSTNode<T>* nodep)    //二叉查找树用中序打印，是有序的
    {
        if (nodep == NULL)
            return;
        inOrderPrint(nodep->left);
        cout << nodep->data << " ";
        inOrderPrint(nodep->right);
    }
};

int main()
{
    BST<int> intBST;
    srand(time(0));
    for(int i = 0; i < 6; ++i)
    {
        intBST.insert(rand());
    }
    intBST.insert(7);
    if(intBST.search(7))
        cout << *(intBST.search(7)) << endl;
    cout << "BST height: " << intBST.get_height(intBST.get_root()) << endl;
    intBST.inOrderPrint(intBST.get_root());
    cout << "max : " << *(intBST.get_max_data()) << ", min : " << *(intBST.get_min_data()) << endl;
    intBST.del(7);
    intBST.inOrderPrint(intBST.get_root());
    return 0;
}