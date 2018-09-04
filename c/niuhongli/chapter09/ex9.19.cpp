#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> iv;
	vector<int>::iterator iv.begin();
	vector<int>::iterator mid=iv.begin()+iv.size()/2;
	while(vector<int>::iterator iter!=mid)
	{
		if(*iter==someval)
		{
			iter=iv.insert(iter,2*someval);
			iter+=iter;
		}
		else
			++iter;
	}
	return 0;
}
