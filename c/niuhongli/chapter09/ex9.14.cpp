#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<string> svec;
	string str;
	cout << "Please enter string to vector: " << endl;
	while(cin >> str)
	{
		svec.push_back(str);
		if(cin.get()=='\n')
			break;
	}
	cout << "Output elements in vector:" << endl;
	for(vector<string>::iterator iter=svec.begin();iter!=svec.end();++iter)
		cout << *iter << " ";
	return 0;
}