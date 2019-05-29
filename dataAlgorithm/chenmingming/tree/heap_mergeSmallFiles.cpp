/**
 * @description: 合并有序小文件
 * @author: michael ming
 * @date: 2019/5/29 22:10
 * @modified by: 
 */
#include "heap.cpp"
int main()
{
    int file0[10] = {11, 21, 31, 41, 51, 61, 71, 81, 91, 101};
    int file1[8] = {1, 2, 3, 4, 5, 6, 7, 80};
    int file2[9] = {13, 23, 33, 43, 53, 63, 73, 83, 93};
    int file3[10] = {12, 22, 32, 42, 52, 62, 72, 82, 92, 102};
    int file4[7] = {15, 25, 35, 45, 55, 65, 72};
    int len0 = 10, len1 = 8, len2 = 9, len3 = 10, len4 = 7;
    int i0, i1, i2, i3, i4, j;
    i0 = i1 = i2 = i3 = i4 = j = 0;
    const int new_len = len0+len1+len2+len3+len4;
    int bigFile[new_len];
    MinHeap intheap(5);
    intheap.insert(file0[i0]);
    intheap.insert(file1[i1]);
    intheap.insert(file2[i2]);
    intheap.insert(file3[i3]);
    intheap.insert(file4[i4]);
    int top;
    while(i0+i1+i2+i3+i4 < new_len-5 || intheap.heapsize())
    {
        top = intheap.getMin();
        bigFile[j++] = top;
        intheap.delMin();
        if(i0 < len0-1 && top == file0[i0])   //可以用list做，就不用查找最小的是哪个文件的
        {
            intheap.insert(file0[++i0]);
        }
        else if(i1 < len1-1 && top == file1[i1])
        {
            intheap.insert(file1[++i1]);
        }
        else if(i2 < len2-1 && top == file2[i2])
        {
            intheap.insert(file2[++i2]);
        }
        else if(i3 < len3-1 && top == file3[i3])
        {
            intheap.insert(file3[++i3]);
        }
        else if(i4 < len4-1 && top == file4[i4])
        {
            intheap.insert(file4[++i4]);
        }
    }
    for(i0 = 1, j = 0; j < new_len; i0++,++j)
    {
        cout << bigFile[j] << " ";
        if(i0%10 == 0)
            cout << endl;
    }
    return 0;
}