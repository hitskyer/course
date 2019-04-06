/**
 * @description: 39个台阶，一次走1步或2步，左脚出发，要求右脚到达
 * @author: michael ming
 * @date: 2019/4/6 18:17
 * @modified by: 
 */
#include <iostream>
#include <map>
using namespace std;
//void recursion(const size_t &targetStairs, size_t steps, size_t stairsWalkAway, size_t &ways)
//{   //暴力搜索版，当n很大时，时间很长
//    if(stairsWalkAway > targetStairs)
//        return;
//    else if(stairsWalkAway == targetStairs && steps%2 == 0)
//    {
//        ways++;
//        return;
//    }
//    else
//    {
//        recursion(targetStairs, steps+1, stairsWalkAway+1, ways);
//        recursion(targetStairs, steps+1, stairsWalkAway+2, ways);
//    }
//}
//int main()
//{
//    size_t stairs = 0, steps = 0, stairsWalkAway = 0, ways = 0;
//    cout << "请输入台阶个数：" << endl;
//    cin >> stairs;
//    recursion(stairs, steps, stairsWalkAway, ways);
//    cout << "左脚出发，右脚到达的方案有：" << ways << " 种。" << endl;
//    return 0;
//}

size_t cal(size_t n,  size_t stepWalkAway)
{
    if(n==1)
    {
        if(stepWalkAway%2 == 0)
            return 0;   //只剩一步了，如果走过了偶数步，那就是右脚达到，不可能了，0
        return 1;
    }
    else if(n==2)   //n = 2 时，不论什么情况，大家都只有1种可能，使得右脚到达
    {
        return 1;
    }
    else
    {
        return cal(n-1,stepWalkAway+1)+cal(n-2,stepWalkAway+1);   //递归调用函数
    }
}
int main()
{
    size_t n, stepWalkAway = 0;
    cout << "请输入你要走的台阶数 n :" ;
    cin >> n;
    cout << "左脚开走，右脚走到有 " << cal(n,stepWalkAway) << " 种方案。" << endl;
    return 0;
}