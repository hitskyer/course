/**
 * @description: 已知路上各加油站的距离，求最少加油次数（贪心）
 * @author: michael ming
 * @date: 2019/7/3 18:07
 * @modified by: 
 */
#include <iostream>
#define N 9     //加油站个数
#define oil_volume 20    //油箱额定可跑里程
using namespace std;
class Car
{
public:
    int s;//行驶里程
    int carmileage;//油箱可跑里程
    Car():s(0),carmileage(oil_volume){}
    void fillgas()
    {
        carmileage = oil_volume;//加油，油箱加满
    }
};
int main()
{
    Car tesla;
    int gasStation[N] = {10,20,35,40,50,65,75,85,100};//加油站距离起点距离
    int dist, i = 0;
    bool fill = true;//加油了吗，默认加满了油出发
    cout << "请输入目的地的距离:";
    cin >> dist;
    if(tesla.carmileage >= dist)
        cout << "无需加油，" << "剩余的汽油可跑"
            << tesla.carmileage-dist << "km。" << endl;
    else
    {
        for(i = 0; i < N; ++i)
        {
            if(tesla.s + tesla.carmileage >= gasStation[i])//车子可开到i加油站
            {
                tesla.carmileage -= gasStation[i]-tesla.s;//油箱变少
                tesla.s = gasStation[i];//里程更新
                fill = false;//没有加油
                if(tesla.s >= dist)
                {
                    cout << "到达终点,剩余的汽油可跑"
                            << tesla.carmileage+tesla.s-dist << "km。" << endl;
                    break;
                }
            }
            else if(tesla.s + tesla.carmileage < gasStation[i] && !fill)
            {//车子没有加油，到不了i号加油站，需要在i-1站加油
                i--;//i-1站
                tesla.fillgas();//加油
                fill = true;//标记加过油
                cout << "在" << gasStation[i] << "km处加油！" << endl;
            }
            else//车子前一站加过油，还到不了i号加油站，不能到达目的地
            {
                cout << "不能到达目的地，距离目的地" << dist-(tesla.s+tesla.carmileage)
                    << "km,距离下一个加油站" << gasStation[i]-(tesla.s+tesla.carmileage)
                    << "km,请呼叫救援！"<< endl;
                break;
            }
        }
        if(tesla.s < dist && i >= N)//开过了所有的加油站 还没到
            cout << "不能到达目的地，后面没有加油站，距离目的地"
                << dist-(tesla.s+tesla.carmileage) << "km,请呼叫救援！"<< endl;
    }
    return 0;
}