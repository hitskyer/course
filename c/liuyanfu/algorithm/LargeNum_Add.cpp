#include <iostream>
#include <string>
#include <string.h>
using namespace std;


void LN_Add(string &str1, string &str2, char *result)
{
	int len = str1.size()>str2.size()?str1.size():str2.size();
	int *a = new int[len+1];
	int *b = new int[len+1];
	memset(a,0,len+1);
	memset(b,0,len+1);
	for(int i=str1.size()-1,j=0;i>=0;--i)
	{
		a[j++] = str1[i] - '0';
	}
	for(int i=str2.size()-1,j=0;i>=0;--i)
	{
		b[j++] = str2[i] - '0';
	}
	for(int i=0;i<len;++i)
	{
		b[i] += a[i];
		if(b[i] >=10)
		{
			b[i+1] += b[i]/10;
			b[i]   %= 10;
		}
	}
	int i;
	for(i=len;i>=0 && b[i]==0;--i);
	if(i>=0)
	{
		for(int j=0;i>=0;--i,++j)
		{	
			result[j] = b[i] + '0';
		}
	}
	delete []a;
	delete []b;

}
int main()
{
	string str1,str2;
	cin >> str1 >> str2;
	char result[200] = {'\0'};
	LN_Add(str1,str2,result);
	cout << result << endl;
	return 0;
}
