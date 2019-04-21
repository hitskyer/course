/**
 * @description: 有 n 块披萨（大小不一样）， f 个人分，包含主人自己 f+1 人；
 *                  每人吃的披萨必须是一块披萨上切下来的。求
 * @author: michael ming
 * @date: 2019/4/20 0:23
 * @modified by: 
 */
#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#define PI acos(-1.0)
using namespace std;
const double error = 1e-7;
double find_max_R(size_t pizza_num, double *s_pizza, double s_low, double s_high, size_t people)
{
    double S_we_want = s_low+(s_high-s_low)/2.0;
    size_t people_get_pizza = 0;
    while(s_high - s_low > error)
    {
        people_get_pizza = 0;
        S_we_want = s_low+(s_high-s_low)/2.0;
        for(int i = 0; i < pizza_num; ++i)
        {
            double temp = s_pizza[i];
            while(temp-S_we_want>=0)
            {
                temp -= S_we_want;
                people_get_pizza++;
            }
        }
        if(people_get_pizza >= people)
            s_low = S_we_want;
        else
            s_high = S_we_want;
    }
    return S_we_want;
}
int main()
{
    size_t t, pizza_num, friend_num;
    double s_max_pizza = 0.0;
    cin >> t;
    while(t--)
    {
        cin >> pizza_num >> friend_num;
        double *s_pizza = new double [pizza_num];
        for(int i = 0; i < pizza_num; ++i)
        {
            cin >> s_pizza[i];
            s_pizza[i] *= s_pizza[i];
        }
        sort(s_pizza, s_pizza+pizza_num);
        s_max_pizza = find_max_R(pizza_num,s_pizza,0,s_pizza[pizza_num-1],friend_num+1);
        cout << setiosflags(ios::fixed) << setprecision(4) << PI*s_max_pizza << endl;
        delete[] s_pizza;
        s_pizza = NULL;
    }
    return 0;
}