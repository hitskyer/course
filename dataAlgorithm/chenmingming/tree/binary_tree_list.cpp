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
    node<T> *left, *right;
    node<T>():left(NULL), right(NULL){}
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
    node<T>* insert(node<T> * nodep, size_t lv, size_t toplv, int data = 1)
    {
        if(lv == 0)
            return NULL;
        else if(nodep == NULL && lv == toplv)
        {
            root = new node<T>();
            nodep = root;
        }
        else
        {
            nodep = new node<T>();
        }
        nodep->data = data;
        nodelen++;
        node<T>* l = insert(nodep->left, lv-1, toplv, 2*data);
        if(l)
            nodep->left = l;    //返回创建好的left节点l，跟父接上
        node<T>* r = insert(nodep->right, lv-1, toplv, 2*data+1);
        if(r)
            nodep->right = r;   //返回创建好的right节点r，跟父接上
        return nodep;
    }
    void preOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        cout << nodep->data << " ";
        preOrderPrint(nodep->left);
        preOrderPrint(nodep->right);
    }
    void inOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        inOrderPrint(nodep->left);
        cout << nodep->data << " ";
        inOrderPrint(nodep->right);
    }
    void postOrderPrint(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        postOrderPrint(nodep->left);
        postOrderPrint(nodep->right);
        cout << nodep->data << " ";
    }
    void levelOrderPrint(node<T> * nodep)    //按层打印
    {
        if (nodep == NULL)
            return;
        postOrderPrint(nodep->left);
        postOrderPrint(nodep->right);
        cout << nodep->data << " ";
    }
    void destory_tree(node<T> * nodep)
    {
        if (nodep == NULL)
            return;
        destory_tree(nodep->left);
        destory_tree(nodep->right);
        delete nodep;
    }
};

int main()
{
    binary_tree<int> btree;
    btree.insert(btree.getRoot(), 3, 3);
    btree.preOrderPrint(btree.getRoot());
    cout << endl << endl;
    btree.inOrderPrint(btree.getRoot());
    cout << endl << endl;
    btree.postOrderPrint(btree.getRoot());
    cout << endl;
    btree.destory_tree(btree.getRoot());
    return 0;
}