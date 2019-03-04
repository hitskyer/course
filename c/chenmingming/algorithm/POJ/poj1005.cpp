#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.141592653
int main()
{
    float x,y;
    double area,distance,dangerdistance=0;
    int year;
    size_t N;
    cin >> N;
    for(int i = 0; i != N; ++i)
    {
        cin >> x >> y;
        distance = sqrt(x*x+y*y);
        for(area = 0,year =0; dangerdistance < distance; ++year)
        {
            area += 50;
            dangerdistance = sqrt(2*area/PI);
        }
        cout << "Property " << i+1 << ": This property will begin eroding in year " << year << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}