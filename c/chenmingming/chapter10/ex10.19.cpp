
#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<string>
using namespace std;
int main()
{
	map<string, vector<pair<string,string> > > children;
	string surname, childname, birthday;
	do
	{
		cout << "请输入姓氏： " << endl;
		cin >> surname;
		if(!cin)
			break;
		vector<pair<string,string> > chd;
		pair<map<string, vector<pair<string,string> > >::iterator, bool> ret =
		children.insert(make_pair(surname, chd));
		if(!ret.second)
		{
			cout << "姓氏已在map中" << surname << endl;
			continue;
		}
		cout << "输入孩子的名字和生日，如'陈慕恩 20150101' ：" << endl;
		while(cin >> childname >> birthday)
			ret.first->second.push_back(make_pair(childname,birthday));
		cin.clear();
	}
	while(cin);
	char ask;
	do
	{
		cin.clear();
		cout << "输入姓进行查找：" << endl;
		cin >> surname;
		map<string, vector<pair<string,string> > >::iterator it = children.find(surname);
		if(it == children.end())
			cout << "没找到该姓氏： " << surname << endl;
		else
		{
			cout << "children, name, birthday : " << endl;
			vector<pair<string,string> >::iterator sit = (*it).second.begin();
			while(sit != it->second.end())
			{
				cout << (*sit).first << " " << sit->second << endl;
				++sit;
			}
		}
		
		cout << "continue ?  y/n " << endl;
		cin >> ask;
	}
	while(ask == 'y' || ask == 'Y');
	return 0;
}