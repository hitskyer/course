/**
 * @description: 计算子串的种数
 * @author: michael ming
 * @date: 2019/5/8 17:20
 * @modified by: 
 */
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;
void chartoint(string &str, int *num)   //把字符中出现过的字符转成1开始的数字
{
    int value = 1;
    int len = str.size();
    for(int i = 0; i < len; ++i)
    {
        if(num[str[i]] == 0)
            num[str[i]] = value++;
    }
}
size_t hashfunc(int i, int j, int m, int *num, string &str)    //计算子串hash值
{
    int hashValue = 0;
    for(int k = i; k <= j; ++k)
        hashValue = hashValue*m + num[str[k]];
    return hashValue;
}
int main()
{
    const unsigned int max = 16000001;
    int num[300] = {0};
    size_t *hash = new size_t[max];
    memset(hash, 0, sizeof(hash));
    int sublen, m;
    int result = 0;
    string str;
    cin >> sublen >> m >> str;
    chartoint(str, num);
    for(int i = 0; i <= str.size()-sublen; ++i)
    {
        size_t hashValue = hashfunc(i, i+sublen-1, m, num, str)%max;
        if(!hash[hashValue])
        {
            result++;
            hash[hashValue] = 1;
        }
    }
    cout << result << endl;
    delete[] hash;
    return 0;
}