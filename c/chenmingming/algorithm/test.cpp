#include<iostream>
using namespace std;
void sort(int *arr)
{
	int dsize = 11;
	for(int i=0;i <= 10;++i)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;

	void merge(int *arr,size_t left,size_t mid,size_t right)
{
        int len = right - left + 1;
        int *temp = new int [len];
        size_t index = 0;
        size_t i = left, j = mid + 1;
        while(i <= mid && j <= right)
        {
                temp[index++] = arr[i]<= arr[j]? arr[i++]: arr[j++];
        }
        while(i <= mid)         {temp[index++]= arr[i++];}
        while(j <= right)       {temp[index++]= arr[j++];}
        for(int k = 0;k< len;++k)
        {
                arr[left++ ]= temp[k];
        }
        delete [] temp;
        temp = NULL;
}

void divide(int *arr,size_t left,size_t right)
{
        if(left == right)
                return;
        size_t mid = (left+right)/2;

        divide(arr,left,mid);
        divide(arr,mid+1,right);
        merge(arr,left,mid,right);
}

        size_t left = 0, right = dsize-1;
        divide(arr,left,right);


	for(int i=0;i <= 10;++i)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;


int main()
{
	int arr1[]={6,5,8,1,3,9,6,7,4,2,5};
	int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
	int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
	int arr4[]={1,1,1,1,1,1,1,1,1,1,1};
	sort(arr1);
	sort(arr2);
	sort(arr3);
	sort(arr4);
	return 0;
}
