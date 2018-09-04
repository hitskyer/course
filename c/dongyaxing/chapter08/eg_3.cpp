#include<iostream>
#include<fstream>
//#include<cstdlib>      
//#include<string>
#include<stdexcept>  //linux下，此头文件必须引用，否则runtime_error() 提示未声明
using namespace std;

istream& get(istream& in)
{
        int ival;
        while(in>>ival,!in.eof())
        {
                if(in.bad())
                {        throw runtime_error("To stream corrupted");}
                if(in.fail())
                {
                        cerr<<"bad data,try again"<<endl;
                        in.clear(istream::failbit);
                        in.ignore(200,' ');
                        //continue;
                        break;
		}
                cout<<ival<<" ";
        }
        in.clear(istream::failbit);
	return in;
}

int main()
{
	cout<<"只能输入整数，小数或字符串，则退出"<<endl;
	double dval;
	get(cin);
	cin>>dval;
	cout<<dval<<endl;
	return 0;
}
