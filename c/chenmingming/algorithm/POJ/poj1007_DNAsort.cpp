#include<string>
#include<iostream>
using namespace std;
struct DNAdata
{
	std::string name;
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
	//char arr[4] = {'A','C','G','T'};
	cin >> n >> m;
	DNAdata dna[m];
	char temp;
	size_t i,j,k;
	for(int i = 0; i != m; ++i)
	{
		cin >> dna[i].name;
		for(int j = 0; j != n; ++j)
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
	
	for (size_t i = 0; i != m; ++i)
	{
       		for (size_t j = i; j > 0 && dna[j-1].sum > dna[j].sum; --j)
        //每次的子列都是有序的，判断条件可写在for(内)，否则不可（这么做减少运行次数）
        //每次和有序数组最后一个比较，向前搜索，直到找到位置停止
        	{
            		swapDNA(&dna[j-1], &dna[j]);
        	}
    	}

    	for (size_t i = 0; i != m; ++i)
    	{
        	cout << dna[i].name << " " << dna[i].sum << endl;   
    	}
	return 0;
}
