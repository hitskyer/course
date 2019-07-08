#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <memory.h>
#define N 6
typedef unsigned int UINT;
using namespace std;

typedef struct HFMnode
{
	char data;
	char code;
	UINT weight;
	HFMnode *parent, *lp, *rp;
	HFMnode()
	{
		data = '/';
		code = '0';
		weight = 0;
		parent = lp = rp = NULL;
	}
}HFMnode;

class comp
{
public:
	bool operator()(HFMnode* &a, HFMnode* &b)const
	{
		if (a->weight == b->weight)
		{
			return a->data > b->data;
		}
		return a->weight > b->weight;
	}
};

class HuffmanTree
{
public:
	HFMnode *root;		// 根结点指针
	HFMnode *node[2*N-1];	// N个字符，霍夫曼树结点个数2*n-1
	priority_queue<HFMnode*, vector<HFMnode*>, comp> pri_queue;	// 插入的同时，进行排序。按照权重从大到小
	// 优先队列中存放类指针时，第三个参数应该另写一个comp类，类内写operator()
	void creatTree_outputCode(int *w)
	{
		char ch = 'a';
		HFMnode *left, *right;
		for (int i = 0; i < N; ++i, ++ch)		// 把abcdef存入，且权重为输入对象数组。
		{
			// 生成钱N个字符节点，输入权重和字符信息
			node[i] = new HFMnode();
			node[i]->weight = w[i];
			node[i]->data = ch;
			pri_queue.push(node[i]);
		}

		for (int i = N; i < 2*N-1; ++i)
		{
			// 后面新生成的N-1个节点
			node[i] = new HFMnode();
			if (pri_queue.top()->data != '/')
			{
				//队首节点不是新生成的，队首放右边
				right = pri_queue.top();
				right->code = '1';
				pri_queue.pop();
				left = pri_queue.top();
				left->code = '0';
				pri_queue.pop();
			}
			else
			{
				//队首节点是新生成的，队首放左边
				left = pri_queue.top();
				left->code = '0';
				pri_queue.pop();
				right = pri_queue.top();
				right->code = '1';
				pri_queue.pop();
			}
			// 新节点权值、上下连接指针对接
			node[i]->weight = left->weight + right->weight;
			node[i]->lp = left;
			node[i]->rp = right;
			left->parent = node[i];
			right->parent = node[i];
			pri_queue.push(node[i]);	// 新生成的结点cherub队列
		}
		root = pri_queue.top();		// 最后还剩一个结点，是根节点
		creatHuffCode();
		for (int i = 0; i < 2*N-1; ++i)
		{
			delete node[i];
		}
	}

	void creatHuffCode()
	{
		HFMnode* parent;
		string huffCode;	// 霍夫曼编码
		int codelen = 0;	// 输入的字符串编码后的总长度bits
		for (int i = 0; i < N; ++i)
		{
			huffCode = "";
			parent = node[i];	// 从自己（叶子节点）开始向上找父结点，直到root
			cout << i + 1 << " " << node[i]->data << " The Huffman encoding is : ";
			while(parent != root)
			{
				//huffCode.push_back(parent->code);	// 将路径中的编码汇成字符串
				huffCode+=parent->code;
				parent = parent->parent;
			}
			reverse(huffCode.begin(), huffCode.end());	// 将最终的编码翻转一下
			cout << huffCode << endl;
			codelen += huffCode.size()*node[i]->weight;		// 单字节code长*出现的次数
		}
		cout << "The Huffman encoding length of the string is " << codelen << " bits." << endl;
	}
};

int main()
{
	HuffmanTree huff;
	cout << "Please enter the weight of the character , total " << N << " character: " << endl;
	int w[N];
	for (int i = 0; i < N; ++i)
	{
		cout << "No. " << i+1 << " ";
		cin >> w[i];
	}
	huff.creatTree_outputCode(w);
//	system("pause");
	return 0;
}
