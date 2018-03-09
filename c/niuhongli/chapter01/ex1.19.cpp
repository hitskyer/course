#include <iostream>
using namespace std;

/*编写程序，提示用户输入两个数并将这两个数范围内的每
 * 个数写到标准输出。
 */

int main()
{
cout << "Enter two numbers: " << endl;
int v1, v2, lower, upper;
cin >> v1 >> v2;
if (v1<v2) {
lower=v1;
upper=v2;
}
else
{
lower=v2;
upper=v1;
}
cout << "The number from " << lower << " to " << upper << " is successively: " << endl;
for (int i=lower, count=1; i<=upper; ++i, ++ count)
{
cout << i << " ";
if (count % 10 ==0)
cout << endl;
}
return 0;
}
