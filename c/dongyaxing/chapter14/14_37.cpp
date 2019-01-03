#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	const int ARR_SIZE = 7;
	int ia[ARR_SIZE] = {1,1025, 2, 1026, 1030, 3, 1048};
	vector<int> ivec(ia,ia+ARR_SIZE);
	string sa[ARR_SIZE] = {"many", "much", "that", "pooh", "this","pooh", "rich"};
	vector<string> svec(sa,sa+ARR_SIZE);

	//查找大于1024的所有值
	cout<<"all values that are greater than 1024: "<<endl;
	vector<int>::iterator iter = ivec.begin();
	while((iter = find_if(iter, ivec.end(), bind2nd(greater<int>(), 1024)))!=ivec.end()) //bind2end() -> find_if() -> iter!=ivec.end()
	{
		cout<<*iter<<" ";
		++iter;
	}
	
	//查找不等于“pooh”的所有字符串
	cout<<endl<<"all strings that are not equal to pooh: "<<endl;
	vector<string>::iterator it = svec.begin();
	//使用bind2dn函数适配器，将not_equal_to对象的右操作数绑定为“pooh”
	while((it = find_if(it, svec.end(), bind2nd(not_equal_to<string>(),"pooh")))!=svec.end())
	{
		cout<<*it<<" ";
		++it;
	}

	//将所有值都乘以2
	//使用bind2nd函数适配器将multiplies对象的右操作数绑定为2
	transform(ivec.begin(), ivec.end(), ivec.begin(),bind2nd(multiplies<int>(), 2));

	cout<<endl<<"all values multiplied by 2: "<<endl;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end(); ++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	return 0;
}
