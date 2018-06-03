#include <iostream>
using namespace std;

int main() 
{
	cout << "请输入你此刻的心情:  " << endl;
	string mood;
	cin >> mood; // 输入心情；
	if (mood =="开心" || mood == "高兴"){
        cout << "耶和华果然为我们行了大事，我们就欢喜（诗126:3)" << endl;
	}
	else if (mood == "难过" || mood=="忧伤")
	{
 	cout << "求他按着他丰富的荣耀，籍着他的灵，叫你们心里的力量刚强起来 （以弗所书3:16)" << endl;
	}
	else if (mood == "烦躁")
	{
	cout << " 主耶和华以色列的圣者曾如此说：“你们得救在乎归回安息，你们得力在乎平静安稳 （赛30:15) " << endl;
	}
	else 
	{
	cout << "没有理解你的心情， 盼望你在主里面得力量，平安喜乐！" << endl;
	}
	return 0;
}
