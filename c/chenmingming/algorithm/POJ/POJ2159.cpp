#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int secretnum = 1;
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
    // cin.ignore(1,'\n');
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
    sort(secrettext.begin(),secrettext.end());
    sort(origintext.begin(),origintext.end());
    for(int i = 0;i != secrettext.size();++i)
    {
        if(secrettext[i] != origintext[i])
        {
            cout << "NO" ;
            return 0;
        }
    }
    cout << "YES" ;
    return 0;
}