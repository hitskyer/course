#include <iostream>
using namespace std;

int main() {
	enum open_modes {input, output, append};
	enum Forms {shape = 1, sphere, cylinder, polygon};
	enum Points {point2d = 2, point2w,
				 point3d = 3, point3w};
	//定义枚举变量
	Points pt = point2d;
	cout << "pt = " << pt << endl;
	pt = point2w;
	cout << "pt = " << pt << endl;
	pt = point3d;
	cout << "pt = " << pt << endl;
	pt = point3w;
	cout << "pt = " << pt << endl;
	
	return 0;
}
