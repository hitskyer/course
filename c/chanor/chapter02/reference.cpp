#include <iostream>
using namespace std;

int main()
{
	int ival = 1024;
	int &refVal = ival;
	int &refrefVal = refVal;
	refVal++;
	refrefVal++;
	cout <<"inval		:" << ival << endl;
	cout << "refVal		:" << refVal << endl;
	cout << "refrefVal	:" << refrefVal << endl;
}
