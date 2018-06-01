#include <iostream>
using namespace std;

int main()
{
// 记录金融、工商、工管三个专业的项目、论文以及获奖数量；
typedef int project;
typedef int paper;
typedef int honor;

project pro_Fi=10;
project pro_Ba=13;
project pro_Em=15;

paper pa_Fi=47;
paper pa_Ba=60;
paper pa_Em=40;

honor hor_Fi=5;
honor hor_Ba=19;
honor hor_Em=18;
cout << "Projects: " << endl;
cout << "pro_Fi= " << pro_Fi << "\n" << "pro_Ba= " << pro_Ba << "\n" << "pro_Em=" << pro_Em<< endl;
cout << "Papers: " << endl;
cout << "pa__Fi= " << pa_Fi << "\n" << "pa_Ba= " << pa_Ba << "\n" << "pa_Em=" << pa_Em<< endl;
cout << "Honors: " << endl;
cout << "hor__Fi= " << hor_Fi << "\n" << "hor_Ba= " << hor_Ba << "\n" << "hor_Em=" << hor_Em<< endl;


}
