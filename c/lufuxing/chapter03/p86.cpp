#include<iostream>
#include<string>
using namespace std;
int main()
{
 string s;
 cout <<"请输入一个字符串，可以包含空格："<<endl;
 getline(cin,s);
 for(auto &c:s)
 {
  c='X';
 }
 cout <<s<<endl;
 return 0;
}
