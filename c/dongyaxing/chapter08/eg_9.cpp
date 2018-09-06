#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int fileToVector(string fileName, vector<string>& svec)
{
	//创建ifstream 对象，inFile,并绑定到由形参fileName指定的文件
	ifstream inFile(fileName.c_str());
	if(!inFile)
		return 1;
	//将文件内容读入到string类型的vector容器
	//每一行存储为该容器对象的一个元素
	string s;
	while(getline(inFile, s))   //getline() 读取一行，直到换行符结束
	{
		svec.push_back(s);
	}
	inFile.close();   //关闭文件
	if(inFile.eof())   //遇到文件结束符
		return 4;
	if(inFile.bad())   //发生系统故障
		return 2;
	if(inFile.fail())   //读入数据失败
		return 3;
}

int main()
{
	vector<string> svec;
	string fileName, s;
	//读入文件名
	cout<<"Enter fileName: "<<endl;
	cin>>fileName;
	//处理文件
	switch(fileToVector(fileName, svec))
	{
		case 1:
			cout<<"error : can not open file: "<<fileName<<endl;
		return -1;
		case 2:
			cout<<"error:system failure"<<endl;
		return -1;
		case 3:
			cout<<"error:read failure"<<endl;
		return -1;
	}
	//输出vector对象进行检验
	cout<<"Vector:"<<endl;
	for(vector<string>::iterator iter = svec.begin();iter != svec.end(); ++iter)
	{
		cout<<*iter<<endl;
	}
	return 0;
}
