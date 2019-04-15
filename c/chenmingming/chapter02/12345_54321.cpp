#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int arr[100] = {0};
	int classroom = 5, flag = 0;
	while(classroom)
	{
		if(flag%2 == 0)
		{
			while(classroom)
			{	
				cout << 5-classroom+1 << " ";
				classroom--;
			}
			flag++;
		}
		else
		{
			while(classroom)
			{
				cout << classroom-- << " ";
			}
			flag--;
		}
		if(classroom == 0)
			classroom = 5;
		cout << endl;
	}
}