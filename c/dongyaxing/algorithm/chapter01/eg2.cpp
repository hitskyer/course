//(a) 百度文库、百度经验等等搜索引擎，需要算法，提高搜索速度
#include<iostream>
//#include<stdio>
//#include<stdin>

#include<math.h>
using namespace std;
int main()
{
	cout<<"判断何时8n^2 > 64nlgn"<<endl;
	int n=2;
	bool flag=true;
	while(flag)
	{
		if((64*n*log(2*n)-8*n*n)<0)
		{
			flag=false;
		}
		n++;
	}
	cout<<"当n= "<<n<<" 时，8n^2>64nlgn."<<endl;
	//float fl=0.00;
	//fl=log(10);
	//cout<<fl<<endl;
	return 0;
}

//log(2,10) or log(10) 均表示：以2为底10的对数。
//若在shell运行界面直接使用，则写为：
//  awk 'BEGIN{OFMT="%.3f";fl=log(10);print fl;}'
//
