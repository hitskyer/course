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

void swapDNA(DNAdata &a,DNAdata &b)
{
	DNAdata tempDNA ;
		    tempDNA = a;
			a       = b;
			b       = tempDNA;
}

int main()
{
	size_t n,m;
	char temp;
	size_t i,j,k;
	cin >> n >> m;
	DNAdata *dna = new DNAdata[m];
	int tp = 0;
	while(tp<m)
	{
		cin >> dna[tp].name ;
		++tp;
	}
	for(i=0;i!=m;++i)
	{
		for(j =0;j!=n;++j)
		{
			temp = dna[i].name[j];
			for(k=j+1;k!=n;++k)
			{
				if(temp>dna[i].name[k])
				{
					++dna[i].sum;
				}
				
			}
		}
	}
	for(i=0;i!=m;++i)
	{
		for(j =0;j<m-i-1;++j)
		{
			if(dna[j+1].sum <dna[j].sum)
			{
				swapDNA(dna[j+1],dna[j]);
			}			
		}
	}
	for (i =0;i!=m;++i)
	{
		cout << dna[i].name << endl;
	}
	delete []dna;
	return 0;
}
