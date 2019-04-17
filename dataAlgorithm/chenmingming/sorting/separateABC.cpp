/**
 * @description: 分离开大小写字符，但不改变相对顺序（桶排序思想）
 * @author: michael ming
 * @date: 2019/4/13 18:25
 * @modified by: 
 */
#include <iostream>
#include <time.h>
using namespace std;
void randomABCandNum(char *ch, size_t N)    //生成随机大小字母和数字
{
    char tempch[26+26+10];
    int i, j, k, randIndex;
    for(i = 0; i < 26; )
        tempch[i++] = 'A' + i;
    for(j=0; j < 26; j++)
        tempch[i++] = 'a' + j;
    for(k=0; k < 10; k++)
        tempch[i++] = '0' + k;
    srand((unsigned)time(NULL));
    for(int x = 0; x < N; ++x)
    {
        randIndex = rand()%62;
        ch[x] = tempch[randIndex];
        cout << ch[x] << " ";
    }
    cout << endl;
}
void countseparate(char *ch, size_t N)
{
    size_t lowerNum = 0, upNum = 0, digitNum = 0;
    for(int i = 0; i < N; ++i)  //计数，看每种类型有多少个
    {
        if(ch[i] >= 'a' && ch[i] <= 'z')
            lowerNum++;
        else if(ch[i] >= 'A' && ch[i] <= 'Z')
            upNum++;
        else
            digitNum++;
    }
    size_t lowerIndex = 0, upIndex = lowerNum, digitIndex = lowerNum+upNum;//每种类型的起始下标
    int *temp = new int [N];
    for(int i = 0; i < N; ++i)  //按区间写入
    {
        if(ch[i] >= 'a' && ch[i] <= 'z')
            temp[lowerIndex++] = ch[i];
        else if(ch[i] >= 'A' && ch[i] <= 'Z')
            temp[upIndex++] = ch[i];
        else
            temp[digitIndex++] = ch[i];
    }
    for(int i = 0; i < N; ++i)
    {
        ch[i] = temp[i];  //写回原数组
    }
    delete [] temp;
    temp = NULL;
}
void printArr(char* arr, size_t N)  //打印字符数组
{
    for(int i = 0; i < N; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "请输入N，程序生成大小写字母和数字的组合随机序列：";
    size_t N;
    cin >> N;
    char ch[N];
    randomABCandNum(ch, N);
    cout << "程序现将字符按[小写字母][大写字母][数字]排列，内部顺序不变：" << endl;
    countseparate(ch, N);
    printArr(ch, N);
}
