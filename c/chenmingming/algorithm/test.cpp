#include<iostream>
using namespace std;
size_t parr [2];
void selectmedianofthree(int *arr, size_t left, size_t right)
{
        size_t mid = left + (right - left)/2;
        if(arr[mid]>arr[right])
        {
                swap(arr[mid],arr[right]);
        }
        if(arr[left]>arr[right])
        {
                swap(arr[left],arr[right]);
        }
        if(arr[mid]>arr[left])
        {
                swap(arr[mid],arr[left]);
        }
}
size_t partion(int *arr, size_t left, size_t right)
{
        selectmedianofthree(arr,left,right);
        
        size_t lessPnum = 0, equalPnum=1, largePnum=0;
        int pval = arr[left];
        cout << "pval " << pval << endl;
        int *temp = new int [right-left+1];
        for(int i = left+1;i <= right;++i )
        {
                if(pval > arr[i])
                {
                        temp[lessPnum++] = arr[i];
                }
                if(pval < arr[i])
                {
                        temp[right-largePnum++] = arr[i];
                }
        }
        for(int i = left + lessPnum; i <= right - largePnum; ++i)
        {
                temp[i] = pval;
        }
        for(int i = left, j=0; i <= right; ++i)
        {
                arr[i] = temp[j++];
        }
        delete [] temp;
        temp = NULL;
        parr[0]=lessPnum;
        parr[1]=largePnum;
        cout << "lessPnum " << parr[0] << endl;
        cout << "largePnum " << parr[1] << endl;
}
void qsort(int *arr, size_t left, size_t right)
{
        cout << "left " << left << " right " << right << endl;
        if(left >= right)
        {       return;}
        partion(arr,left,right);
        size_t pl_index = left + parr[0];
        size_t pr_index = right - parr[1];
        cout << "left " << left << "pl_index " << pl_index 
        <<" pr_index " << pr_index << " right " << right << endl;

        if(pr_index == right)
        {       qsort(arr,left,pl_index-1);
        }
        else if(pl_index == left)
        {       qsort(arr,pr_index+1,right);
        }
        else    
        {
                qsort(arr,left,pl_index-1);
                qsort(arr,pr_index+1,right);
        }
}

void sort(int *arr)
{
	int dsize = 11;
	for(int i=0;i <= 10;++i)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;

	

        size_t left = 0, right = dsize-1;
        qsort(arr,left,right);


	for(int i=0;i <= 10;++i)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;

}
int main()
{
	int arr1[]={6,5,8,1,3,6,6,7,4,2,5};
	int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
	int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
	int arr4[]={2,1,1,1,1,1,1,1,1,1,1};
	sort(arr1);
	sort(arr2);
	sort(arr3);
	sort(arr4);
	return 0;
}
