/**
 * @description: 桶排序，将数据按规则分组，对各小组再分别排序
 * @author: michael ming
 * @date: 2019/4/12 23:55
 * @modified by: 
 */
#include <unordered_map>
void bucketsort(int *arr, size_t n)
{
    if(n < 2)
        return;
    int maxVal = arr[0], minVal = arr[0];
    for(int i = 0; i < n; ++i)
    {
        maxVal = maxVal > arr[i] ? maxVal : arr[i];
        minVal = minVal < arr[i] ? minVal : arr[i];
    }
    if(maxVal == minVal)
        return;
    else
    {
        int bucket = 1000;
        int space = (maxVal-minVal)/bucket +1;
        int *numsOfEveryBucket = new int [bucket]();
        int *endPosOfEachBucket = new int [bucket]();
        for(size_t i = 0; i < n; ++i)
        {
            ++numsOfEveryBucket[(arr[i]-minVal)/space];
            ++endPosOfEachBucket[(arr[i]-minVal)/space];
        }
        for(int i = 1; i < bucket; ++i)
            endPosOfEachBucket[i] += endPosOfEachBucket[i-1];
        int *temp = new int [n];
        for(size_t i = 0; i < n; ++i)
            temp[--endPosOfEachBucket[(arr[i]-minVal)/space]] = arr[i];
        for(size_t i = 0; i < bucket; ++i)
            if(numsOfEveryBucket[i] > 1)
                quicksort(&temp[endPosOfEachBucket[i]], numsOfEveryBucket[i]);
        for(size_t i = 0; i < n; ++i)
            arr[i] = temp[i];
        delete[]numsOfEveryBucket;
        delete[]endPosOfEachBucket;
        delete[]temp;
        numsOfEveryBucket = NULL;
        endPosOfEachBucket = NULL;
        temp = NULL;
    }
}