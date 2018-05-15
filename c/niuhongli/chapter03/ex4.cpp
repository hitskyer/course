#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{

	string st("The expense of spirit\n");
	cout << "The size of " << st << " is " << st.size()
	     << " characters, including the newline." << endl;
	return 0;
}
