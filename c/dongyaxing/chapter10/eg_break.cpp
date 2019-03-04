#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int a[]={1,2,3,4,5};
	int b[]={1,2,3,4,5,6};
	vector<int> iveca(a,a+5);
	vector<int> ivecb(b,b+6);
	
	vector<int> ivecc;

	vector<int>::iterator itera = iveca.begin();
	vector<int>::iterator iterb = ivecb.begin();
	for(;itera != iveca.end(); ++itera)
	{
		for(;iterb != ivecb.end(); ++iterb)
		{
			if(*itera + *iterb == 5)
				break;
			else
				ivecc.push_back(*itera + *iterb);
		}break;
	}
	vector<int>::iterator iterc = ivecc.begin();
	for(;iterc !=ivecc.end();++iterc)
	{
		cout<<*iterc<<",";
	}
	cout<<endl;
	for(itera = iveca.begin(); itera!=iveca.end();++itera)
	{
		
		while(*itera >3)
		{
			*itera += 10;
			break;
		}
		cout<<*itera<<",";
		break;
	}
	for(itera=iveca.begin();itera!=iveca.end();++itera)
	{
		cout<<*itera<<",";
	}
	cout<<endl;
	return 0;
}
