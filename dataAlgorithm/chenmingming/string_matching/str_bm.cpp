/**
 * @description: 字符匹配BM算法
 * @author: michael ming
 * @date: 2019/6/18 22:19
 * @modified by: 
 */
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
#define SIZE 256    //字符集字符数
void generateBadChar(char *b, int m, int *badchar)//(模式串字符b，模式串长度m，模式串的哈希表)
{
    int i, ascii;
    for(i = 0; i < SIZE; ++i)
    {
        badchar[i] = -1;//哈希表初始化为-1
    }
    for(i = 0; i < m; ++i)
    {
        ascii = int(b[i]);  //计算字符的ASCII值
        badchar[ascii] = i;//重复字符被覆盖，记录的是最后出现的该字符的位置
    }
}
void generateGS(char *b, int m, int *suffix, bool *prefix)
{
    int i, j, k;
    for(i = 0; i < m; ++i)//两个数组初始化
    {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for(i = 0; i < m-1; ++i)//b[0,i]
    {
        j = i;
        k = 0;//公共后缀子串长度(模式串尾部取k个出来，分别比较)
        while(j >= 0 && b[j] == b[m-1-k])//与b[0,m-1]求公共后缀子串
        {
            --j;
            ++k;
            suffix[k] = j+1;
            //相同后缀子串长度为k时，该子串在b[0,i]中的起始下标
            // (如果有多个相同长度的子串，被赋值覆盖，存较大的)
        }
        if(j == -1)//查找到模式串的头部了
            prefix[k] = true;//如果公共后缀子串也是模式串的前缀子串
    }
}
int moveByGS(int j, int m, int *suffix, bool *prefix)//传入的j是坏字符对应的模式串中的字符下标
{
    int k = m - 1 - j;//好后缀长度
    if(suffix[k] != -1)//case1，找到跟好后缀一样的模式子串（多个的话，存的靠后的那个（子串起始下标））
        return j - suffix[k] + 1;
    for(int r = j + 2; r < m; ++r)//case2
    {
        if(prefix[m-r] == true)//m-r是好后缀的子串的长度，如果这个好后缀的子串是模式串的前缀子串
            return r;//在上面没有找到相同的好后缀下，移动r位，对齐前缀到好后缀
    }
    return m;//case3,都没有匹配的，移动m位（模式串长度）
}
int str_bm(char *a, int n, char *b, int m)//a表示主串，长n; b表示模式串,长m
{
    int *badchar = new int [SIZE];//记录模式串中每个字符最后出现的位置
    generateBadChar(b,m,badchar);     //构建坏字符哈希表
    int *suffix = new int [m];
    bool *prefix = new bool [m];
    generateGS(b, m, suffix, prefix);
    int i = 0, j, moveLen1, moveLen2;//j表示主串与模式串匹配的第一个字符
    while(i < n-m+1)
    {
        for(j = m -1; j >= 0; --j)  //模式串从后往前匹配
        {
            if(a[i+j] != b[j])
                break;  //坏字符对应模式串中的下标是j
        }
        if(j < 0)   //匹配成功
        {
            delete [] badchar;
            delete [] suffix;
            delete [] prefix;
            return i;   //返回主串与模式串第一个匹配的字符的位置
        }
        //这里等同于将模式串往后滑动 j-badchar[int(a[i+j])] 位
        moveLen1 = j - badchar[int(a[i+j])];//按照坏字符规则移动距离
        moveLen2 = 0;
        if(j < m-1)//如果有好后缀的话
        {
            moveLen2 = moveByGS(j,m,suffix,prefix);//按照好后缀规则移动距离
        }
        i = i + max(moveLen1,moveLen2);//取大的移动
    }
    delete [] badchar;
    delete [] suffix;
    delete [] prefix;
    return -1;
}

int main()
{
    string a = "abcacabcbcbacabc", b = "cbacabc";
    cout << str_bm(&a[0],a.size(),&b[0],b.size());
    return 0;
}