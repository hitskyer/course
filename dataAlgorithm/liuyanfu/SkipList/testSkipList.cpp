#include "SkipList.cpp"

using namespace std;


int main()
{
	SkipList<int> slst;
	slst.Insert(12);
	slst.Insert(34);
	slst.Insert(14);
	slst.Insert(23);
	slst.Insert(5);
	slst.Insert(9);
	slst.Insert(54);
	slst.Insert(38);
	slst.Insert(19);
	slst.Insert(13);
	slst.Insert(31);
	slst.Insert(15);
	slst.Insert(20);
	slst.Insert(65);
	slst.Insert(99);
	slst.Insert(55);
	slst.Insert(30);
	slst.Insert(11);
	//slst.printAll();
	slst.printByLayer();
	/*cout << endl;
	cout << "开始删除数据" << endl;
	slst.Delete(9);
	slst.Delete(38);
	slst.printAll();*/
	return 0;
}