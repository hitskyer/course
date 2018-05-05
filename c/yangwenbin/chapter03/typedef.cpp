#include <iostream>
using namespace std;
//typedef 他并不创建新的类型 为现有的类型添加一个同义字 现在一个类型是float类型，比如写成 float cs =0.0; 但是大家不太容易理解cs到底是什么，给这个类型使用typedef取了一个别名
//这样的话，我们一看cs的类型是ChineseScore 这个只是一个类型的别名，真正我们再看他的实际类型是float类型
typedef float ChineseScore;
typedef int EnglishScore;
typedef int MathScore;
int main() {
	ChineseScore cs = 99.88;
	MathScore    ms = 98;
	EnglishScore es = 97;

	cout << "my Ehinese score is " << cs << endl;
	cout << "my math score is    " << ms << endl;
	cout << "my English score is " << es << endl;
	
	return 0;
}
