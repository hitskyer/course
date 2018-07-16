#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream in;
	in.open("com.text",ios::trunc);
	//trunc 表示在打开文件前将文件清空，文件不存在，则创建
	
	int i;
	char a='a';
	for(i = 1; i< 27; ++i)
	{
		if(i<10)
		{
			in<<"0"<<i<<"\t"<<a<<"\n";
			a++;
		}
		else
		{
			in<<i<<"\t"<<a<<"\n";
			a++;
		}
	}
	in.close();
	return 0;
}
