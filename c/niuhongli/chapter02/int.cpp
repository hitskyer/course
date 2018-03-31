#include <iostream>
#include <cmath>
using namespace std;

int out_var;
int main()
{
cout << "The memory size of int is " << sizeof(int) << " bytes" << endl;

int in_var;
cout << "in_var = " << in_var << endl;
cout << "in_var = " << in_var << " (2nd times)" << endl;

cout << "out_var= " << out_var << endl;
cout << "out_var= " << out_var << " (2nd times)" << endl;

int max_int= pow(2,sizeof(int)*8-1)-1;
int max_int_1= max_int+1;

int min_int=-pow(2,sizeof(int)*8-1);
int min_int_1=min_int-1;


cout << "max_int= " << max_int << endl;
cout << "min_int= " << min_int << endl;
cout << "max_int+1 = " << max_int_1<< endl;
cout << "min_int-1 = " << min_int_1<< endl;

return 0;

}
