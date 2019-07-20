#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include <string.h>
using namespace std;

typedef int VertexType;		// 顶点类型
typedef int EdgeType;			// 边上的权值的类型
#define MAXVEX 20				// 顶点数
#define INFINITY 65535			// 无穷大数
/*
* 邻接链表
*/

typedef struct Node
{
	VertexType data;
	//EdgeType weight;		// 如果为有向图，则添加权重，否则不用添加权重
}Node;

class NoGraph
{
public:
	typedef list<Node> *lst;
	lst *pHeadArr;
	int vexNum;
	int adjNum;
	NoGraph()
	{
		pHeadArr = new lst[MAXVEX];
		memset(pHeadArr, 0, MAXVEX * sizeof(Node));		// 初始化为无穷大
	}
	~NoGraph()
	{
		for(int i = 0; i < MAXVEX; ++i)
		{
			delete pHeadArr[i];
			pHeadArr[i] = NULL;
		}
		delete [] pHeadArr;
		pHeadArr = NULL;
	}
	void creatGraph(const int &vexNum, const int &adjNum)
	{
		int index;
		Node node;
		// 将所有顶点放置在首位
		for(int i = 0; i < vexNum; ++i)
		{
			cout << "请输入顶点索引（即数据，index = data）"<< endl;
			cin >> index;
			node.data = index;
			if(pHeadArr[index] == NULL)
			{
				pHeadArr[index] = new list<Node>();
			}
			pHeadArr[index]->push_back(node);
		}
		// 输入每一个结点关联的结点
		for(int j = 0; j < adjNum; ++j)
		{
			cout <<"输入边的两个顶点，index1,index2（假设：index=data）" << endl;
			int index1, index2;
			cin >> index1 >> index2;
			Node node1, node2;
			node1.data = index1;
			node2.data = index2;
			pHeadArr[index1]->push_back(node2);
			pHeadArr[index2]->push_back(node1);
		}
		cout << "******* 输入完成 *******" << endl;
	}

	// 打印测试
	void print(const int vexNum)
	{
		for(int index = 0; index < vexNum; ++index)
		{
			list<Node>::iterator it = pHeadArr[index]->begin();
			for(; it != pHeadArr[index]->end(); ++it)
				cout << it->data << " -- " ;
			cout << endl;
		}
	}
	// 查找二度好友
	void secondFriend(const int &index, const int vexNum)
	{
		int *arr = new int[vexNum];
		memset(arr, -1, vexNum);
		queue<int> sedfrd;
		if(&pHeadArr[index] != NULL)
		{
			list<Node>::iterator it1 = pHeadArr[index]->begin();
			for(; it1 != pHeadArr[index]->end(); ++it1)
			{
				arr[it1->data] = it1->data;		// 它本身和它的一度好友。
			}
			for(int i = 1; i < vexNum; ++i)
			{
				if(arr[i] == -1)
					continue;
				list<Node>::iterator it2 = pHeadArr[arr[i]]->begin();
				for(; it2 != pHeadArr[arr[i]]->end(); ++it2)
				{
					// 此循环，判断二度好友是否是一度好友。
					if(it2->data != arr[it2->data])
					{
						sedfrd.push(it2->data);
						arr[it2->data] = it2->data;
					}
				}
			}
			while(!sedfrd.empty())
			{
				cout << sedfrd.front() << endl;
				sedfrd.pop();
			}
		}
	}
};
/* 图连接如下：
0-1-2--3
|   |  |
4----  |
--------
*/

/*
直接复制以下数值，进行测试。
0 1 2 3 4 
0 1
1 2
2 3
2 4
3 4
4 0
*/

int main()
{
	NoGraph *G = new NoGraph();
	const int a = 5;		// 顶点数
	const int b = 6;		// 边数
	G->creatGraph(a, b);	// 创建邻接链图
	cout << "打印邻接链图" << endl;
	G->print(a);
	cout << "打印0的二度好友" << endl;
	G->secondFriend(0, a);		// 查找并打印0的二度好友
	cout << "打印1的二度好友" << endl;
	G->secondFriend(1, a);		// 查找并打印0的二度好友
//	system("pause");
	return 0;
}


