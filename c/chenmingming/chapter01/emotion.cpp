#include <iostream>
#include <string>
using namespace std;

int main() 
{
	cout << "输入你此时的心情（中文或English） : " << endl;
	string s;
	cin >> s;
	if (s == "高兴"|| s == "happy") {
		cout << "圣经！";
	} 
	else if (s == "悲伤"||s == "sad"||s == "难过"){
		cout << "圣经！！";
	}
	else {
		cout << "没有查到你的心情相关的经文！祝你喜乐平安！";
	}
	return 0;
}
