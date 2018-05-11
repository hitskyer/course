#include<iostream>
#include<bitset>
#include<string>
using namespace std;
int main()
{
	string s("111000");
	bitset<20> bit;
	bitset<6> bit2(1111);
	bitset<6> bit3(s);
	bitset<3> bit4(s,2,3);
	cout<<"bit2 = "<<bit2<<endl;
	cout<<"bit2 = ";
	for(int i=0;i != bit2.size();i++)
	{
		cout<<bit2[i];
	}
	cout<<endl;
	cout<<"bit3 = "<<bit3<<endl;
	cout<<"bit3 = ";
	for(int x= 0;x !=bit3.size();x++)
	{
		cout<<bit3[x];
	}
	cout<<endl;
	cout<<"bit4 = "<<bit4<<endl;
	cout<<"bit4 = ";
	for(int xi= 0; xi != bit4.size();xi++)
	{
		cout<<bit4[xi];
	}
	cout<<endl;
	cout<<"bit2中为1的二进制的个数为 ："<<bit2.count()<<endl;
	cout<<"bit3中二进制的个数为 ："<<bit3.size()<<endl;
	cout<<"bit2的值为 : "<<bit2.to_ulong()<<endl;
	cout<<"bit4的最后一位为 : "<<bit4.test(2)<<endl;
	for(int ix = 0; ix != bit3.size();ix++)
	{
		bit3[ix]=1;
	}
	cout<<"bit3 = "<<bit3<<endl;
	return 0;
}

