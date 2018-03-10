#include <iostream>

using namespace std;


  int main ()
      {
        int val=0,sum=0;
        cout << "请输入一组整数【以空格间隔】" <<endl;
        while (cin >> val)   //当cin检测到0结尾时，cin>>val的返回值为0即为假，跳出循环
          {
             sum+=val;
          }
        cout << "输入几个整数的总和是：" << sum <<endl;
        return 0;
      }
/*cin不会读取换行符的，会跳过空格和换行符*/
