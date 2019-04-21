/**
 * @description: 求根号n，递归法
 * @author: michael ming
 * @date: 2019/4/15 23:05
 * @modified by: 
 */
#include <iostream>
double rootbinarysearch_R(double num, double upper, double lower)
{
    if(num == 1)
        return 1;
    if(lower > upper)
        std::swap(lower,upper);
    double curValue = lower+(upper-lower)/2;
    if(upper-lower < 0.00000001)
        return curValue;
    if(curValue*curValue < num)
        return rootbinarysearch_R(num,curValue,upper);
    else
        return rootbinarysearch_R(num,lower,curValue);
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << x << "的平方根是 " << rootbinarysearch_R(x,x,1);
    return 0;
}
