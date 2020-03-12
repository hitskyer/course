/**
 * @description: 线段树
 * @author: michael ming
 * @date: 2020/3/13 0:21
 * @modified by: 
 */
#include<vector>
#include<iostream>
using namespace std;
class TreeNode
{
public:
    int sum;//区间和
    int MAX;//区间最大的
    int MIN;//区间最小的
    int start, end;//区间左右端点
    TreeNode *left, *right;//左右节点
    TreeNode(int s, int e, int v):start(s),end(e),sum(v)
    {
        left = right = NULL;
        MAX = v;
        MIN = v;
    }
};
class SegmentTree
{
public:
    TreeNode* root;
    vector<int> data;
    SegmentTree(vector<int>& A)
    {
        root = build(A, 0, A.size()-1);
        data = A;
    }

    TreeNode* build(vector<int>& A, int L, int R)
    {
        if(L > R)
            return NULL;
        TreeNode* root = new TreeNode(L,R,A[L]);
        if(L == R)
            return root;
        int mid = L+((R-L)>>1);
        root->left = build(A,L,mid);
        root->right = build(A,mid+1,R);
        root->sum = 0;
        if(root->left)
        {
            root->sum += root->left->sum;
            root->MAX = max(root->MAX, root->left->MAX);
            root->MIN = min(root->MIN, root->left->MIN);
        }
        if(root->right)
        {
            root->sum += root->right->sum;
            root->MAX = max(root->MAX, root->right->MAX);
            root->MIN = min(root->MIN, root->right->MIN);
        }
        return root;
    }

    vector<int> query(TreeNode *root, int s, int e)//查询区间的sum，min，max
    {
        if(s > root->end || e < root->start)
            return {};//没有交集
        if(s <= root->start && root->end <= e)
            return {root->sum, root->MIN, root->MAX};//完全包含区间，取其值
        //不完全包含，左右查找
        vector<int> l = query(root->left, s, e);
        vector<int> r = query(root->right,s, e);
        //汇总信息
        vector<int> summary(3);
        summary[0] = l[0] + r[0];
        summary[1] = min(l[1], r[1]);
        summary[2] = max(l[2], r[2]);
        return summary;
    }

    void modify(TreeNode *root, int id, int val)
    {
        if(root->start == root->end)
        {	//叶子节点
            root->sum = val;//和为自身
            root->MAX = val;
            root->MIN = val;
            data[id] = val;
            return;
        }
        int mid = (root->start + root->end)/2;
        if(id > mid)
            modify(root->right, id, val);
        else
            modify(root->left, id, val);
        root->sum = 0;
        if(root->left)
        {
            root->sum += root->left->sum;
            root->MAX = max(root->MAX, root->left->MAX);
            root->MIN = min(root->MIN, root->left->MIN);
        }
        if(root->right)
        {
            root->sum += root->right->sum;
            root->MAX = max(root->MAX, root->right->MAX);
            root->MIN = min(root->MIN, root->right->MIN);
        }
    }
};
//-------------test---------------------
void printVec(vector<int> a)
{
    for(auto& ai : a)
        cout << ai << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1,2,7,8,5};
    SegmentTree sgtree(v);
    printVec(sgtree.query(sgtree.root,0,3));
    sgtree.modify(sgtree.root,1,100);
    printVec(sgtree.data);
    return 0;
}