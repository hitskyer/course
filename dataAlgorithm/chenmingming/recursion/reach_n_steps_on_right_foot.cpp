/**
 * @description: 39个台阶，一次走1步或2步，左脚出发，要求右脚到达
 * @author: michael ming
 * @date: 2019/4/6 18:17
 * @modified by: 
 */
#include <iostream>
#include <map>
using namespace std;
//void recursion(const unsigned long &targetStairs, unsigned long steps, unsigned long stairsWalkAway, unsigned long &ways)
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
//    unsigned long stairs = 0, steps = 0, stairsWalkAway = 0, ways = 0;
//    cout << "请输入台阶个数：" << endl;
//    cin >> stairs;
//    recursion(stairs, steps, stairsWalkAway, ways);
//    cout << "左脚出发，右脚到达的方案有：" << ways << " 种。" << endl;
//    return 0;
//}
//------------------------------------------------------------------------------
//unsigned long cal(unsigned long n,  unsigned long stepWalkAway)  //递归方案
//{
//    if(n==1)
//    {
//        if(stepWalkAway%2 == 0)
//            return 0;   //只剩一步了，如果走过了偶数步，那就是右脚达到，不可能了，0
//        return 1;
//    }
//    else if(n==2)   //n = 2 时，不论什么情况，大家都只有1种可能，使得右脚到达
//    {
//        return 1;
//    }
//    else
//    {
//        return cal(n-1,stepWalkAway+1)+cal(n-2,stepWalkAway+1);   //递归调用函数
//    }
//}
//int main()
//{
//    unsigned long n, stepWalkAway = 0;
//    cout << "请输入你要走的台阶数 n :" ;
//    cin >> n;
//    cout << "左脚开走，右脚走到有 " << cal(n,stepWalkAway) << " 种方案。" << endl;
//    return 0;
//}
//-----------------------------------------------------------------------------------
unsigned long dynamicProgram(unsigned long N)
{
    unsigned long left[N+1], right[N+1];
    left [1] = 1; left [2] = 1; right [1] = 0; right [2] = 1;
    for(int i = 3; i <= N; ++i)
    {
        left[i] = right[i-1] + right[i-2];
        right[i] = left[i-1] + left[i-2];
    }
    return right[N];    //题目要求返回右脚到达方案
}
int main()
{
    unsigned long N;
    cout << "请输入你要走的台阶数 n :" ;
    cin >> N;
    cout << "左脚开走，右脚走到有 " << dynamicProgram(N) << " 种方案。" << endl;
    return 0;
}