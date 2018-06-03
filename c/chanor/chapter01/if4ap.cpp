#include <iostream>
using namespace std;

int main() 
{
	while(true)
	{
		cout << "Input your choice ——0:exit; 1:happy; 2:angry; 3:sad; " << endl;
		int v = 0;
		std::cin >> v; // read input
		if (0==v)
		{
			break;
		}else
		if (1==v) 
		{
			cout<< "when you happy,you can sing!" << endl;
		} else if (2==v)
		{
			cout<< "when you angry,you can pray!" << endl;
		} else if (3==v)
		{
			cout<< "when you sad,you can read bible!" << endl;
		}else
		{
			cout << "I don`t know!" << endl;
		}
	}
	return 0;
}
