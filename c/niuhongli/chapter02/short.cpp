#include <iostream>
#include <cmath>
using namespace std;

short out_var;
int main()
{
cout << "The memory size of short is " << sizeof(short) << " bytes" <<  endl;

short in_var;
cout << "in_var = " << in_var << endl;
cout << "in_var = " << in_var << " (2nd times)" << endl;

cout << "out_var= " << out_var << endl;
cout << "out_var= " << out_var << " (2nd times)" << endl;

short max_short= pow(2,sizeof(short)*8-1)-1;
short max_short_1= max_short+1;

short min_short=-pow(2,sizeof(short)*8-1);
short min_short_1=min_short-1;


cout << "max_short= " << max_short << endl;
cout << "min_short= " << min_short << endl;
cout << "max_short+1 = " << max_short_1<< endl;
cout << "min_short-1 = " << min_short_1<< endl;

return 0;

}
