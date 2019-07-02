/**
 * @description: 贪心应用poj2453
 * @author: michael ming
 * @date: 2019/7/2 20:46
 * @modified by:
 */
#include <cstring>
#include <iostream>
using namespace std;
 int calc(int num, int *binarynum)
{
    int i = 0, j, k, value = 0;
    while(num != 0)
    {
        binarynum[i++] = num % 2;//数组存储的是该数的二进制的反序序列
        num = num/2;
//        cout << binarynum[i-1] << " ";
    }
    k = i;//k记录最后一个有效位的下一位
    for(i = 0; i < k; ++i)
    {
        if(binarynum[i] == 0)
            continue;//找到为1的i
        if(binarynum[i+1] == 0)//如果i的下一个为0
        {
            swap(binarynum[i],binarynum[i+1]);//交换完成寻找
            break;
        }
        for(j = i; j >= 1; --j)//否则将i处的1换到最开始
        {
            swap(binarynum[j],binarynum[j-1]);
        }
    }
    for(i = k; i >= 0; --i)//计算对应的10进制数值
        //最后一位k-1可能进位到k，所以i从k开始
        value = value*2 + binarynum[i];
    return value;
}
int main()
{
	int binarynum[30];//数据大小不会超过30位2进制
	int num;
	while(cin >> num && num)
    {
	    memset(binarynum,0,30*sizeof(int));
	    cout << calc(num,binarynum) << endl;
    }
    return 0;
}