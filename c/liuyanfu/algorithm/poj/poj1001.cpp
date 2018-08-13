#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;


void Large_Num_Multi(string &s1,string &s2,char *result)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int a[200] = {0};
	int b[200] = {0};
	int c[200] = {0};
	int temp[200] ={0};
	int index1 = 0,index2 =0;
	int i,j,k;
	int carry1 = 0,carry2 = 0;
	for(i=len1-1,j=0;i>=0;--i)
	{
		if(s1[i]=='.')
		{
			index1 = len1-1-i;
			continue;
		}
		a[j++] = s1[i]-'0';
	}
	for(i=len2-1,j=0;i>=0;--i)
	{
		if(s2[i]=='.')
		{
			index2 = len2-1-i;
			continue;
		}
		b[j++] = s2[i]-'0';
	}
	for(j=0;j<len2-1;++j)
	{
		memset(temp,0,sizeof(temp)/sizeof(int));
		carry1 = 0;
		for(i=0;i<len1-1;++i)
		{
			temp[i+j] = (b[j]*a[i]+carry1)%10;
			carry1 = (b[j]*a[i]+carry1)/10;
		}
		temp[i+j]= carry1;
		int temp1 = 0;
		carry2 = 0;
		for(k=0;k<=j+i;++k)
		{
			temp1 = c[k];
			c[k] = (temp1+temp[k]+carry2)%10;
			carry2 = (temp1+temp[k]+carry2)/10;
		}
		c[k] = carry2;
	}
	int index3 = index1 + index2;
	int flag = 0;
	for(i=0,j=0;i<len1+len2-1;++i)
	{
		if(c[i]==0 && flag ==0)
			continue;
		else 
			flag =1;
		if(flag==1)
		{
			if(i==index3)
			{
				result[j++] = '.';
				result[j++] = c[i] + '0';
			}
			else
			{
				result[j++] = c[i] + '0';
			}
		}
	}
	for(int p =strlen(result)-1;result[p]=='0';--p)
	{
		result[p] = '\0';
	}
	j=strlen(result)-1;i=0;
	while(i<j)
	{
		swap(result[i++],result[j--]);
	}
}
int main()
{
	string s1 ;
	string s2;
	char result[200];
	int n = 0;
	while(cin >> s1 >> n)
	{
		memset(result,0,sizeof(result));
		s2 = s1;
		for(int i =0;i<n-1;++i)
		{
			Large_Num_Multi(s1,s2,result);
			s1 = result;
		}
		cout << result << endl;
		cout << "please input again!" << endl;
	}
	return 0;
}
