#include<iostream>
#include<string>
using namespace std;
int main()
{
	char currch,prech='\0'; 
	int ffc=0,flc=0,fic=0;
	while(cin>>currch)
	{
	if(prech=='f')
	{	switch(currch)
		{
		case 'f':
			++ffc;
			break;
		case 'l':
			++flc;
			break;
		case 'i':
			++fic;
			break;
		}
		prech='\0';
	}
	else
	prech=currch;
	}
	cout<<"ff="<<ffc<<endl;
	cout<<"fl="<<flc<<endl;
	cout<<"fi="<<fic<<endl;
	return 0;
}
