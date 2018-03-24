#include <iostream>
#include <stdio.h>
#include <math.h>

 using namespace std;

   int main ()
      {
        int a=0,b=0,lower=0,upper=0;
        cout << "请输入两个整数【以空格间隔】：" << endl;
        cin >> a >> b;
        lower=(a>b)?b:a;
        upper=(a>b)?a:b;
        while (lower<=upper)
            {
              cout << lower << endl;
              lower++; 
            }
        return 0;
      }
