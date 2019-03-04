#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

istream& get(istream& in)
{
        int ival;
        while(in>>ival,!in.eof())
        {
                if(in.bad())
                         break;
			 //throw runtime_error("To stream corrupted");
                if(in.fail())
                {
                        cerr<<"bad data,try again"<<endl;
                       // cout<<"bad data, try again"<<endl;
			in.clear(istream::failbit);
                        in.ignore(200,' ');
                        //continue;
                        break;
                 }
                 cout<<ival<<" ";
        }
	
        in.clear();
        return in;      
} 
  
int main()
{
	string fileName, s;
	//读入文件名
	cout<<"enter fileName"<<endl;
	cin>>fileName;
	//调用open_file
	ifstream inFile;
	if(!open_file(inFile, fileName.c_str()))
	{
		cout<<"error:can not open file:"<<fileName<<endl;
		return -1;
	}
	//调用get函数读取文件
	get(inFile);
	inFile.close();

	return 0;
}
