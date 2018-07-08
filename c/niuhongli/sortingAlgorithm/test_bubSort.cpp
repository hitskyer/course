#include<iostream>
using namespace std;


void  bubSort(int *array, size_t bsize)
{
	for(size_t i=1;i<bsize;++i){
		for (size_t j=0;j<=bsize-1-i;++j){
			if(array[j]>array[j+1])
				swap(array[j],array[j+1]);//交换
		}
	}
}	

