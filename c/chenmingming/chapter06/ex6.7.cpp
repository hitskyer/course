#include<iostream>
using namespace std;
int main()
{
	char ch;
	int ac=0,ec=0,ic=0,oc=0,uc=0;
	while(cin>>ch)
	{
		switch(ch)
		{
		case 'a':
		case 'A':
			++ac;break;
		case 'e':
		case 'E':
			++ec;break;
		case 'i':
		case 'I':
			++ic;break;
		case 'o':
		case 'O':
			++oc;break;
		case 'u':
		case 'U':
			++uc;break;
		}
	}
	cout << "numbers of a & A are " << ac << endl;
	cout << "numbers of e & E are " << ec << endl;
	cout << "numbers of i & I are " << ic << endl;
	cout << "numbers of o & O are " << oc << endl;
	cout << "numbers of u & U are " << uc << endl;
	return 0;
}
