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
class comp
{
public:
    bool operator()(htNode* &a, htNode* &b)const
    {
        if(a->weight == b->weight)
            return a->data > b->data;
        return a->weight > b->weight;
    }
};

class HuffmanTree
{
public:
    htNode *root;
    htNode* node[2*N-1];
    priority_queue<htNode*,vector<htNode*>,comp> pri_queue;

    void creatTree(int *w)
    {
        char ch = 'a';
        htNode *left, *right;
        for(int i = 0; i < N; ++i,++ch)
        {
            node[i] = new htNode();
            node[i]->weight = w[i];
            node[i]->data = ch;
            pri_queue.push(node[i]);
        }
        for(int i = N; i < 2*N-1; ++i)
        {
            node[i] = new htNode();
            if(pri_queue.top()->data != '/')
            {
                right = pri_queue.top();
                right->code = '1';
                pri_queue.pop();
                left = pri_queue.top();
                left->code = '0';
                pri_queue.pop();
            }
            else
            {
                left = pri_queue.top();
                left->code = '0';
                pri_queue.pop();
                right = pri_queue.top();
                right->code = '1';
                pri_queue.pop();
            }
            node[i]->weight = left->weight+right->weight;
            node[i]->lchild = left;
            node[i]->rchild = right;
            left->parent = node[i];
            right->parent = node[i];
            pri_queue.push(node[i]);
        }
        root = pri_queue.top();
    }
    void creatHuffCode()
    {
        htNode *parent;
        string huffcode;
        int codelen = 0;
        for(int i = 0; i < N; ++i)
        {
            huffcode = "";
            parent = node[i];
            cout << i+1 << " " << node[i]->data << " 的霍夫曼编码是: ";
            while(parent != root)
            {
                huffcode.push_back(parent->code);
                parent = parent->parent;
            }
            reverse(huffcode.begin(),huffcode.end());
            cout << huffcode << endl;
            codelen += huffcode.size()*node[i]->weight;
        }
        cout << "该字符串的huffman编码长度为: " << codelen << " bits.";
    }
};

int main()
{
    HuffmanTree huff;
    cout << "请输入某字符串中" << N << "个字母abc...的权值（频率）：" << endl;
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