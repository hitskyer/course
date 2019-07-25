/**
 * @description: 莱文斯坦距离，回溯
 * @author: michael ming
 * @date: 2019/7/25 1:25
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
void lwstBT(string &a, string &b, int i, int j, int dist, int &minDist)
{
    if(i == a.size() || j == b.size())
    {
        if(i < a.size())
            dist += (a.size()-i);
        if(j < b.size())
            dist += (b.size()-j);
        if(dist < minDist)
            minDist = dist;
        return;
    }
    if(a[i] == b[j])// 两个字符匹配
    {
        lwstBT(a,b,i+1,j+1,dist,minDist);
    }
    else// 两个字符不匹配
    {
        lwstBT(a,b,i+1,j,dist+1,minDist);// 删除 a[i] 或者 b[j] 前添加一个字符
        lwstBT(a,b,i,j+1,dist+1,minDist);// 删除 b[j] 或者 a[i] 前添加一个字符
        lwstBT(a,b,i+1,j+1,dist+1,minDist);// 将 a[i] 和 b[j] 替换为相同字符
    }
}
int main()
{
    int minDist = INT_MAX;
    string a = "mitcmu", b = "mtacnu";
    lwstBT(a,b,0,0,0,minDist);
    cout << "莱文斯坦距离：" << minDist << endl;
}