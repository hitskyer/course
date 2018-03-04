#include <iostream>
int main()
{
	std::cout << "enter two numbers:" << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;// read input
	//定义中间变量
	std::cout << "the large number is " ;
	if(v1 <= v2){
		std::cout << v2;
	}
	else{
		std::cout << v1;
	}
	return 0;
}
