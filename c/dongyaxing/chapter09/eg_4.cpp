#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main()
{
	deque<int> de(10,1);
	list< deque<int> > lst(10);
	cout<<"list< deque<int> > lst"<<endl;
	return 0;
}
