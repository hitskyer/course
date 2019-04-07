/**
 * @description: 汉诺塔递归问题
 * @author: michael ming
 * @date: 2019/4/7 20:10
 * @modified by:
 */
#include <iostream>
using namespace std;
void hanoi(size_t n, string startP, string middleP, string destP, size_t &counts)
{
    if(n == 1)
    {
        cout << startP << " ---> " << destP << endl;
        counts++;
        return;
    }
    else
    {
        hanoi(n-1, startP, destP, middleP, counts);     //n-1个从开始-->中间
        cout << startP << " ---> " << destP << endl;    //最底下那个开始-->目的地
        counts++;
        hanoi(n-1, middleP, startP, destP, counts);     //n-1个从中间-->目的地
    }
}
int main()
{
    cout << "请输入汉诺塔层数：";
    size_t n, steps = 0;   cin >> n;
    hanoi(n,"a","b","c",steps);
    cout << "共走了 " << steps << " 步。" << endl;
    return 0;
}