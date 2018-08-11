#include <iostream>

using namespace std;

void merges(int *arr,int left, int mid, int right)
{
	int *p = new int[right-left+1];
	int lf = left;
	int rg = mid+1;
	int first = left;
	while(lf<= mid && rg <=right)
	{
		if(arr[lf]<=arr[rg])
		{
			p[first++] = arr[lf++];
		}
		else 
		{
			p[first++] = arr[rg++];
		}
	}
	while(lf<=mid)
	{
		p[first++] = arr[lf++];
	}
	while(rg<=right)
	{
		p[first++] = arr[rg++];
	}
	for(int i =left;i<=right;++i)
	{
		arr[i] = p[i];
	}
}

void divide(int *arr,int left, int right)
{
	if(left >= right)
	{
		return;
	}
	else if(right - left == 1)
	{
		if(arr[left]>arr[right])
		{
			int temp = arr[left];
			arr[left]= arr[right];
			arr[right]= temp;
		}
		return;
	}
	int lf = left;
	int rg = right;
	int mid= (right+left)/2;
	divide(arr,lf,mid);
	divide(arr,mid+1,rg);
	merges(arr,left,mid,right);
}

void mgsort(int *arr,int dsize)
{
	divide(arr,0,dsize-1);
}

int main()
{
	int arr[10] = {12,33,44,5,21,3,45,11,42,10};
	mgsort(arr,10);
	for(int i=0;i<10;++i)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
