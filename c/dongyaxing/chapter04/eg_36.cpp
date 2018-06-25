#include <iostream>
using namespace std;
int main()
{
	int ia[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
	int (*p)[4];
	for(p=ia;p!=ia+3;p++)
	{
		cout<<p<<","<<*p<<endl;  //*p与p均输出地址
		for(int *q=*p;q!=*p+4;q++)
		{
			cout<<*q<<","<<q<<endl; //*q输出内容，q输出地址
			
		}
	}
	return 0;
}
