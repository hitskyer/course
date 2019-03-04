#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,sum;
    a=10;b=20;sum=0;
    plus<int> Addint;	//标准库函数对象
    sum = Addint(a,b);
    cout << sum << endl;
    negate<int> Negateint;
    sum = Negateint(a);
    cout << sum << endl;
    string str[5] = {"apple","orange","banana","rice","pear"};
    sort(str,str+5);
    for(int i = 0; i != 5; ++i)
    {
    	cout << str[i] << " ";
    }
    cout << endl;
    string str_a[5] = {"apple","orange","banana","rice","pear"};
    sort(str_a,str_a+5,greater<string>());	//函数对象用作谓词函数
    for(int i = 0; i != 5; ++i)
    {
    	cout << str_a[i] << " ";
    }
    cout << endl;
    return 0;
}

