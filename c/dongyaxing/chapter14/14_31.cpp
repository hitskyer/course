#include<iostream>
#include<string>
using namespace std;

//template<typename T>
class ifThenElse
{
public:
	template<typename T>
	int operator () (T val1, T val2, T val3)
	{
		return val1? val2:val3;
	}
};

int main()
{
	ifThenElse ite;
	int n = ite(0,2,4);
	cout<<"期待 4"<<n<<endl;
	n = ite(1,2,4);
	cout<<"期待 2"<<n<<endl;
	
//	string str = ite("abc","cde","eof");
//	cout<<"期待 cde"<<str<<endl;

	return 0;
}
