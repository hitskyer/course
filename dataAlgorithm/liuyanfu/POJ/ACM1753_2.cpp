#include<iostream>

using namespace std;

bool isPureColor(char* arr, int n)
{
	for(int i = 0; i < n-1; ++i)
	{
		if(arr[i] != arr[i+1])
			return false;
	}
	return true;
}

char change(char ch)
{
	return ch == 'w'?'b':'w';
}


void flip(char* arr, int index)
{
	arr[index] = change(arr[index]);
	int row = index / 4;
	int column = index % 4;
	if(column < 3)
		arr[index+1] = change(arr[index+1]);
	if(column > 0)
		arr[index-1] = change(arr[index-1]);
	if(row < 3)
		arr[index+4] = change(arr[index+4]);
	if(row > 0)
		arr[index-4] = change(arr[index-4]);
}


int flipToPure_recu(char* arr, bool* vist, int n, int curStep, int nStep)
{
	char b[16];
	bool v[16];
	memcpy(v, vist, n);
	for(int i = 0; i < n; ++i)
	{
		memcpy(b, arr, n);
		if(v[i] == false)
		{
			v[i] = true;
			flip(b, i);
			if(curStep == nStep)
			{
				if(isPureColor(b, n))
					return nStep;
			}
			else
			{
				int rtn = flipToPure_recu(b, v, n, curStep + 1, nStep);
				if(rtn > 0)
					return rtn;
			}
		}
	}
	return -1;
}

int flipToPureColor(char* arr, int n, bool* vist)
{
	if(isPureColor(arr, n))
		return 0;
	int rtn;
	for(int i = 1; i < 16; ++i)
	{
		rtn = flipToPure_recu(arr, vist, n, 1, i);
		if(rtn > 0)
			return rtn;
	}
	return -1;
}

void entryData(char* arr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}

int main()
{
	char arr[16];
	bool visited[16] = {0};
	entryData(arr, 16);
	int rtn = flipToPureColor(arr, 16, visited);
	if(rtn == 0)
		cout << 0 << endl;
	else if(rtn > 0)
		cout << rtn << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}