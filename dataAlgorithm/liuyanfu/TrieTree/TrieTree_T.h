#ifndef _TEMPLATE_TRIETREE_H
#define _TEMPLATE_TRIETREE_H

template<int Size> //代表字符表的大小
struct trie_node
{
	bool isEndingChar;
	int nodeNum;
	char data;
	trie_node* child[Size];

	trie_node(const char ch):isEndingChar(false), nodeNum(0)
	{
		data = ch;
		memset(child, 0, sizeof(child));
	}
};

template<int Size, typename Index>
class Trie
{
public:
	typedef trie_node<Size> node_type;
	typedef trie_node<Size>* link_type;

	Trie(Index i = Index()): index(i){}
	~Trie() 
	{
		clear();
	}

	/* 清空 */
	void clear()
	{
		clear_node(root);
		for(int i = 0; i < Size; ++i)
			root.child[i] = 0;
	}

	/* 插入字符串 */
	template<typename Iterator>
	void insert(Iterator begin, iterator end)
	{
		link_type cur = &root;
		for(; begin != end; ++begin)
		{
			if(!cur->child[index[*begin]])
			{
				cur->child[index[*begin]] = new node_type(*begin);
				++cur->nodeNum;
			}
			cur = cur->child[index[*begin]];
		}
		cur->isEndingChar = true;
	}

	/* 插入字符串，针对C风格字符串的重载版本 */
	void insert(const char* str)
	{
		insert(str, str + strlen(str));
	}

	/* 查找字符串 */
	template<typename Iterator>
	bool find(Iterator begin, iterator end)
	{
		link_type cur = &root;
		for(; begin != end; ++begin)
		{
			if(cur->child[index[*begin]])
				return false;
			cur = cur->child[index[*begin]];
		}
		return cur.isEndingChar;
	}

	/* 查找字符串，针对C风格字符串的重载版本 */
	bool find(const char* str)
	{
		return find(str, str + strlen(str));
	}

	/* 删除字符串 */
	template<typename Iterator>
	bool erase(Iterator begin, Iterator end)
	{
		bool result;
		erase_node(begin, end, result);
		return result;
	}

	/* 删除字符串， 针对C风格字符串的重载版本 */
	bool erase(const char* str)
	{
		return erase(str, str + strlen(str));
	}

	/* 按字典序遍历单词树 */
	template<typename Functor>
	void traverse(Functor &execute = Functor())
	{
		visit_node(root, execute);
	}

	void print(node_type cur)
	{
		cout << cur.data;
	}
private:
	/* 访问某节点及其子节点 */
	template<typename Functor>
	void visit_node(node_type cur, Functor &execute)
	{
		execute(cur);
		for(int i = 0; i < Size; ++i)
		{
			if(cur.child[i] == 0) continue;
			visit_node(*cur.child[i], execute);
		}
	}

	/* 清除某个节点的所有子节点 */
	void clear_node(node_type cur)
	{
		for(int i = 0; i < Size; ++i)
		{
			if(cur.child[i] == 0) continue;
			clear_node(cur.child[i]);
			delete cur.child[i];
			cur.child[i] = 0;
			if(--nodeNum == 0)
				break;
		}
	}

	/* 边搜索边删除冗余节点，返回值用于向其父节点声明是否删除该节点 */
	template<typename Iterator>
	bool erase_node(iterator begin, Iterator end, node_type &cur, bool &result)
	{
		if(begin == end)
		{
			result = cur.isEndingChar;
			cur.isEndingChar = false;
			return cur.nodeNum == 0;
		}
		if(cur.child[index[*begin]] == 0)
			return result = false;
		else if(erase_node((++begin)--, end, *(cur.child[index[*begin]]), result))
		{
			delete cur.child[index[*begin]];
			cur.child[index[*begin]] = 0;
			if(--cur.nodeNum == 0 && cur.isEndingChar == false)
				return true;
		}
		return false;
	}

	/* 根节点 */
	node_type root;

	/* 将字符转换为索引的转换表或函数对象 */
	Index index;
};

class Index
{
public:
	int operator[](const char key)
	{
		return key % 26;
	}
};

#endif //_TEMPLATE_TRIETREE_H