#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
void print(const vector<T> &vec)
{
	for(typename vector<T>::size_type i=0;i!=vec.size();i++)
		cout << vec[i] << "  " ;
}
template<typename T>
void print2(const vector<T> &vec)
{
	for(typename vector<T>::const_iterator iter=vec.begin();iter!= vec.end();++iter)
		cout << *iter << endl;
}
int main ()
{
	vector<int> v1(10,-1);
	vector<int> v2(v1);
	vector<string> v3(10,"hello!");
	vector<int> v4(5);
	vector<int> v5;
	print(v1);
	cout << endl;
	print(v2);
	cout << endl;
	print(v3);
	cout << endl;
	print(v4);
	cout << endl;
	print(v5);
	cout << "v5的元素个数为：" << v5.size() << endl;
	int i=0;
	while(i<10)
	{
		v5.push_back(2*i);
		i=i+1;
	}
	print2(v5);
	cout << endl;
	cout << "v5的元素个数为：" << v5.size() << endl;
	vector<int>::iterator mid=v5.begin()+v5.size()/2;
	cout << *mid << endl;
	const vector<string>::iterator it=v3.begin();
	vector<string>::const_iterator it2=v3.begin();
	cout << *(it+5) << endl;
	*(it+5)+=" world";
	cout << *(it+5) << endl;
	cout << *(it2+7) << endl;
//const_iterator 没有+=和赋值等操作,即不可以对元素进行修改
	//*(it2+7)=" world";
	//cout << *(it2+5) << endl;
	return 0;
	}
