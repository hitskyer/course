#include<iostream>
using namespace std;
int main()
{
	enum Grade {one=1, two, three ,four, five, six};
	enum avlue {a, b, c=4, d, e=1, f};
	avlue h= a;
	avlue n= h;
	cout<<"three : "<<three<<endl;
	cout<<"six   : "<<six<<endl;
	cout<<"a     : "<<a<<endl;
	cout<<"d     : "<<d<<endl;
	cout<<"f     : "<<f<<endl;
	cout<<"h     : "<<h<<endl;
	cout<<"n     : "<<n<<endl;
	return 0;
}

