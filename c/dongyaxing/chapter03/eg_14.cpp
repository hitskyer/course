#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> s_vec;
	string str;
	cout<<"Enter text(Ctrl+z to end):"<<endl;
	while(cin>>str)
	{
		if(str=="q")
		{continue;}
		else
		s_vec.push_back(str);
		
	}
	for(vector<int>::size_type i=0;i<s_vec.size();i++)
	{
		
		for(string :: size_type index=0;index<s_vec[i].size();index++)
		{
			s_vec[i][index]=toupper(s_vec[i][index]);
		}
		cout<<s_vec[i]<<"\t";
		if((i+1)%8==0)
			cout<<endl;
	}
	while(cin>>str)
	{
		if(str=="q")
		return -1;		
	}
	return 0;
}




