#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	vector<string> svec;
	string word;
	while (cin >> word)
		svec.push_back(word);
	cout << "输出svec中的单词:" << endl;
	for (vector<string>::size_type i=0;i!=svec.size();++i)
		cout << svec[i] << "\t";
	cout << endl;
	cout << "把svec中每个单词换成大写字母并输出:" << endl;
	if (svec.size()==0){
		cout << "No string ?!" << endl;
		return -1;
	}
	string temp;
	int cn=0;
	for (vector<string>::size_type index=0;index!=svec.size();++index)
	{
		temp=svec[index];
		for (string::size_type ix=0;ix!=temp.size();++ix)
		{
			temp[ix]=toupper(temp[ix]);
		}
		cout << temp << " ";
	++ cn;
	if (cn % 8 ==0)
	cout << endl;
	}
}
	
