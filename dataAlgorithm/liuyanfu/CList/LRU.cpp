#include <iostream>
#include <stdio.h>
#include <string>
#include "SingleList.cpp"

using namespace std;

int main()
{
	cout << "\t\t---------------------------------------" << endl;
	
	string web;
	int maxbufsize = 6;
	SingleList<string> slst;
	char ch;
	do
	{
		cout << "\t\tPlease enter you want to browse website" << endl;
		cin >> web;
		SingleList<string>::ListNode TempNode = slst.Find(web);
		if(TempNode == NULL)
		{
			if(slst.GetSize() == maxbufsize)
			{
				slst.RemoveAt(slst.GetTailNode());
			}
			slst.AddHead(web);
		}
		else
		{
			if(TempNode != slst.GetHeadNode())
			{
				string stemp = TempNode->data;
				slst.RemoveAt(TempNode);
				slst.AddHead(stemp);
			}
		}
		cout << "Do you want to continue browse£º ¡¾Y/N¡¿" << endl;
		fflush(stdin);
		ch = getchar();
	}while(ch == 'Y' || ch == 'y');
	
	return 0;
}