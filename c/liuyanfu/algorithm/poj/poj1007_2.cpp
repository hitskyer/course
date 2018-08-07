#include <iostream>
#include <string>
using namespace std;

struct DNAdata
{
	string name;
	double sum;
	DNAdata()
	{
		sum = 0;
	}
};

void swapDNA(DNAdata *a,DNAdata *b)
{
	DNAdata tempDNA ;
	tempDNA = *a;
	*a       = *b;
	*b       = tempDNA;
}

int main()
{
	size_t n,m;
	n = 10;
	m = 6;
	DNAdata dna[6];
	char temp;
	size_t i,j,k;
	dna[0].name= "AACATGAAGG";
	dna[1].name= "TTTTGGCCAA";
	dna[2].name= "TTTGGCCAAA";
	dna[3].name= "GATCAGATTT";
	dna[4].name= "CCCGGGGGGA";
	dna[5].name= "ATCGATGCAT";
	for(i=0;i!=m;++i)
	{
		for(j =0;j!=n;++j)
		{
			temp = dna[i].name[j];
			for(k=j+1;k!=n && temp>dna[i].name[j+1];++k)
			{
				++dna[i].sum;
			}
		}
	}
	for (i =0;i!=m;++i)
	{
		cout << dna[i].name << " "<<dna[i].sum << endl;
	}
	cout << endl;
	for(i=0;i!=m;++i)
	{
		for(j =i;j>0 && dna[j-1].sum <dna[j].sum;--j)
		{
			swapDNA(&dna[j-1],&dna[j]);		
		}
	}
	for (i =0;i!=m;++i)
	{
		cout << dna[i].name << " "<<dna[i].sum << endl;
	}
	return 0;
}
