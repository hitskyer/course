#include <iostream>
using namespace std;

char out_var;
int main()
{
cout << "The memory size of char is " << sizeof(char) << " bytes" <<  endl;

char in_var;
cout << "in_var = " << in_var << endl;

cout << "out_var= " << out_var << endl;

char in_var1='\n', in_var2='\t', in_var3='\\';

cout << "in_var1= " << in_var1 << endl;

cout << "in_var2= " << in_var2 << endl;

cout << "in_var3= " << in_var3 << endl;

return 0;

}
