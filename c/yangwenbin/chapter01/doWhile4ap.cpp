#include <iostream>
 using namespace std;
    	int main(){
        char flag = 'y';
        do{
           cout<<"Please enter one number: "<< endl;
         int sum = 0, n = 0, start = 1;
         cin>> n;
         while(start <= n){

          sum +=start;
          start ++;

        }
       cout<< "The sum from 1 to "<< n <<" is "<< sum <<endl;
       while(true){

        cout<<" Contine (y/N):"<<endl;
        cin>> flag ;

        if ('y'==flag){
           break;

        }else if('N'==flag){

          return 0;
        }else{

         continue;
        }
	   }




    }while ('y'==flag);



    return 0;
	}
	

