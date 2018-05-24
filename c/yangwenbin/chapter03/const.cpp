#include<iostream>
using namespace std;

void testModifyConst(const int x){
//	x=10;
}



    void testConstFunction(int _x) const{

        ///错误，在const成员函数中，不能修改任何类成员变量
        //    x=_x;
        
        //错误，const成员函数不能调用非onst成员函数，因为非const成员函数可以会修改成员变量
         //  modify_x(_x);
       }
        
     void modify_x(int _x){
      	       
     }
                                                   
                                                        



int main(){
    int a1=3;   ///non-const data
    const int a2=a1;    ///const data

    int * a3 = &a1;   ///non-const data,non-const pointer
    const int * a4 = &a1;   ///const data,non-const pointer
    int * const a5 = &a1;   ///non-const data,const pointer
    int const * const a6 = &a1;   ///const data,const pointer
    const int * const a7 = &a1;   ///const data,const pointer   
         
    return 0;
}
