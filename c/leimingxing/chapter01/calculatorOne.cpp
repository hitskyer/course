#include<iostream>

using namespace std;

int main(){

  //设定变量,
  //输入序列号
  int Snumber;
  //输入 数字A
  int a;
  //输入 数字B
  int b;
  
  while(true){
    
   loop: 
     cout << " 简单计算器 "  << endl;
     cout << "1. 加法运算"  << endl;
     cout << "2. 减法运算"  << endl;
     cout << "3. 乘法运算"  << endl;
     cout << "4. 除法运算"  << endl;
     cin >> Snumber;
     loop1: if(cin.fail()){
        
        cin.clear();
        cin.ignore();
        cout << "输入有误,请重新输入"<< endl;
        cin >> Snumber;
  	goto loop1;
     }
    
     if(Snumber>0 && Snumber < 5){
        
	if(Snumber==1){
       	   cout << "请输入两个整数" << endl;
	   cin >> a >> b;
       	loop2:if(cin.fail()){
	   cin.clear();
	   cin.ignore();
	   cout << "输入有误,请重新输入两个整数" << endl;
	   cin >> a >> b ;
	   goto loop2;
	}else{
  	  cout << a << "与" << b << "的和为" << a+b << endl ;
	  goto loop;
 	}
 	}
        if(Snumber==2){
          cout << "请输入两个整数" << endl;
	  cin >> a >> b;
	loop3:if(cin.fail()){
	  cin.clear();
	  cin.ignore();
          cout << "输入有误,请重新输入两个整数" << endl;
	  cin >> a >> b;
	  goto loop3;
	}else{
	  cout << a << "与" << b << "的差为" << a-b << endl; 
	  goto loop;
	}
	}
        if(Snumber==3){
	  cout << "请输入两个整数" << endl;
          cin >> a >> b;
	loop4:if(cin.fail()){
	  cin.clear();
	  cin.ignore();
          cout << "输入有误,请重新输入两个整数" << endl;
          cin >> a >> b;
	  goto loop4;
	}else{
	  cout << a << "与" << b << "的积为" << a*b << endl;
          goto loop;
	}
	}
	if(Snumber==4){
	  cout << "请输入两个整数" << endl;
	  cin >> a >> b;
	loop5: if(cin.fail()){
	  cin.clear();
	  cin.ignore();
	  cout << "输入有误,请重新输入两个整数" <<endl;
	  cin >> a >> b;
	  goto loop5;
	}else{
	  cout << a << "与" << b << "的商为" << a/b << endl;
	  goto loop;
	}
     }else{
        cout << "无此序列号,请重新输入" << endl;
        cin >> Snumber;
        goto loop1;
     }

   }
}
} 
