#include <iostream>

using namespace std;

	void print(float f)
	{
		cout << f << endl;
	}
	float f;
	int main()
	{
		float ft;
		cout << "float类型的全局变量的默认值： ";
		print(f);
		cout << "float类型的局部变量的默认值： ";
		print(ft);
		cout << "float类型变量的存储长度： "<< sizeof(ft) << endl;
		return 0;
	
	}
