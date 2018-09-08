#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int fileToVector(string fileName, vector<string> &svec)
{
	//创建ifsteam对象inFile，并绑定到由形参fileName指定的文件
	ifstream inFile(fileName.c_str());
	if(!inFile)   //打开文件失败
		return 1;
	//将文件内容读入到string类型的vector容器
	//每一行存储为该容器对象的一个元素
	string s;
	while(getline(inFile, s))
	{
		svec.push_back(s);
	}
	inFile.close();  //关闭文件
	if(inFile.eof())  //遇到文件结束符
		return 4;
	if(inFile.bad())  //发生系统故障
		return 2;
	if(inFile.fail())  //读入数据失败
		return 3;
}

int main()
{
	vector<string> svec;
	string fileName, s;
	
	cout<<"enter fileName"<<endl;
	cin>>fileName;
	
	switch(fileToVector(fileName, svec))
	{
		case 1:
			cout<<"error:can not open file:"<<fileName<<endl;
		break;
		case 2:
			cout<<"error:system failuer"<<endl;
		break;
		case 3:
			cout<<"eror:read failure"<<endl;
		break;
	}
	//使用istringstream从vector里以每次读一个单词的形式读取所存储的行
	string word;
	istringstream isstream;
	for(vector<string>::iterator iter = svec.begin();iter != svec.end(); ++iter)
	{
		//将vector对象的当前元素复制给istringstream对象
		isstream.str(*iter);
		//从istringstream对象中读取单词并输出
		while(isstream>>word)
		{
			cout<<word<<endl;
		}
		isstream.clear();   //将istringstream流置为有效状态
	}
	return 0;
}
