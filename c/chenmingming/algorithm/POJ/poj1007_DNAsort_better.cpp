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
    size_t A = 0, C = 0, G = 0;
    for(i = 0; i != m; ++i)
    {
        for(j = 0; j != n; ++j) //输入1个dna的字符序列
        {
            cin >> dna[i].name[j];
        }
        for(int j = n-1; j >= 0; --j)	//从后往前计算逆序数
        {
            switch(dna[i].name[j])
            {
                case 'A':
                    ++A;break;
                case 'C':
                    ++C;dna[i].sum += A;break;
                case 'G':
                    ++G;dna[i].sum += A + C;break;
                case 'T':
                    dna[i].sum += A + C + G;break;
                default:
                    break;
            }
        }
        A = 0;	//为下一个计算，清零
        C = 0;
        G = 0;
    }

    for (i = 0; i != m; ++i)	//插入排序
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
        //cout << " " << dna[i].sum << endl;
    }
    return 0;
}
