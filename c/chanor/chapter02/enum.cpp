#include <iostream>
using namespace std;

int main()
{

	//enum Week {Mon=1, Tues, Wed, Thur, Fri, Sat, Sun};
	enum {Mon=1, Tues, Wed, Thur, Fri, Sat, Sun};
	int index;
	while(true)
	{
		cin >> index ; 
		switch(index)
		{
			case Mon:
				cout << "工作第一天，要喜乐哦~" << endl;
				break;
			case Tues:
				cout << "工作第二天，要平安幺~" << endl;
				break;
			case Wed:
				cout << "工作第三天，要加油啦~" << endl;
				break;
			case Thur:
				cout << "工作第四天，要得力哦~" << endl;
				break;
			case Fri:
				cout << "工作第五天，要减持哈~" << endl;
				break;
			case Sat:
				cout << "休息啦~" << endl;
				break;
			case Sun:
				cout << "主日去团契啦~" << endl;
				break;
		}	
	}
/*
*/
}
