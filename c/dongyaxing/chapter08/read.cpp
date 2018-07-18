#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char buffer[256];
	fstream out;
	out.open("com.text",ios::in);
	cout<<"com.text"<<" 的内容如下： "<<endl;
	while(!out.eof())
	{
		out.getline(buffer,256,'\n');
		cout<<buffer<<endl;
	} 
	out.close();
	//cin.get();
	return 0;
}
