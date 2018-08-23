#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int secretnum = 1;	//移动的位数（每个都一样）
    char word1,word2;
    vector<char> secrettext,origintext;
    while(cin.get(word1))
    {
        if(word1 == '\n')
            break;
        if(word1 >= 'A' && word1 <= 'Z')
        {
            word1 = word1 - secretnum;
            if(word1 < 'A')
                word1 = word1 + 26;
            secrettext.push_back(word1);
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
            origintext.push_back(word2);
        }
        else
        {
            continue;
        }
    }
    sort(secrettext.begin(),secrettext.end());//字母升序排序
    sort(origintext.begin(),origintext.end());//字母升序排序
    for(int i = 0;i != secrettext.size();++i)
    {
        if(secrettext[i] != origintext[i])
        {
            cout << "NO" ;
            return 0;
        }
    }
    cout << "YES" ;//都升序排列后，每一位都相等则ok（题目没说都移动同样位数，解答错误）
    return 0;
}