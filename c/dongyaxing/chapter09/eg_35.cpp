#include<iostream>
#include<string>
#include<cctype>  //此头文件不包含，也可执行
using namespace std;
int main()
{
	string str("ThIs Is a eXamPle");
	cout<<"原始："<<str<<endl<<endl;

	for(string::iterator it=str.begin();it!=str.end();++it)
	{
		if(isupper(*it))
		{
			str.erase(*it);
			//--it;
		}
	}
	cout<<"删除大写："<<str<<endl<<endl;
	return 0;
}
