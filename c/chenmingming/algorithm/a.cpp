
#include<iostream>
#include<math.h>
using namespace std;
// int main()
// // {
// // 	const double a =3;
// // 	double e=1,x,temp;
// // 	int n=0;
// // 	for(x = sqrt(a);e > 0.00000000000000000000000000001;++n)
// // 	{
// // 		temp = x;
// // 		x = sqrt(a+x);
// // 		e = x-temp;
// // 	cout << "limit is " << x << ", n is " << n << ", e is "<< e << endl;
// // 	}
// // }
int main()
{
    
    long double e=1,sum=0,lastsum=0;
    long double n;
    for(n=2;e > 0.0000000001;++n)
    {
        
        sum = sum + 1/n;
        e = sum - lastsum;
        lastsum=sum;
    }
    cout << "limit is " << sum << ", n is " << n << ", e is "<< e << endl;
}
