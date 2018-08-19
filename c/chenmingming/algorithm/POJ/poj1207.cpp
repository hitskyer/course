#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		if(a > b)
			swap(a,b);
		int len = b-a+1;
		int *maxcyclen = new int [len];
		int cyctime=0;
		int num=0,maxcyctime=0;
		for(int i = a,j=0; i <= b; ++i,++j)
		{
			num = i;
			cyctime=1;
			while(num != 1)
			{
				if(num%2==1)
				{
					num = 3*num+1;
				}
				else
				{
					num /= 2;
				}
				++cyctime;
			}
			maxcyclen[j] = cyctime;
		}
		maxcyctime = maxcyclen[0];
		for(int i = 0; i != len; ++i)
		{
			if(maxcyctime < maxcyclen[i])
				maxcyctime = maxcyclen[i];
		}
		cout << a << " " << b << " " << maxcyctime << endl;
		delete [] maxcyclen;
		maxcyclen = NULL;
	}
	return 0;
}