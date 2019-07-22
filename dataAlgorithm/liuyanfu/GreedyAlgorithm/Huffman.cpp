#include <iostream>
#include "Huffman.h"
using namespace std;


void Great_Huffman(HTNode* HT, UINT n)
{
	UINT k, j;
	UINT w;
	BYTE ch;
	UINT m = 2*n -1;
	//输入n个字符及其权值
	for(k = 0; k < n; ++k)
	{
		cout << "Input char and weight: ";
		cin >> ch >> w;
		HT[k].character = ch;
		HT[k].weight = w;
		HT[k].Parent = HT[k].lChild = HT[k].rChild = 0; //初始化
	}

	//初始化用于连接子叶的n-1个节点
	for(k = n; k < m; ++k)
	{
		HT[k].character = '\0';
		HT[k].weight = 0;
		HT[k].Parent = HT[k].lChild = HT[k].rChild = 0;
	}

	//构建赫夫曼树
	UINT Min_w1, Min_w2; //用来存储权值最小的两个值
	UINT p1, p2;			//两个权值对应的下标
	//外层循环用于构造新的节点
	for(k = n; k < m; ++k)
	{
		Min_w1 = Min_w2 = MAXINT;
		p1 = p2 = 0; //初始化下标
		//内层循环用于寻找构造新节点的两个最小权节点
		for(j = 0; j < k; ++j)
		{
			if(HT[j].Parent == 0) //如果这个子叶尚未合并
			{
				if(HT[j].weight < Min_w1)//更新最小权
				{
					Min_w2 = Min_w1;
					p2 = p1;
					Min_w1 = HT[j].weight;
					p1 = j;
				}
				else if(HT[j].weight < Min_w2)//更改次小权
				{
					Min_w2 = HT[j].weight;
					p2 = j;
				}
			}
		}
		HT[p1].Parent = HT[p2].Parent = k;
		HT[k].lChild = p1;
		HT[k].rChild = p2;
		HT[k].weight = HT[p1].weight + HT[p2].weight;
	}
}

//将字符的出现率作为节点的权值，进而保证出现频率高的的字符使用的二进制位的个数少，
//而出现频率低的字符使用的二进制位数多
void Huffman_Code(HTNode* HT, UINT n)
{
	UINT k;
	int sp, fp;
	char* HF = new char[n];
	int p;
	for(k = 0; k < n; ++k)
	{
		sp = n - 1;
		p = k;
		fp = HT[k].Parent;
		//从叶子搜索直到根节点
		while(fp != 0)
		{
			if(HT[fp].lChild == p) //如果当前节点是左子树
				HF[sp] = '0';
			else
				HF[sp] = '1';
			sp--;
			p = fp;
			fp = HT[fp].Parent;
		}
		//显示编码
		cout << HT[k].character << ": ";
		sp++;
		while(sp < n)
		{
			cout << HF[sp];
			sp++;
		}
		cout << endl;
	}
}

int main()
{
	HTNode HT[7]; 
	Great_Huffman(HT, 4);
	Huffman_Code(HT, 4);
	return 0;
}