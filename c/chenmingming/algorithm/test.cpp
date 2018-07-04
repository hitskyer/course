#include<iostream>
using namespace std;
size_t parr [2];
int cyctimes=0;
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

    size_t lessPnum = 0, largePnum=0;
    int pval = arr[left];
//    cout << "pval " << pval << endl;
    int *temp = new int [right-left+1];
    int tempLindex=0, tempRindex = right-left;
    for(int i = left+1; i <= right; ++i)
    {
        if(pval > arr[i])
        {
            temp[tempLindex++] = arr[i];
            ++lessPnum;
        }
        if(pval < arr[i])
        {
            temp[tempRindex--] = arr[i];
            largePnum++;
        }
    }
    for( ; tempLindex <= tempRindex; ++tempLindex)
    {
        temp[tempLindex] = pval;
    }
    for(int i = left, j=0; i <= right; ++i)
    {
        arr[i] = temp[j++];
//        cout << arr[i] << " " ;
    }
    delete [] temp;
    temp = NULL;
    parr[0]=lessPnum;
    parr[1]=largePnum;
//    cout << "lessPnum " << parr[0] << endl;
//    cout << "largePnum " << parr[1] << endl;
}
void qsort(int *arr, size_t left, size_t right)
{
//    cout << "left " << left << " right " << right << endl;
    if(left >= right)
    {
        return;
    }
    else if(right-left == 1)
    {
        if(arr[left]>arr[right])
        {        swap(arr[left], arr[right]);
//            cout << "cyctimes "<< ++cyctimes << endl;
        }

    }
    else
    {
//        cout << "cyctimes "<< ++cyctimes << endl;
        partion(arr,left,right);
        size_t pl_index = left + parr[0];
        size_t pr_index = right - parr[1];
//        cout << "left " << left << "pl_index " << pl_index
//             <<" pr_index " << pr_index << " right " << right << endl;

        if(pr_index == right && pl_index != left)
        {       qsort(arr,left,pl_index-1);
        }
        else if(pl_index == left && pr_index != right)
        {       qsort(arr,pr_index+1,right);
        }
        else if(pl_index == left && pr_index == right)
        {
            return;
        }
        else
        {
            qsort(arr,left,pl_index-1);
            qsort(arr,pr_index+1,right);
        }
/*        for(int i=0;i <= 10;++i)
        {
            cout << arr[i]<< " ";
        }
*/    
    }
}

void sort(int *arr)
{
    int dsize = 11;
    for(int i=0;i <= 10;++i)
    {
        cout << arr[i] << " ";
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
    int arr1[]={6,5,7,1,3,6,6,8,4,2,5};
    int arr2[]={1,2,3,4,5,6,7,8,9,10,11};
    int arr3[]={11,10,9,8,7,6,5,4,3,2,1};
    int arr4[]={2,1,1,1,1,1,1,1,1,1,1};
    int arr5[]={1,1,1,1,1,1,1,1,1,1,1};
	int *p = arr1;
    sort(p);
    sort(arr2);
    sort(arr3);
    sort(arr4);
    sort(arr5);
    return 0;
}
