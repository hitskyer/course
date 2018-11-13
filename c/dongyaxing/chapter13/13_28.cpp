class TreeNode
{
public:
	TreeNode():count(0), left(0), right(0) { }
	TreeNode(const TreeNode &orig):value(orig.value)
	{
		count = orig.count;
		if(orig.left)
			left = new TreeNode(*orig.left);
		else
			left = 0;
		if(orig.right)
			right = new TreeNode(*orig.right);
		else
			right = 0;
	}
	~TreeNode()
	{
		if(left)
			delete left;
		if(right)
			delete right;
	}

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree
{
public:
	BinStrTree():root(0) { }
	BinStrTree(const BinStrTree &orig)
	{
		if(orig.root)
			root = new TreeNode(*orig.root);
		else
			root = 0;
	}
	~BinStrTree()
	{
		if(root)
			delete root;
	}
private:
	TreeNode *root;
};
