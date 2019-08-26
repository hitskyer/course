#include "ACMatch.h"
#include <queue>

AC::AC(void)
{
	root = new ACNode('/');		// 初始化根结点
}

AC::~AC(void)
{
	clear();
}

/****************************************************************
* @brief : 		插入模式串
* @author : 	dyx
* @date : 		2019/8/26 19:20
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
void AC::insert(Iterator begin, Iterator end)
{
	ACNode *cur = root;
	int i;
	for (i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		if (cur->child[index] == 0)		// 子结点为0，则进行新建结点
		{
			cur->child[index] = new ACNode(*begin);		
			++cur->nodeNum;
		}
		cur = cur->child[index];		// 子节点不为0，则继续找子节点的子节点
	}
	cur->isEndingChar = true;
	cur->length = i;		// 表示当前最后子节点的长度
};

void AC::insert(const char* text)
{
	insert(text, text + strlen(text));
}

/****************************************************************
* @brief : 		查找是否含有模式串
* @author : 	dyx
* @date : 		2019/8/26 19:19
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
bool AC::find(Iterator begin, Iterator end)
{
	ACNode* cur = root;
	for (; begin != end; ++begin)
	{
		int index = *begin - 'a';
		if (cur->child[index] == 0)
		{
			return false;
		}
		cur = cur->child[index];
	}
	return cur->isEndingChar;
}

bool AC::find(const char* pattern)
{
	return find(pattern, pattern + strlen(pattern));
}

/****************************************************************
* @brief : 		构建Trie树的失败指针，相当于KMP的next数组
* @author : 	dyx
* @date : 		2019/8/26 19:00
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::buildFailurePointer()
{
	queue<ACNode> que;
	root->pFail = NULL;
	que.push(*root);
	while (!que.empty())
	{
		ACNode p = que.front();
		que.pop();
		for (int i = 0; i < 26; ++i)
		{
			ACNode *pc = p.child[i];
			if (pc == NULL)
			{
				continue;
			}
			if (p == *root)
			{
				pc->pFail = root;
			}
			else
			{
				ACNode *q = p.pFail;
				while (q != NULL)
				{
					ACNode *qc = q->child[pc->data - 'a'];
					if (qc != NULL)
					{
						pc->pFail = qc;
						break;
					}
					q = q->pFail;
				}
				if (q == NULL)
				{
					pc->pFail = root;
				}
			}
			que.push(*pc);
		}
	}
}


/****************************************************************
* @brief : 		匹配模式串
* @author : 	dyx
* @date : 		2019/8/26 19:08
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
template<typename Iterator>
void AC::match(Iterator begin, Iterator end, PosSet *ret)
{
	ACNode* cur = root;
	for (int i = 0; begin != end; ++begin, ++i)
	{
		int index = *begin - 'a';
		while(cur->child[index] == 0 && cur != root)		// 没有孩子且不是根结点，就去找它的失效结点
		{
			cur = cur->pFail;
		}
		cur = cur->child[index];
		if (cur == 0)
		{
			cur = root;
		}
		ACNode *pTemp = cur;
		while(pTemp != root)
		{
			if (pTemp->isEndingChar == true)
			{
				ret->vPos.push_back(i - pTemp->length + 1);
				ret->vLen.push_back(pTemp->length);
			}
			pTemp = pTemp->pFail;
		}
	}
}


/****************************************************************
* @brief : 		匹配过程
* @author : 	dyx
* @date : 		2019/8/26 19:13
* @version : 	ver 1.0
* @inparam :  字符串的首地址，
* @outparam : ret 保存 匹配到的字符串的位置和长度
*****************************************************************/
void AC::match(const char* text, PosSet* ret)
{
	match(text, text + strlen(text), ret);
}


/****************************************************************
* @brief : 		清空结点
* @author : 	dyx
* @date : 		2019/8/26 19:14
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::clear_node(ACNode cur)
{
	for(int i = 0; i < 26; ++i)
	{
		if (cur.child[i] == 0)
		{
			continue;
		}
		clear_node(*cur.child[i]);
		delete cur.child[i];
		cur.child[i] = 0;
		if (--cur.nodeNum == 0)		// 结点个数--
		{
			break;
		}
	}

}

/****************************************************************
* @brief : 		清空all
* @author : 	dyx
* @date : 		2019/8/26 19:15
* @version : 	ver 1.0
* @inparam : 
* @outparam : 
*****************************************************************/
void AC::clear()
{
	clear_node(*root);
	for (int i = 0; i < 26; ++i)
	{
		root->child[i] = 0;
	}
}

/****************************************************************
* @brief : 		打印输出。
* @author : 	dyx
* @date : 		2019/8/26 19:15
* @version : 	ver 1.0
* @inparam :	主串
* @outparam :	如果含有模式串，则输出的主串会带**
*****************************************************************/
void AC::print(const char* text)
{
	string str(text, text + strlen(text));
	PosSet ret;
	match(text, text + strlen(text), &ret);
	for (size_t i = 0; i < ret.vPos.size(); ++i)
	{
		string stemp(ret.vLen[i], '*');		// *的长度
		str = str.replace(ret.vPos[i], ret.vLen[i], stemp.c_str());	//起始位置，替换长度，替换内容
	}
	cout << str.c_str() << endl;
}