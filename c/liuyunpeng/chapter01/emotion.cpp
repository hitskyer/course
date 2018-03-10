#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s;
	char flag='y';
	while('y' == flag) {
		cout << "输入你此时的心情" << endl;
		cin >> s;
		if ("高兴" == s) {
			cout << "因此我的心欢喜，我的灵（原文作荣耀）快乐。我的肉身也要安然居住。（诗篇16：9）" << endl;
		} else if ("悲伤" == s) {
			cout << "然而他知道我所行的路。他试炼我之后，我必如精金。（约伯记23:10）" << endl;
		} else if ("骄傲" == s) {
			cout << "骄傲在败坏以先；狂心在跌倒之前。(箴言 16:18)" << endl;
		} else if ("无助" == s){
			cout << "我要向山举目；我的帮助从何而来？我的帮助从造天地的耶和华而来。(诗篇 121:1-2 和合本)" << endl;
		} else {
			cout << "没有查到你的心情相关的经文！祝你喜乐平安！" << endl;
		}
		while (true) {
			cout << "continue(y/N)?" << endl;
			cin >> flag;
			if ('y' == flag) {
				break;
			} else if ('N' == flag) {
				return 0;
			} else {
				continue;
			}
		}
	}
	return 0;
}
