#include <iostream>
#include <cmath>
using namespace std;

long out_var;
int main()
{
cout << "The memory size of long is " << sizeof(long) << " bytes" <<  endl;

long in_var;
cout << "in_var = " << in_var << endl;
cout << "in_var = " << in_var << " (2nd times)" << endl;

cout << "out_var= " << out_var << endl;
cout << "out_var= " << out_var << " (2nd times)" << endl;

long max_long= pow(2,sizeof(long)*8-1)-1;
long max_long_1= max_long+1;

long min_long=-pow(2,sizeof(long)*8-1);
long min_long_1=min_long-1;


cout << "max_long= " << max_long << endl;
cout << "min_long= " << min_long << endl;
cout << "max_long+1 = " << max_long_1<< endl;
cout << "min_long-1 = " << min_long_1<< endl;

return 0;

}
