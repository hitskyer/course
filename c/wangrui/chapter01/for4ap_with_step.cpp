#include <iostream>
using namespace std;
int main(){
	char flag = 'y';
	while ('y'==flag){
		cout<<"请输入一个数："<<endl;
		int sum=0,n=0,i=1;
		cin >> n;
		for(int start=1;i<=n;i++){
			start=1+(i-1)*2;
                        sum +=start;
		}
		cout<<"首项为1，公差为2的等差的数列的1到"<< n <<"项的和为："<<sum <<endl;
		while(true){
			cout<<"输入y 或n继续程序："<<endl;
			cin >> flag;
			if('y'==flag){
				break;
			}else if ('n'==flag){
				return 0;
				
			}else{
				continue;
			}
		}
		
		
	}
	
}
