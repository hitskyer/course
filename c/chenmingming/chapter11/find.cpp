#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
	int ia[7] = {52,13,14,100,66,10,66};
	int search = 66;
	int *position = std::find(ia,ia+7,search);
	std::cout << "the value you want is " << *position << (position==ia+7 ? " not found" : " found")
	<< std::endl;
	std::cout << "ia address is " << ia << " address of found value is " << position << std::endl;
	int ia1[] = {1,2,3,4};
	int sum = std::accumulate(ia1,ia1+3,100);
	std::cout << "sum is " << sum << std::endl;
	string str[] = {"abc","def","ghi","jkl"};
	string strsum = accumulate(str,str+4,string("ok!!!"));
	cout << strsum << endl;
	char* str1[] = {"jkl","haha","abc"};
	string *strp = find_first_of(str,str+4,str1,str1+3);
	cout << *strp << " " << str << " " << strp << endl;
}