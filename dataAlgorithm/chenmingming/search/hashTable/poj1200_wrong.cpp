/**
 * @description: http://poj.org/problem?id=1200,采用map解题
 * @author: michael ming
 * @date: 2019/5/8 16:14
 * @modified by: 
 */
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;
int main()
{
    size_t sublen, diffchar;
    scanf("%d%d",&sublen,&diffchar);
    map<string, int> substring;
//    char str[16000001];
//    scanf("%s", str);
    string str, substr;
    cin >> str;
    size_t len = str.size();
    for(size_t i = 0, j = i+sublen-1; j < len; i++,j++)
    {
        substr = str.substr(i, sublen);
        substring.insert(pair<string, int>(substr, 1));
    }
    cout << substring.size();
    return 0;
}