#include <iostream>
using namespace std;
int main(){
        char flag='y';
        while('y'==flag){
	cout<<"现在的心情是？"<<endl;
	string mood="开心";
	cin>>mood;
	if (mood=="开心"){
		cout<<"这些事我已经对你们说了，是要叫我的喜乐存在你们心里，并叫你们的喜乐可以满足。-约翰福音15:11"<<endl;
	}else if(mood=="沮丧"){
		cout <<"你们现在也是忧愁，但我要再见你们，你们的心就喜乐了；这喜乐也没有人能夺去。-约翰福音16:22"<<endl;
	}else {
		cout<<"生灵所结的果子，就是仁爱，喜乐，和平，忍耐，恩慈，良善，信实。-加拉太书5:22"<<endl;
	}
        while(true){

            cout<<"输入“y/n”继续或终止程序："<<endl;
            cin>>flag;
            if('y'==flag){

                 break;
            }else if('n'==flag){
                return 0;
           }else{
                continue;
           }


       }
	
}
         return 0;
}
