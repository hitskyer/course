/**
 * @description: 求大于n的最小质数
 * @author: michael ming
 * @date: 2019/5/9 22:35
 * @modified by: 
 */
#include <stdio.h>
#include <math.h>
bool IsPrime(size_t n)
{
    size_t Sqt = ceil(sqrt(n));
    if(n == 1)
        return false;
    for(int i=2; i<=Sqt; ++i)
    {
        if(n%i == 0 && n != 2)
            return false;
    }
    return true;
}
int main()
{
    size_t i, j;
    printf("请输入一个数，程序求解大于其的最小质数：");
    scanf("%d", &i);
    j = i;
    while(1)
    {
        i++;
        if(IsPrime(i))
           break;
    }
    printf("大于%zu的最小质数是%zu",j,i);
    return 0;
}