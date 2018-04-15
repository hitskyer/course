#include <iostream>
using namespace std;
//定义全局变量
char c;
int main() {
        // 定义局部变量
       char d;	
       cout << "c =  "<< c <<endl;
       cout << "d =  "<< d <<endl;
     cout<< "char 型变量的存储大小是："<< sizeof(char)<<" 字节 "<<endl;
     cout << "换行符\n: "<< "你好 \n 世界" << endl;
     cout <<"水平制表符\t: "<< "你好 \t 地球" <<endl;
     cout <<"纵向制表符\v: "<< "你好 \v 地球" <<endl;
     cout <<"退格符\b: "<< "你好\b 地球" <<endl;
     cout <<"回车符\r: "<< "你好 \r 地球" <<endl;
     cout <<"进纸符\f: "<< "你好 \f 地球" <<endl;
     cout <<"反斜线\\: "<< "你好 \\地球" <<endl;
     cout <<"报警符\a: "<< "你好 \a 地球" <<endl;




       /*	for (int i = -128; i < 128; ++i) {
		c = i;
		cout << "i = " << i << ", c = " << c << endl;
	}
	signed char sc;
	for (int i = -128; i < 128; ++i) {
		sc = i;
		cout << "i = " << i << ", sc = " << sc << endl;
	}
	unsigned char uc;
	for (int i = 0; i < 256; ++i) {
		uc = i;
		cout << "i = " << i << ", uc = " << uc << endl;
	}*/
	return 0;
}
