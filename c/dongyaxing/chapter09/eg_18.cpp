#include<iostream>
#include<list>
#include<deque>

using namespace std;

int main()
{
	int val;
	list<int> ilst;
	deque<int> evenDq, oddDq;

	cout<<"Enter some int values(ctrl+d/z to end): "<<endl;
	while(cin >> val)
	{
		ilst.push_back(val);
	}
	
	//copy
	for(list<int>::iterator iter=ilst.begin(); iter!=ilst.end();++iter)
	{
		if(*iter % 2 == 0)
		{
			evenDq.push_back(*iter);
		}
		else if(*iter % 2 == 1)
		{
			oddDq.push_back(*iter);
		}
	}
	
	//output
	deque<int>::iterator it;
	it=evenDq.begin();
	while(it!=evenDq.end())
	{
		cout<<(*it)<<"  ";
		it++;
	}
	cout<<endl;
	deque<int>::iterator itodd;
	itodd=oddDq.begin();
	while(itodd!=oddDq.end())
	{
		cout<<(*itodd)<<"  ";
		itodd++;
	}
	cout<<endl;
	
		
	return 0;
}
