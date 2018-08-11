#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int iv;
	cout << "Please enter some integers for vector, end with 'Enter' key!" << endl;
	while(cin>>iv)
	{	
		ivec.push_back(iv);
		if(cin.get()=='\n')
			break;
	}
	if(ivec.empty())
		cout << "No element!" << endl;
	else //非空
	{
		cout << "The first element in ivec is " << ivec[0] << endl;
		cout << "The first element in ivec is " << ivec.at(0) << endl;
		cout << "The first element in ivec is " << ivec.front() << endl;
		cout << "The first element in ivec is " << *ivec.begin() << endl;
	}
	return 0;
}




