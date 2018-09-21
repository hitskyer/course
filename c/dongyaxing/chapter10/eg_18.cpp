#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int main()
{
	map<string, vector<string> > children;
	string surName, childName;
	
	//读入条目（家族姓氏及其所有孩子的名字）
	do
	{
		cout<<"Enter surName(ctrl+d to end)"<<endl;
		cin>>surName;
		if(!cin)     //结束读入
			break;
		//cin.clear();
		
		//插入新条目
		vector<string> chd;
		pair<map<string, vector<string> > :: iterator, bool> ret = children.insert(make_pair(surName, chd));
		
		if(!ret.second)  //该家族姓氏已经在map容器中存在
		{
			cout<<"repeated surName: "<<surName<<endl;
			continue;
		}
		
		cout<<"Enter children's name(ctrl+d to end):"<<endl;
		while(cin >> childName)  //读入该家族所有孩子的名字
			ret.first -> second.push_back(childName);
		cin.clear();
	}while(cin);
	
	cin.clear();  //使输入流重新有效
	
	//读入要查询的家族
	cout<<"Enter a surName to search: "<<endl;
	cin>>surName;
	
	//根据读入的家族姓氏进行查询
	map<string, vector<string> >::iterator iter=children.find(surName);
	
	//输出查询结果
	if(iter == children.end())
		cout<<"no this surName!!!"<<endl;
	else
	{
		cout<<"children: "<<endl;
		vector<string>::iterator it = iter->second.begin();
		while(it != iter->second.end())
		{
			cout<<*it<<endl;
			++it;
		}
	}
	
	
	return 0;
}
