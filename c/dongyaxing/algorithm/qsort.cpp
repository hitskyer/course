#include<iostream>

using namespace std;
void swap(int *arr, int low, int high)
{
        int temp;
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
}

int partition(int *arr, int low, int high)
{
        int pivotkey;  //用子表的第一个记录作枢轴记录
        pivotkey=arr[low];
        while(low<high) //从表的两端交替向中间扫描
        {
                while(low<high && arr[high]>=pivotkey)   //左侧不能越过右侧，且右侧值大于枢轴值，
                { high--;}                             //标兵high往低位走，--
                swap(arr,low,high);                    //若high标兵直到某位，arr[high]<povitkey
						       //交换low 与high 对应位置的值

		while(low<high && arr[low]<=pivotkey)   //左侧不能越过右侧，且右侧值大于枢轴值，
                { low++;}                              //标兵low往高位走，++
						       //若low标兵直到某位，arr[low]>povitkey
                swap(arr,low,high);                    //交换low 与high 对应位置的值
        }
        return low;                                    //返回枢轴所在位置
}

void qsort(int *arr, int low, int high)
{
        int pivot;
        if(low<high)
        {
                pivot = partition(arr,low,high);
                qsort(arr,low,pivot-1);
                qsort(arr,pivot+1,high);
        }
}

void quicksort(int *arr, size_t length)
{
	qsort(arr, 0, length-1);
}


int main()
{
	int a[20]={2,4,56,3,23,6,8,5,98,96,46,43,64,37,26,38,46,45,55,77};
	quicksort(a, sizeof(a)/sizeof(a[0]));
	for(int i=0;i<20;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}



