#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		cout << a << " " << b << " " ;//坑，要先输出a,b,如果调换了，输出就颠倒了
		if(a > b)
			swap(a,b);
		int maxcyclen=0;
		int cyctime=0;
		int num=0;
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
			if(maxcyclen < cyctime)
			{
				maxcyclen = cyctime;
			}
		}
		cout << maxcyclen << endl;
	}
	return 0;
}