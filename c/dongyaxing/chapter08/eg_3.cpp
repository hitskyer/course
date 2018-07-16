#include<iostream>
#include<fstream>
#include<string>

using namespace std;

std::istream & get(istream & in)
{
        int ival;
        while(in>>ival,!in.eof())
        {
                if(in.bad())
                        //throw runtime_error("to stream corrupted");
                if(in.fail())
                {
                        std::cerr<<"bad data,try again"<<endl;
                        in.clear(istream::failbit);
                        in.ignore(200,' ');
                        continue;
                }
                std::cout<<ival<<" ";
        }
        in.clear(istream::failbit);
	return in;
}

int main()
{

//	double dval;
//	get(cin);
//	cin>>dval;
//	cout<<dval<<endl;


	string fileName;
	cout<<"Enter file name:"<<endl;
	cin>>fileName;
	ifstream inFile(fileName.c_str());
	if(!inFile)
	{
		cerr<<"error:can not open input file:"<<fileName<<endl;
	}
	get(inFile);

	return 0;
}
