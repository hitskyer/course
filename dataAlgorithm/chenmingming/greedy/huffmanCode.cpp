/**
 * @description: 贪心应用--霍夫曼编码
 * @author: michael ming
 * @date: 2019/6/30 23:53
 * @modified by: 
 */
#include <string>
#include <iostream>
#define N 26
using namespace std;
struct htNode
{
    char data;
    unsigned int weight;
    htNode *parent, *lchild, *rchild;
    htNode():weight(0)
    {
        parent = lchild = rchild = NULL;
    }
};
class HuffmanTree
{
public:
    htNode *root;
    htNode node[2*N-1];
    void creatTree(int *w)
    {
        for(int i = 0; i < N; ++i)
        {
            node[i].weight = w[i];
        }
    }
};

int main()
{
    HuffmanTree huff;
    cout << "请输入依次26个字母a-z的权值（频率）：" << endl;
    int w[N];//权重
    for(int i = 0; i < N; ++i)
    {
        cout << i+1 << " ";
        cin >> w[i];
    }
    huff.creatTree(w);
}