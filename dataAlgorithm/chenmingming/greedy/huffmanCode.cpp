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

#define N 6		//字符集字符种数
using namespace std;
struct htNode//霍夫曼树节点
{
    char data;//数据类型
    char code;//数据存放的节点编码
    unsigned int weight;//数据权值
    htNode *parent, *lchild, *rchild;//连接节点指针
    htNode():data('/'),code('\0'),weight(0)
    {
        parent = lchild = rchild = NULL;
    }
};
class comp//优先队列比较函数
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
    htNode *root;//根节点指针
    htNode* node[2*N-1];//N个字符，霍夫曼树节点个数2*N-1
    priority_queue<htNode*,vector<htNode*>,comp> pri_queue;
    //优先队列中存放类指针时，第三个参数应该另写一个comp类，类内写operator()
    void creatTree_outputCode(int *w)
    {
        char ch = 'a';
        htNode *left, *right;
        for(int i = 0; i < N; ++i,++ch)
        {//生成前N个字符节点，输入权重，和字符信息
        	//并放入优先队列（权值小的优先）
            node[i] = new htNode();
            node[i]->weight = w[i];
            node[i]->data = ch;
            pri_queue.push(node[i]);
        }
        for(int i = N; i < 2*N-1; ++i)
        {//后面新生成的N-1个节点
            node[i] = new htNode();
            if(pri_queue.top()->data != '/')
            {//队首的节点不是新生成的，队首放右边
                right = pri_queue.top();
                right->code = '1';//右边节点编码1
                pri_queue.pop();
                left = pri_queue.top();
                left->code = '0';//左边节点编码0
                pri_queue.pop();//左右节点出队
            }
            else
            {//队首是新生成的节点，放左边
            	//（以上if-else保证新生成的节点总在左边）
                left = pri_queue.top();
                left->code = '0';
                pri_queue.pop();
                right = pri_queue.top();
                right->code = '1';
                pri_queue.pop();//左右节点出队
            }
            //新节点权值、上下连接指针对接
            node[i]->weight = left->weight+right->weight;
            node[i]->lchild = left;
            node[i]->rchild = right;
            left->parent = node[i];
            right->parent = node[i];
            pri_queue.push(node[i]);//新生成的节点入队
        }
        root = pri_queue.top();//最后还剩一个节点，是根节点
        creatHuffCode();
        for(int i = 0; i < 2*N-1; ++i)//释放资源
        {
        	delete node[i];
        }
    }
    void creatHuffCode()
    {
        htNode *parent;
        string huffcode;//霍夫曼编码
        int codelen = 0;//输入的字符串编码后的总长度bits
        for(int i = 0; i < N; ++i)//遍历前N个字符节点，求其编码
        {
            huffcode = "";
            parent = node[i];//从自己（叶子节点）开始向上找父节点，直到root
            cout << i+1 << " " << node[i]->data << " 的霍夫曼编码是: ";
            while(parent != root)//
            {
                huffcode.push_back(parent->code);//将路径中的编码汇成字符串
                parent = parent->parent;
            }
            reverse(huffcode.begin(),huffcode.end());//将最终的编码反转一下
            cout << huffcode << endl;
            codelen += huffcode.size()*node[i]->weight;//单字符code长*出现次数
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
        cin >> w[i];//输入权值
    }
    huff.creatTree_outputCode(w);//将权值传入并生成Huffman树;生成霍夫曼编码，打印出来
    return 0;
}