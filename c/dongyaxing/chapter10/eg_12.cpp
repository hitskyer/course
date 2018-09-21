#include<iostream>
#include<map>
#include<utility>
#include<string>
using namespace std;

int main()
{
	map<string, int> wordCount;
	string word;
	//读入单词并统计其出现次数
	cout<<"enter some words(ctrl+d to end):"<<endl;
	while(cin >> word)
	{
		//插入元素<word ,1>
		pair<map<string,int>::iterator,bool>ret = wordCount.insert(make_pair(word,1));
		if(!ret.second)  //该单词已存在容器中
			++ret.first->second;  //将单词出现的次数加1
	}
	
	//输出结果
	cout<<"word\t\t"<<"times"<<endl;
	for(map<string, int>::iterator iter = wordCount.begin();iter!=wordCount.end();++iter)
	{
		cout<<(*iter).first<<"\t\t"<<(*iter).second<<endl;
	}
	return 0;
}
