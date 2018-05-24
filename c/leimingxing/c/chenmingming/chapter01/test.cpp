#include <iostream>
int main()
{
	using namespace std;
        double x=0,y=0;
                cout << "------------------\n请输入两个数，求商！" << endl;
               // cin >> x >> y;
                cout <<  !(cin >> x&& cin >> y) << endl;
		return 0;
}
