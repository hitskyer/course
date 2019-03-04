#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    char word1, word2;
    int secrettext[26]={0}, origintext[26]={0};
    while(cin.get(word1))
    {
        if(word1 == '\n')
            break;
        if(word1 >= 'A' && word1 <= 'Z')
        {
            ++secrettext[word1-'A'];    //统计每个字符的频次存入数组
        }
        else
        {
            continue;
        }
    }
    while(cin.get(word2))
    {
        if(word2 == '\n')
            break;
        if(word2 >= 'A' && word2 <= 'Z')
        {
            ++origintext[word2-'A'];    //统计每个字符的频次存入数组
        }
        else
        {
            continue;
        }
    }
    sort(secrettext,secrettext+26); // 对频次进行排序
    sort(origintext,origintext+26); // 对频次进行排序
    for(int i = 0;i != 26;++i)
    {
        if(secrettext[i] != origintext[i])
        {
            cout << "NO" ;
            return 0;
        }
    }
    cout << "YES" ; //频次完全一致，则每个字符经过一定平移即可得到第二行的字符串
    return 0;
}