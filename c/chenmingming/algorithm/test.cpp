#include<iostream>
using namespace std;
int main()
{
	int oarr[]={6,5,8,1,3,9,6,7,4,2,5};
	for(int i=0;i <= 10;++i)
	{
		cout << oarr[i]<< " ";
	}
	cout << endl;
	size_t pindex = 0;
        int pval = oarr[0];
        for(int i = 1;i <= 10;++i )
        {
                if(pval > oarr[i])
                {
                        swap(oarr[pindex++],oarr[i]);
                }
                oarr[pindex] = pval;
        }
	      cout << "pindex " << pindex << endl;
	for(int i=0;i <= 10;++i)
	{
		cout << oarr[i]<< " ";
	}
}
