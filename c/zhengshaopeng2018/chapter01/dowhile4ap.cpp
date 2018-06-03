#include<iostream>
using namespace std;
int main()
{
    char flag = 'Y' ;
    do
    {
             int sum =0,n =0 , start =1;//定义变量
             cout<<"请输入一个整数"<<endl;
             cin>>n;//输入数字
             do
                { 
                    sum += start; //sum = sum + start
                     ++start ; // start = start+1
                 } while(start<=n);
          cout<< "从1到"<<n<<"的和为"<<sum<<endl;
          do
              {
                 cout<<"请输入Y/N（继续或者结束）"<<endl;
                 cin>>flag;
                 if('Y'==flag) {
                                   break ;                  
                                } 
                 else if ('N'==flag ){
                                          return 0;
                                      } 
                 else {
                             continue ;
                      } 
                 }while(true);
     }while('Y'==flag);
        return 0;
}
    
