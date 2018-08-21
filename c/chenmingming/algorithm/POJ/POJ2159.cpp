#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int secretnum = 1;
    char word1,word2;
    vector<char> secrettext,origintext;
    while(1)
    {
    	cin >> word1;
    	if(word1 == 32)
    		break;
        word1 = word1 - secretnum;
        if(word1 < 'A')
            word1 = word1 + 26;
        secrettext.push_back(word1);
    }
    while(cin.get(word2))
    {
        origintext.push_back(word2);
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