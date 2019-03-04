#include"Employee.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<Employee> vemp;
	Employee e1, e2("cmm"), e3(e2);
	// vemp.push_back(e1);
	// vemp.push_back(e2);
	// vemp.push_back(e3);
	string name;
	cout << "please enter Employee's name: " << endl;
	while(cin >> name)
	{
		Employee e4(name);
		//vemp.push_back(e4);
	}
	return 0;
}