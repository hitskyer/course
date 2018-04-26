#include <iostream>
using namespace std;

typedef struct Yanfu
{
	char name[20];
	char gender[4];
	int age;
	char education[20];
	int height;
	int weight;
	char character[50];
	char lover[20];
	
} afu;

int main()
{
	Yanfu afu;
	cout<<"请输入：姓名，性别，学历，品格，女朋友"<<endl;
        cin>>afu.name;
        cin>>afu.gender;
        afu.age=26;
        cin>>afu.education;
        afu.height=178;
        afu.weight=75;
        cin>>afu.character;
        cin>>afu.lover;
        cout<<afu.name<<" "<<afu.gender<<" "<<afu.age<<" "
			<<afu.education<<" ,身高："<<afu.height<<"cm,体重： "
			<<afu.weight<<endl;
	cout<<afu.character<<endl;
        cout<<"女朋友是："<<afu.lover<<endl; 
	return 0;
}
