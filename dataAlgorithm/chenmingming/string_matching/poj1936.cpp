/**
 * @description: poj1936水题
 * @author: michael ming
 * @date: 2019/6/25 18:19
 * @modified by: 
 */
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string a, b;
	size_t i, j;
	while(cin >> a >> b)
	{
		for(i = 0, j = 0; i < a.size() && j < b.size(); ++j)
		{
			if(a[i] == b[j])
				i++;
		}
		if(i == a.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}