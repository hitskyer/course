#include <iostream>
int main()
{
	std::cout << "enter two numbers:" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;// read input
	//定义中间变量，转换上下限
	int low, up;
	if(v1 <= v2){
		low = v1;
		up = v2;
	}
	else{
	low = v2;
	up = v1;
	}
	int sum = 0;
	for(int i = low; i <= up; ++i)
	sum += i;
	std::cout << "sum of " << low
		<< " to " << up
		<< " is " << sum
		<< std::endl;
	return 0;
}
