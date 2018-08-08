#include<string>
#include<iostream>
using namespace std;
struct DNAdata	//定义结构体
{
    char name[51];
    double sum;
    DNAdata()
    {
        sum = 0;
    }
};
void swapDNA(DNAdata *a, DNAdata *b)
{
    DNAdata tempDNA;
    tempDNA = *a;
    *a = *b;
    *b = tempDNA;
}
int main()
{
    size_t n, m;	//dna序列位数n，m个dna序列
    cin >> n >> m;
    DNAdata dna[101];
    char temp;
    size_t i,j,k;
    for(i = 0; i != m; ++i)
    {
        for(j = 0; j != n; ++j) //输入1个dna的字符序列
        {
            cin >> dna[i].name[j];
        }
        for(j = 0; j != n; ++j) //对该序列进行求逆序数
        {
            temp = dna[i].name[j];
            for(k = j+1; k != n; ++k)
            {
                if(temp>dna[i].name[k])
                {
                    ++dna[i].sum;
                }
            }
        }
    }
    for (i = 0; i != m; ++i)  //插入排序
    {
        for (j = i; j > 0 && dna[j-1].sum > dna[j].sum; --j)
            //每次的子列都是有序的，判断条件可写在for(内)，否则不可（这么做减少运行次数）
            //每次和有序数组最后一个比较，向前搜索，直到找到位置停止
        {
            swapDNA(&dna[j-1], &dna[j]);
        }
    }
    for (i = 0; i != m; ++i)  //输出排序后的dna序列
    {
        for(j = 0; j != n; ++j)
        {
            cout << dna[i].name[j];
        }
        cout << endl;
    }
    return 0;
}