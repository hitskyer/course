#include <iostream>
#include <iterator>
#include <map>
using namespace std;
unsigned long cal(unsigned long n, map<unsigned long, unsigned long>& n_fn_map)
{
    map<unsigned long,unsigned long>::iterator iter = n_fn_map.find(n);   //查找key n
    if(iter != n_fn_map.end())
    {
        return iter->second;    //如果找到了，就不必进行下面计算了，直接返回value
    }
	if(n==1)
    {
        n_fn_map.insert(pair<unsigned long, unsigned long>(1,1)); //把f(1)存入映射
	    return 1;
    }
	else if(n==2)
    {
        n_fn_map.insert(pair<unsigned long, unsigned long>(2,2)); //把f(2)存入映射
	    return 2;
    }
    else
    {
        unsigned long sum = cal(n-1,n_fn_map)+cal(n-2,n_fn_map);   //递归调用函数
        n_fn_map.insert(pair<unsigned long, unsigned long>(n,sum));       //求得的f(n)存入映射，供后面查询直接使用
        return sum;
    }
}
int main()  //递归(带避免重复计算fn的值功能)
{
    unsigned long n;
    cout << "请输入你要走的台阶数 n :" ;
    cin >> n;
    map<unsigned long, unsigned long> n_Fn;   //n，f(n)的 k，v 容器
	cout << "走台阶有 " << cal(n,n_Fn) << " 种方案。" << endl;
	return 0;
}

//int main()  //循环
//{
//    unsigned long n, step, nextStep = 2, nextnextStep = 1;
//    cout << "请输入你要走的台阶数 n :" ;
//    cin >> n;
//    if(n > 0)
//    {
//        if(n == 1)
//        {
//            step = 1;
//        } else if(n == 2)
//        {
//            step = 2;
//        }
//        else
//        {
//            for(int i = 2; i < n; ++i)
//            {
//                step = nextStep + nextnextStep;
//                nextnextStep = nextStep;
//                nextStep = step;
//            }
//        }
//	    cout << "走台阶有 " << step << " 种方案。" << endl;
//    }
//	return 0;
//}