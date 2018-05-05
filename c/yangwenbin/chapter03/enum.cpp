#include <iostream>
using namespace std;


//理解: 枚举可以用来保存一组属性的值.比如当官中有军 师 旅 团 营 连 排 班 等几个等级，这样一组属性就可以用枚举表示
int main() {
	enum open_modes {input, output, append};
	enum Forms {shape = 1, sphere, cylinder, polygon};
	enum Points {point2d = 2, point2w,
				 point3d = 3, point3w};
	//定义枚举变量  默认是递增的
	Points pt = point2d;
	cout << "pt = " << pt << endl;
	pt = point2w;
	cout << "pt = " << pt << endl;
	pt = point3d;
	cout << "pt = " << pt << endl;
	pt = point3w;
	cout << "pt = " << pt << endl;

	cout << "--------------------------------------------------------------" << endl;
	Forms f =shape;
	cout << "f = " << f << endl;
	f= sphere;
	cout << "f = " << f << endl;
	f= cylinder;
        cout << "f = " << f << endl;
	f=polygon;
        cout << "f = " << f << endl;

	
	return 0;
}
