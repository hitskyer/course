#include <string>
 #include <iostream>
 using std :: string;
 using std :: cout;
 using std :: endl;
 
 	string s;
 	int main()
 {
 		string s2;
 		cout << s << endl; //string是类，如果没有初始化，自动调动构造函数 ，s为空字符串
 		cout << s2 << endl; // s2 也是空字符串
 }
