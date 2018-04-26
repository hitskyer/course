#include <iostream>
using namespace std;

int main()
{
	enum ColorRainbow {red=1, orange, yellow, green, blue, indigo, violet};
	cout << "The colors of Rainbow are " << red << "(red) " << orange << "(orange) " << yellow << "(yellow) " 
		<< green << "(green) " << blue << "(blue) " << indigo << "(indigo) " << violet  << "(violet)" <<endl;
	ColorRainbow CR_desk=yellow;
	cout << "CR_desk= " << yellow << endl;
	
	return 0;

}
