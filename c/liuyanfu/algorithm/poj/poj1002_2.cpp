#include <iostream>
#include <string.h>


using namespace std;

int main()
{
	char x1[200] = {'\0'};
	char x2[200] = {'\0'};
	int carry[201] = {0};
	int result[201]= {0};
	int i,j;
	cin >> x1 >> x2;
	int len1 =strlen(x1);
	int len2 =strlen(x2); 
	int lenmax = len1>len2?len1:len2;
	int x11[200] ={0};
	for(i=len1-1,j=0;i>=0;--i)
	{
		x11[j++] = x1[i] - '0';
	}
	int x22[200] = {0};
	for(i=len2-1,j=0;i>=0;--i)
	{
		x22[j++] = x2[i] - '0';
	}
	for(i=0;i<=lenmax-1;++i)
	{
		result[i]= x11[i]+x22[i];
		result[i+1] = 0;
	}
	for(i=0;i<=lenmax;++i)
	{
		carry[i+1] = (result[i]+carry[i])/10;
		result[i]  = (result[i]+carry[i])%10;
	}
	if(result[lenmax]==0)
		i = lenmax -1;
	else 
		i = lenmax;
	for(;i>=0;--i)
		cout << result[i];
	cout << endl;
	return 0;
}
