#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define LEN 200

string Multi(string s1, string s2)
{
	 string tmp(LEN,'0');
	 int carrers = 0;
	 int answers = 0;
	 unsigned int i = 0,j = 0;
	 for(i=0;i<s1.length();++i)
	 {
		 carrers = 0;
		 for(j=0;j<s2.length();++j)
		 {
			 answers = ((s1.at(i)-'0')*(s2.at(j)-'0')+(tmp[i+j]-'0')+carrers)%10;
			 carrers = ((s1.at(i)-'0')*(s2.at(j)-'0')+(tmp[i+j]-'0')+carrers)/10;
			 tmp[i+j]= answers + '0';
		 }
		 if(carrers!=0)
		 {
			 tmp[i+j] = carrers + '0';
		 }
	 }
	 tmp = tmp.substr(0,i+j);
	 return tmp;
}

string expo(string s1, int time)
{
	if(time == 1)
	{
		return s1;
	}
	else
	{
		return Multi(s1,expo(s1,time-1));		 
	}

}

int main()
{
	string s;
	int  n   = 0;
	while(cin>>s>>n)
	{
		int end = s.length()-1;
		int beg = 0;
		int pos = s.find('.');
		while(beg <=end && s.at(beg)== 0)
		{
			++beg;
		}
		if(pos!=-1)
		{
			while(end>=0 && s.at(end)== 0)
			{
				--end;
			}
		}
		s=s.substr(beg,end-beg+1);
		pos = s.find('.');
		if(pos!=-1)
		{
			int len = s.length();
			s.erase(pos,1);
			pos = n*(len-1-pos);
		}
		reverse(s.begin(),s.end());
		end = 0;
		string result = expo(s,n);
		if(pos!=-1)
		{
			result.insert(pos,1,'.');
			while(result.at(end)=='0')
			{
				++end;
			}
			if(result.at(end)=='.')
			{
				++end;
			}
		}
		beg = result.length()-1;
		while(beg>=0 && result.at(beg)=='0')
		{
			--beg;
		}
		if(beg<end)
		{
			result = "0";
		}
		else
		{
			result = result.substr(end,beg-end+1);
			reverse(result.begin(),result.end());
		}
		cout << result << endl;
	}
	
	return 0;
}
