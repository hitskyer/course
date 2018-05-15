#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main ()
{
	bitset<4> bitset1;
	bitset<8> bitset2(12);

	string s="100101";
	bitset<10> bitset3(s);

	char s2[]="10101";
	bitset<13> bitset4(s2);
	cout << bitset1 << endl;
	cout << bitset2 << endl;
	cout << bitset3 << endl;
	cout << bitset4 << endl;

	bitset<2> bitset5(12);
	string str="1001011";
	bitset<4> bitset6(str);
	char s3[]="111010";
	bitset<4> bitset7(s3);
	cout << bitset5 << endl;
	cout << bitset6 << endl;
	cout << bitset7 << endl;
	if (bitset3.any())
		cout << "存在" << endl;
	else 
		cout << "不存在" << endl;
	cout << bitset3.count() << endl;
	cout << bitset3.size() << endl;
	cout << bitset3[3] << endl;
	if (bitset3.test(4))
		cout << "该处的二进制位为 1" << endl;
	else
		cout << "该处的二进制位为 " << bitset3[4] << endl;
	bitset3.set();
	cout << bitset3 << endl;
	bitset3.reset(); 
	cout << bitset3 << endl;
	bitset3.set(2); 
	cout << bitset3 << endl;
	bitset3.reset(2); 
	cout << bitset3 << endl;
	bitset3.flip(); 
	cout << bitset3 << endl;
	system("pause");
	return 0;
}
