#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

const double PI = 3.14159265359;
int pieRi[10001];
double precision = 1e-6;

int main()
{
	int nCase = 0;
	cin >> nCase;
	int nPai = 0;
	int nF = 0;
	double maxEare = 0;
	while(nCase--)
	{
		cin >> nPai >> nF;
		for (int i = 0; i < nPai; ++i)
		{
			cin >> pieRi[i];
			pieRi[i] *= pieRi[i];
			maxEare = pieRi[i]> maxEare ? pieRi[i] : maxEare;
		}
		double low = 0;
		double high = maxEare;
		double mid = 0;
		int sumNum = 0;
		while(high - low > precision)
		{
			mid = low + (high - low) / 2;
			for (int i = 0; i < nPai; ++i)
			{
				if (pieRi[i] >= mid)
				{
					sumNum += (int)(pieRi[i]/mid);
				}
			}
			if (sumNum >= (nF + 1))
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
			sumNum = 0;
		}
		cout <<fixed << setprecision (4) << mid * PI << endl;
	}
	return 0;
}
