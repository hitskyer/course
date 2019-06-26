/**
 * @description: 红黑树
 * @author: michael ming
 * @date: 2019/5/18 16:59
 * @modified by: 
 */
#include <iostream>
using namespace std;
enum color
{
    RED, BLACK,
};
template <class K, class V>
struct RBTNode
{
    int col;//颜色
    K key;
    V value;
    RBTNode<K,V> *left, *right, *parent;
    RBTNode(const K& key, const V& value):key(key),value(value)
    {
        col = RED;
        left = right = parent = NULL;
    }
};
template <class K, class V>
class RBT
{
    typedef RBTNode<K,V> node;
private:
    node* root;
public:
    RBT():root(NULL){}
    bool insert(const K& key, const V& value)
    {
        if(root == NULL)
        {
            root = new node(key, value);
            root->col = BLACK;
        }
        node *father = NULL, *cur = root;
        while(cur != NULL)
        {
            if(cur->key > key)
            {
                father = cur;
                cur = cur->left;
            }
            else if(cur->key <= key)
            {
                father = cur;
                cur = cur->right;
            }
//            else
//                return false;
        }
        if(father->key > key)   //选择左右插入
        {
            cur = new node(key, value);
            father->left = cur;
            cur->parent = father;
        }
        else
        {
            cur = new node(key, value);
            father->right = cur;
            cur->parent = father;
        }
        //插入后调整
        node *grandfather, *uncle;
        while(cur != root && father->col == RED)
        {
            grandfather = father->parent;
            uncle = NULL;
            //左边的情况
            if(father == grandfather->left)
            {
                //情况1
                uncle = grandfather->right;
                if(uncle && uncle->col == RED)
                {
                    //1.不需要旋转
                    if(cur == father->left)
                    {
                        grandfather->col = RED;
                        father->col = BLACK;
                        uncle->col = BLACK;
                        cur = grandfather;
                        father = cur->parent;
                    }
                    //2.需要旋转
                    else if(cur == father->right)
                    {
                        rotateL(father);
                        grandfather->col = RED;
                        ???
                    }
                }
            }
        }
    }
};