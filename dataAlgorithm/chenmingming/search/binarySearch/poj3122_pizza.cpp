/**
 * @description: 有 n 块披萨（大小不一样）， f 个人分，包含主人自己 f+1 人；
 *                  每人吃的披萨必须是一块披萨上切下来的。求
 * @author: michael ming
 * @date: 2019/4/20 0:23
 * @modified by: 
 */
#include <iostream>
#include <iomanip>
#define PI 3.1415926535898
using namespace std;
const double error = 1e-7;
double find_max_R(size_t pizza_num, int *r_pizza, double r_low, double r_high, size_t people)
{
    double R_we_want = r_low+(r_high-r_low)/2.0;
    size_t people_get_pizza = 0;
    while(r_high - r_low > error)
    {
        people_get_pizza = 0;
        R_we_want = r_low+(r_high-r_low)/2.0;
        for(int i = 0; i < pizza_num; ++i)
            people_get_pizza += (int)(r_pizza[i]*r_pizza[i]/(R_we_want*R_we_want));
        if(people_get_pizza >= people)
            r_low = R_we_want;
        else
            r_high = R_we_want;
    }
    return R_we_want;
}
int main()
{
    size_t t, pizza_num, friend_num;
    double r_max_pizza = 0.0;
    cin >> t;
    while(t--)
    {
        cin >> pizza_num >> friend_num;
        int *r_pizza = new int [pizza_num];
        for(int i = 0; i < pizza_num; ++i)
        {
            cin >> r_pizza[i];
            r_max_pizza = r_pizza[i] > r_max_pizza ? r_pizza[i] : r_max_pizza;
        }
        r_max_pizza = find_max_R(pizza_num,r_pizza,0,r_max_pizza,friend_num+1);
        cout << setiosflags(ios::fixed) << setprecision(4) << PI*r_max_pizza*r_max_pizza << endl;
        delete[] r_pizza;
        r_pizza = NULL;
    }
    return 0;
}