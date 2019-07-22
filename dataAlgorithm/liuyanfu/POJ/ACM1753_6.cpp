#include <iostream>
#include <math.h>
using namespace std;
int arr[16];
int ans = 17;
bool isPureColor()
{
	for(int i = 0; i < 15; ++i)
	{
		if(arr[i] != arr[i+1])
			return false;
	}
	return true;
}


void flip(int index)
{
	arr[index] = !arr[index];
	int row = index / 4;
	int column = index % 4;
	if(column < 3)
		arr[index+1] = !arr[index+1];
	if(column > 0)
		arr[index-1] = !arr[index-1];
	if(row < 3)
		arr[index+4] = !arr[index+4];
	if(row > 0)
		arr[index-4] = !arr[index-4];
}

void flipToPure_recu(int nPos, int nTimes)
{
	if(isPureColor())
	{
		ans = min(nTimes, ans);
		return;
	}
	if(nPos > 15)
		return;
	flipToPure_recu(nPos + 1, nTimes);
	flip(nPos);
	flipToPure_recu(nPos + 1, nTimes + 1);
	flip(nPos);
	return;
}

void entryData(int n)
{
	char ch;
	for(int i = 0; i < n; ++i)
	{
		cin >> ch;
		if(ch == 'w')
			arr[i] = 1;
		else if(ch == 'b')
			arr[i] = 0;
	}
}

int main()
{
	entryData(16);
	if(isPureColor())
	{
		cout << 0;
		return 0;
	}
	flipToPure_recu(0,0);
	if(ans == 17)
		cout << "Impossible";
	else
		cout << ans;
	return 0;
}