/**
 * @description: 二叉树,数组实现
 * @author: michael ming
 * @date: 2019/5/11 11:44
 * @modified by: 
 */
#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    node<T>():data(NULL){}
};
template <class T>
class binary_tree
{
private:
    int size;
    size_t tree_arrlen;
    node<T>* tree;
public:
    binary_tree(int len = 20):size(len),tree_arrlen(0)
    {
        tree = new node<T> [size];
    }
    ~binary_tree()
    {
        delete [] tree;
    }
    void insert(T &data)
    {
        if(tree_arrlen < size)
        tree[++tree_arrlen].data = data;
    }
    void preOrderPrint(size_t index = 1)
    {
        if(tree_arrlen < 1 || index > tree_arrlen)
            return;
        cout << tree[index].data << " ";
        preOrderPrint(index*2);
        preOrderPrint(index*2+1);
    }
    void inOrderPrint(size_t index = 1)
    {
        if(tree_arrlen < 1 || index > tree_arrlen)
            return;
        inOrderPrint(index*2);
        cout << tree[index].data << " ";
        inOrderPrint(index*2+1);
    }
    void postOrderPrint(size_t index = 1)
    {
        if(tree_arrlen < 1 || index > tree_arrlen)
            return;
        postOrderPrint(index*2);
        postOrderPrint(index*2+1);
        cout << tree[index].data << " ";
    }
};

int main()
{
    binary_tree<int> btree;
    for(int i = 1; i < 8; ++i)
        btree.insert(i);
    btree.preOrderPrint();
    cout << endl;
    btree.inOrderPrint();
    cout << endl;
    btree.postOrderPrint();
    return 0;
}