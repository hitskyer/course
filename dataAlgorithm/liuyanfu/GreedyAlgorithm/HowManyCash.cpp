#include <iostream>
#include <vector>

using namespace std;


int HowManyCash(vector<int>& vRMB, int num, int waitToPay)
{
	int count = 0;
	for(int i = 0; i < num; ++i)
	{
		int use = waitToPay/vRMB[i];
		count += use;
		waitToPay = waitToPay - vRMB[i]*use;
		cout << "需要面额" << vRMB[i] << "的 " << use << " 张" << endl;
		cout << "剩下需要支付RMB " << waitToPay << endl;
	}
	cout << "总共需要 " << count << " 张RMB" << endl;
	return count;
}


int main()
{
	vector<int> vRMB;
	vRMB.push_back(100);
	vRMB.push_back(50);
	vRMB.push_back(20);
	vRMB.push_back(10);
	vRMB.push_back(5);
	vRMB.push_back(2);
	vRMB.push_back(1);
	
	int num = vRMB.size();
	int waitToPay = 611;
	HowManyCash(vRMB, num, waitToPay);
	return 0;
}