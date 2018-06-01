#include<iostream>
 #include<bitset>
 using namespace std;
 int main()
 {
 	bitset<5> good;
 	bitset<5> b1(good);
 	cout <<good <<" " <<b1 <<endl;
 	string s("1001");
 	bitset<5> b2(s);
 	cout << b2<<endl;
 	b2.flip();
 	cout << b2 << endl;
 	b2.set();
 	cout << b2 << endl;
 	b2.reset();
 	cout << b2 << endl;
 
 }
