#include<iostream>
using namespace std;
unsigned long func(size_t apple, size_t disc)
{
    if(apple == 1 || apple == 0)
        return 1;
    if(disc == 1)
        return 1;
    if(apple < disc)
        return func(apple, apple);
    else
        return func(apple, disc-1) + func(apple-disc, disc);
}
int main()
{
    size_t t, apple, disc;
    unsigned long sum = 0;
    cin >> t;
    while(t--)
    {
        cin >> apple >> disc;
        sum = func(apple, disc);
        cout << sum << endl;
    }
    return 0;
}