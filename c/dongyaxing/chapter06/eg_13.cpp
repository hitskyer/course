#include<iostream>
#include<string>
using namespace std;
int main()
{
	//定义变量
	string preword,currword;
	string repword;
	//初始化
	int currc=0,maxc=1;
	
	cout<<"enter some words(ctrl +d to end)"<<endl;
	//循环判断
	while(cin>>currword)
	{
		if(currword==preword)
			++currc;
		else
		{
			if(currc>maxc)
			{
				maxc=currc;
				repword=preword;
			}
			currc=1;
		}
		preword=currword;
	}
		if(maxc!=1)
		cout<<preword<<" repeated for " 
			<<maxc<<" times"<<endl;
		else
			cout<<"There is no repeated word."<<endl;
	
	return 0;
}
