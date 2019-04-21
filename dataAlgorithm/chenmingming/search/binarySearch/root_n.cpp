#include<iostream>
double rootbinarysearch(double num)
{

	if(num == 1)
		return 1;
	double lower = 1, upper = num, curValue;
    if(lower > upper)
        std::swap(lower,upper);
	while(upper-lower > 0.00000001)
	{
		curValue = lower+(upper-lower)/2;
		if(curValue*curValue < num)
			lower = curValue;
		else
			upper = curValue;
	}
	return curValue;
}

int main()
{
	double x;
	std::cin >> x;
	std::cout << x << "的平方根是 " << rootbinarysearch(x);
	return 0;
}