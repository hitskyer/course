#include <iostream>
using namespace std;
#include <sys/time.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include <string.h>
const size_t G_BigSize    = 1000000;
const size_t G_SmallSize  = 1000;
const int    G_CycleTimes = 1000;




void  bubSort(size_t dsize,int *arr)
{
        for(size_t i=1;i<dsize;++i){
                for (size_t j=0;j<=dsize-1-i;++j){
                        if(arr[j]>arr[j+1])
                                swap(arr[j],arr[j+1]);//交换
                }
        }
}

void rand4data(int i, size_t dsize, int *arr)
{
    int flag = i%5;
    if (flag == 0)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = i;
        }
    }
    else if (flag == 1)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = (int)dsize - i;
        }
    }
    else if (flag == 2)
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            if (i%5 == 0)
            {
                arr[i] = rand();
            }
            else
            {
                arr[i] = 7;
            }
        }
    }
    else
    {
        for (size_t i = 0; i != dsize; ++i)
        {
            arr[i] = rand();
        }
    }
}


long getCurrentTime()
{
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
}


bool right4sorted(const int *arr, size_t dsize)
{
        for (size_t i = 1; i < dsize; ++i)
        {
                if (arr[i-1] > arr[i])
                {
                        return false;
                }
        }
        return true;
}
void test4sort(size_t dsize, void (*mysort)(size_t dsize, int *arr))
{
        int *arr         = new int[dsize];
        long   total_time = 0;

        for (int i = 0; i != G_CycleTimes; ++i)
        {
                rand4data(i, dsize, arr);

                long start_time = getCurrentTime();
                mysort(dsize, arr);
                long end_time   = getCurrentTime();
                total_time     += end_time - start_time;

                if (!right4sorted(arr, dsize))
                {
                        cerr << "sort for ints failed" << endl;
                        return;
                }
        }
        cout << "You have completed for sort testing!" << endl;
        cout << "And the total time is "
                << float(total_time)/1000000.0 << " seconds." << endl;

        delete [] arr;
        arr = NULL;
}


int main(int argc, char *argv[])
{
        if (argc < 3)
        {
                cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
                return -1;
        }
        else
        {
                size_t dsize = 0;
                if (string(argv[1]) == "small")
                {
                        dsize = G_SmallSize;
                }
                else if (string(argv[1]) == "big")
                {
                        dsize = G_BigSize;
                }
                else
                {
                        cerr << "\t ./" << argv[0] << " type4data(big|small) method4sort(bsort|todo)" << endl;
                        return -2;
                }
                if (string(argv[2]) == "bubSort")
                {
			test4sort(dsize,bubSort);
                }
          }
          return 0;
}

