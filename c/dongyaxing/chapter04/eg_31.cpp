#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<bitset>
using namespace std;

int main()
{
	string in_str;
	const size_t str_size=10;
	char result_str[str_size];

	cout<<"Enter a string(<="<<str_size<<" characters):"<<endl;
	cin>>in_str;

	size_t len=strlen(in_str.c_str());
	if(len>str_size)
	{
		len=str_size;
		cout<<"String is longer than str_size"<<endl;
		return -1;
	}
	else if(len<=str_size)
	{
		cout<<"string is smaller than str_size"<<endl;
	}
	strncpy(result_str,in_str.c_str(),str_size);
	cout<<result_str<<endl;
	return 0;
}




