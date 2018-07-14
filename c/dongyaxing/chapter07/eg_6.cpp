#include<iostream>

using namespace std;

int swap_1(int i, int j)
{
	int temp1;
	temp1=i;
	i=j;
	j=temp1;
}

int swap_2(int *i, int *j)
{
	int temp2;
	temp2= *i;
	*i= *j;
	*j=temp2;
}

int main()
{
	int a,b;
	cout<<"exchange a and b"<<endl;
	cout<<"input two numbers: "<<endl;
	cin>>a>>b;
	swap_1(a,b);
	cout<<a<<" "<<b<<endl;
	swap_2(&a,&b);
	cout<<a<<" "<<b<<endl;
	return 0;

}
