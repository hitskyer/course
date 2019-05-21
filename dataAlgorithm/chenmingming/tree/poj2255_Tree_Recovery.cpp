/**
 * @description: 给出前序和中序二叉树节点序列，求后序二叉树节点输出序列
 * @author: michael ming
 * @date: 2019/5/21 18:49
 * @modified by: 
 */
#include <iostream>
#include <string>
using namespace std;
void postOrder(string &pre, int pre_start, int pre_end, string &in, int in_start, int in_end)
{
    char root = pre[pre_start]; //前序的根节点
    int pos = in.find(root);    //在中序里找到root
    int L_len = pos - in_start, R_len = in_end - pos;   //计算左右子树长度
    if(L_len >= 1)
        postOrder(pre, pre_start+1, pre_start+L_len, in, in_start, pos-1);  //对左子树递归调用
    if(R_len >= 1)
        postOrder(pre, pre_start+L_len+1, pre_end, in, pos+1, pos+R_len);   //对右子树递归调用
    cout << root;   //后序，最后输出根节点
}
int main()
{
    string preOrder, inOrder;
    while(cin >> preOrder >> inOrder)
    {
        //参数（前序字符，前序开始p，前序结束p，中序字符，中序开始p，中序结束p）
        postOrder(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1);
        cout << endl;
    }
    return 0;
}