#include <iostream>
using namespace std;

int main() {
	cout << "\\n(换行符)     : " << "before\nafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\t(水平制表符) : " << "before\tafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\v(纵向制表符) : " << "before\vafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\b(退格符)     : " << "before\bafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\r(回车符)     : " << "before\rafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\f(进纸符)     : " << "before\fafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\a(报警符)     : " << "before\aafter" << endl;
	cout << "-------------------------------------" << endl;
	cout << "\\\\(反斜线)    : " << "before\\after" << endl;
	cout << "-------------------------------------" << endl;

	return 0;
}
