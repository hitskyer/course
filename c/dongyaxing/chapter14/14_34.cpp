#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class EQ_cls
{
public:
	EQ_cls(int val = 0):spValue(val) { }
	bool operator()(const int &ival)
	{ return ival == spValue; }
private:
	int spValue;
};

int main()
{
	vector<int> ivec;
	int ival;
	cout<<"enter some numbers(ctrl+d to end): "<<endl;
	while(cin>>ival)
		ivec.push_back(ival);
	cin.clear();
	
	int replacedVal;
	cout<<"enter a value that will be replaced: "<<endl;
	cin>>replacedVal;
	cin.clear();
	
	int newval;
	cout<<"enter a new value: "<<endl;
	cin>>newval;
	cin.clear();
	
	replace_if(ivec.begin(),ivec.end(),EQ_cls(replacedVal), newval);
	
	cout<<"new sequence:"<<endl;
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		cout<<*iter<<" , ";
	}

	return 0;
}
