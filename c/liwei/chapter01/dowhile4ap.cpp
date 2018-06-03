#include <iostream>
using namespace std;

int main()
{
char flag = 'y';
int sum = 0,n= 0,start = 1;
do{
cout << "输入一个数字"<< endl;
cin >> n;

  while(start<=n  ) 
  { 
	sum=sum+start;//等价于sun+=start
	start=start+1;
	  
  }  

 cout << "等于";
cout << sum;
cout << "是否继续(y/n)？";
cin >> flag;  //用什么接收

}while(flag == 'y'  );
return 0;
}
