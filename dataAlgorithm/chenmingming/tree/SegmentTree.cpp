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
    ~SegmentTree()
    {
        destroy(root);
    }

    void destroy(TreeNode* rt)
    {
        destroy(rt->left);
        destroy(rt->right);
        delete rt;
    }

    TreeNode* build(vector<int>& A, int L, int R)
    {
        if(L > R)
            return NULL;
        TreeNode* rt = new TreeNode(L,R,A[L]);
        if(L == R)
            return root;
        int mid = L+((R-L)>>1);
        rt->left = build(A,L,mid);
        rt->right = build(A,mid+1,R);
        rt->sum = 0;
        if(rt->left)
        {
            rt->sum += rt->left->sum;
            rt->MAX = max(rt->MAX, rt->left->MAX);
            rt->MIN = min(rt->MIN, rt->left->MIN);
        }
        if(rt->right)
        {
            rt->sum += rt->right->sum;
            rt->MAX = max(rt->MAX, rt->right->MAX);
            rt->MIN = min(rt->MIN, rt->right->MIN);
        }
        return rt;
    }

    vector<int> query(TreeNode *rt, int s, int e)//查询区间的sum，min，max
    {
        if(s > rt->end || e < rt->start)
            return {0, INT_MAX, INT_MIN};//没有交集
        if(s <= rt->start && rt->end <= e)
            return {rt->sum, rt->MIN, rt->MAX};//完全包含区间，取其值
        //不完全包含，左右查找
        vector<int> l = query(rt->left, s, e);
        vector<int> r = query(rt->right,s, e);
        //汇总信息
        vector<int> summary(3);
        summary[0] = l[0] + r[0];
        summary[1] = min(l[1], r[1]);
        summary[2] = max(l[2], r[2]);
        return summary;
    }

    void modify(TreeNode *rt, int id, int val)
    {
        if(rt->start == rt->end)
        {	//叶子节点
            rt->sum = val;//和为自身
            rt->MAX = val;
            rt->MIN = val;
            data[id] = val;
            return;
        }
        int mid = (rt->start + rt->end)/2;
        if(id > mid)
            modify(rt->right, id, val);
        else
            modify(rt->left, id, val);
        root->sum = 0;
        if(rt->left)
        {
            rt->sum += rt->left->sum;
            rt->MAX = max(rt->MAX, rt->left->MAX);
            rt->MIN = min(rt->MIN, rt->left->MIN);
        }
        if(rt->right)
        {
            rt->sum += rt->right->sum;
            rt->MAX = max(rt->MAX, rt->right->MAX);
            rt->MIN = min(rt->MIN, rt->right->MIN);
        }
    }
};
//-------------test---------------------
void printVec(vector<int> &a)
{
    for(auto& ai : a)
        cout << ai << " ";
    cout << endl;
}

int main()
{
    vector<int> v = {1,2,7,8,5};
    printVec(v);

    cout << "建立线段树" << endl;
    SegmentTree sgtree(v);
    printVec(sgtree.data);

    cout << "查询区间的sum，MIN，MAX" << endl;
    vector<int> qy_res = sgtree.query(sgtree.root,1,3);
    printVec(qy_res);

    cout << "修改某位置的值" << endl;
    sgtree.modify(sgtree.root,1,100);
    printVec(sgtree.data);

    cout << "查询区间的sum，MIN，MAX" << endl;
    qy_res = sgtree.query(sgtree.root,1,3);
    printVec(qy_res);
    return 0;
}