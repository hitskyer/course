#include<iostream>
#include<string>
#include<bitset>
using namespace std;

int main()
{
//a
	bitset<64> bitvec(32);
	cout << "bitvec= " << bitvec << endl;
//b
	bitset<32> bv(1010101);
	cout << "bv= " << bv << endl;
//c
	string bstr;
	cin >> bstr;
	bitset<8> bv1(bstr);
	cout << "bv1= " << bv1 << endl;
}
