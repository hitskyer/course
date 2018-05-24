#include<iostream>
using namespace std;
int main(){
	int sum =0;
	int number =100;
	int i=1;
	do{
	   sum +=i;
           i++;
	}while(i<=number);
	cout << "sum的值为:" << sum << endl;
	return 0;
}
