/**
 * @description: 贪心应用--霍夫曼编码
 * @author: michael ming
 * @date: 2019/6/30 23:53
 * @modified by: 
 */
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <memory.h>

#define N 6
using namespace std;
struct htNode
{
    char data;
    char code;
    unsigned int weight;
    htNode *parent, *lchild, *rchild;
    htNode():data('/'),code('\0'),weight(0)
    {
        parent = lchild = rchild = NULL;
    }
    bool operator<(const htNode &a)const
    {
        if(weight == a.weight)
            return data > a.data;
        return weight > a.weight;
    }
    htNode& operator=(const htNode &a)
    {
        data = a.data;
        code = a.code;
        weight = a.weight;
        parent = a.parent;
        lchild = a.lchild;
        rchild = a.rchild;
        return *this;
    }
};
class HuffmanTree
{
public:
    htNode root;
    htNode node[2*N-1];
    priority_queue<htNode,vector<htNode>> pri_queue;
    void creatTree(int *w)
    {
        char ch = 'a';
        htNode left, right;
        for(int i = 0; i < N; ++i,++ch)
        {
            node[i].weight = w[i];
            node[i].data = ch;
            pri_queue.push(node[i]);
        }
        for(int i = N; i < 2*N-1; ++i)
        {
            left = pri_queue.top();
            left.code = '0';
            pri_queue.pop();
            right = pri_queue.top();
            right.code = '1';
            pri_queue.pop();
            node[i].weight = left.weight+right.weight;
            node[i].lchild = &left;
            node[i].rchild = &right;
            left.parent = &node[i];
            right.parent = &node[i];
            pri_queue.push(node[i]);
        }
        root = pri_queue.top();
    }
    void creatHuffCode()
    {
        queue<htNode*> nodeQueue;
        htNode* leafNode[N];
        memset(leafNode,NULL,N* sizeof(htNode*));
        nodeQueue.push(&root);
        htNode *left, *right, *parent;
        int i = 0;
        string huffcode;
        while(!nodeQueue.empty())//按层遍历，获取叶子节点
        {
            left = nodeQueue.front()->lchild;
            right = nodeQueue.front()->rchild;
            if(left && right)//霍夫曼树左右节点成对出现
            {
                nodeQueue.push(left);
                nodeQueue.push(right);
            }
            else
            {
                leafNode[i++] = nodeQueue.front();//存储叶子节点
            }
            nodeQueue.pop();
        }
        for(i = 0; i < N; ++i)
        {
            huffcode = "";
            parent = leafNode[i];
            cout << i+1 << " " << leafNode[i]->data << " 的霍夫曼编码是: ";
            while(parent != &root)
            {
                huffcode.push_back(parent->code);
            }
            reverse(huffcode.begin(),huffcode.end());
            cout << huffcode << endl;
        }
    }
};

int main()
{
    HuffmanTree huff;
    cout << "请输入依次" << N << "个字母abc...的权值（频率）：" << endl;
    int w[N];//权重
    for(int i = 0; i < N; ++i)
    {
        cout << i+1 << " ";
        cin >> w[i];
    }
    huff.creatTree(w);
    huff.creatHuffCode();
    return 0;
}