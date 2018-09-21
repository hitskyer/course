#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a[]={1,2,3,4,5,6,7};
	int b[]={15,16,17,8,9,10,11};
	vector<int> vec_a(a,a+7);
	vector<int> vec_b(b,b+7);
	bool re = true;
	for(size_t i = 0; i< vec_a.size(); ++i)
	{
		for(size_t j = 0; j<vec_b.size(); ++j)
		{
			if(vec_a[i] == vec_b[j])
			{
				re = false;
				break;
			}
		}
	}
	cout<<re<<endl;
	return 0;
}
