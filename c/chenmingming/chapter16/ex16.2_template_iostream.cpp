#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
template <typename T1,typename T2>
T1& print(T1 &s, T2 val)
{
	s << val;
	return s;
}

int main()
{
	double dval = 0.88;
	float fval = -12.3;
	string oristr = "this is a test", desstr;
	ostringstream oss(desstr);
	ofstream outfile("result.txt");
	//写至cout
	print(cout,-3) << endl;
	print(cout,dval) << endl;
	print(cout,fval) << endl;
	print(cout,oristr) << endl;
	//写至文件
	print(outfile,-3) << endl;
	print(outfile,dval) << endl;
	print(outfile,fval) << endl;
	print(outfile,oristr) << endl;
	outfile.close();
	//写至stringstream
	print(oss,-3) << endl;
	print(oss,dval) << endl;
	print(oss,fval) << endl;
	print(oss,oristr) << endl;
	//将stringstream中的字符串输出到cout
	cout << oss.str() << endl;
	return 0;
}