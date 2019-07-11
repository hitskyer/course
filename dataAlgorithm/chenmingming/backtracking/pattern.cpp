/**
 * @description: 正则表达式匹配（回溯）
 * @author: michael ming
 * @date: 2019/7/11 0:07
 * @modified by: 
 */
#include <string>
#include <iostream>

using namespace std;
class Pattern
{
    bool matched;
    string pattern;//正则表达式
    int plen;//正则表达式长度

public:
    Pattern(const string &pat, int len)
    {
        matched = false;
        pattern = pat;
        plen = len;
    }
    bool match(string text, int tlen)//文本串及长度
    {
        matched = false;
        rmatch(0,0,text,tlen);
        return matched;
    }
private:
    void rmatch(int ti, int pj, string text, int tlen)
    {
        if(matched)//已经匹配，停止递归
            return;
        if(pj == plen)//正则表达式到结尾了
        {
            if(ti == tlen)//文本串也到结尾了
                matched = true;
            return;
        }
        if(pattern[pj] == '*')// * 匹配任意个字符
        {
            for(int k = 0; k <= tlen-ti; ++k)
                rmatch(ti+k,pj+1,text,tlen);
        }
        else if(pattern[pj] == '?')//匹配0个或者1个字符
        {
            rmatch(ti,pj+1,text,tlen);
            rmatch(ti+1,pj+1,text,tlen);
        }
        else if(ti < tlen && pattern[pj] == text[ti])//纯字符匹配才行
            rmatch(ti+1,pj+1,text,tlen);
    }

};

int main()
{
    Pattern Pat("xia?mi",6);
    cout << Pat.match("xiaomi",6);
    return 0;
}