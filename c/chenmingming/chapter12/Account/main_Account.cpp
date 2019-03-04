#include"Account.h"
#include<iostream>
using namespace std;

int main()
{
	Account cmm("chenmm", 0), nhl("niuhl", 0);
	cout << cmm.rate() << " " <<nhl.rate() << endl;
	cmm.rate(0.035);
	cout << cmm.rate() << " " <<nhl.rate() << endl;
	cmm.deposit(100);
	nhl.deposit(200);
	cout << cmm.getBalance() << " " <<nhl.getBalance() << endl;
	cmm.withdraw(50);
	nhl.withdraw(210);
	cout << cmm.getBalance() << " " <<nhl.getBalance() << endl;
	cmm.applyint();
	nhl.applyint();
	cout << cmm.getBalance() << " " <<nhl.getBalance() << endl;
}