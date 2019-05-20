#include "HashTableOpti.h"
#include <iostream>
using namespace std;

int main()
{
	HashTableOpti mp;
	mp.Insert(20);
	mp.Insert(123);
	mp.Insert(34);
	mp.Insert(45);
	mp.Insert(13);
	mp.Insert(7);
	mp.Insert(65);
	mp.Insert(27);
	mp.Insert(35);

	mp.Insert(21);
	mp.Insert(124);
	mp.Insert(33);
	mp.Insert(46);
	mp.Insert(15);
	mp.Insert(3);
	mp.Insert(66);
	mp.Insert(28);
	mp.Insert(39);

	mp.Insert(22);
	mp.Insert(125);
	mp.Insert(41);
	mp.Insert(49);
	mp.Insert(12);
	mp.Insert(1);
	mp.Insert(76);
	mp.Insert(29);
	mp.Insert(32);
	mp.print();
	cout << endl;

 	if(mp.Contain(20))
 		mp.Delete(20);
 	else
 		mp.Insert(20);
 	mp.print();
 	cout << endl;
 
 	if(mp.Contain(55))
 		mp.Delete(55);
 	else
 		mp.Insert(55); 
	if(mp.Contain(26))
		mp.Delete(26);
	else
		mp.Insert(26);
	if(mp.Contain(27))
		mp.Delete(27);
	else
		mp.Insert(27);
	mp.print();
	system("pause");
	return 0;
}