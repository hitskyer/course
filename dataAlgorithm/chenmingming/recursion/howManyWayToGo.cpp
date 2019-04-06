#include <iostream>
#include <iterator>
#include <map>
using namespace std;
size_t cal(size_t n, map<size_t, size_t>& n_fn_map)
{
    map<size_t,size_t>::iterator iter = n_fn_map.find(n);   //查找key n
    if(iter != n_fn_map.end())
    {
        return iter->second;    //如果找到了，就不必进行下面计算了，直接返回value
    }
	if(n==1)
    {
        n_fn_map.insert(pair<size_t, size_t>(1,1)); //把f(1)存入映射
	    return 1;
    }
	else if(n==2)
    {
        n_fn_map.insert(pair<size_t, size_t>(2,2)); //把f(2)存入映射
	    return 2;
    }
    else
    {
        size_t sum = cal(n-1,n_fn_map)+cal(n-2,n_fn_map);   //递归调用函数
        n_fn_map.insert(pair<size_t, size_t>(n,sum));       //求得的f(n)存入映射，供后面查询直接使用
        return sum;
    }
}
int main()  //递归(带避免重复计算fn的值功能)
{
    size_t n;
    cout << "请输入你要走的台阶数 n :" ;
    cin >> n;
    map<size_t, size_t> n_Fn;   //n，f(n)的 k，v 容器
	cout << "走台阶有 " << cal(n,n_Fn) << " 种方案。" << endl;
	return 0;
}

//int main()  //循环
//{
//    size_t n, step, nextStep = 2, nextnextStep = 1;
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