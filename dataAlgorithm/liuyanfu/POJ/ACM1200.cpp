/*
* Copyright: (c) 2019
*
* 文件名称:  ACM1200.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/5/15  13:33
*/
#include <stdio.h>
#include <string.h>
const int max_num = 16000000;
char str[max_num];
int num[256];
bool h[max_num];

int main()
{
	int n ,nc;
	while(~scanf("%d%d%s", &n, &nc, str))
	{
		int nLen = strlen(str);
		int cnt = 1;
		for(int i = 0; cnt <= nc; ++i)
		{
			if(!num[str[i]])
				num[str[i]] = cnt++;
		}
		int sum = 0,pow=1;
		for(int i = 0; i < n; ++i)
		{
			if(i)
				pow *= nc;
			sum = sum * nc + num[str[i]];
		}
		int ans = 0;
		if(!h[sum])
		{
			h[sum] = true;
			ans++;
		}
		for(int i = n; i < nLen; ++i)
		{
			sum -= num[str[i - n]] * pow;
			sum = sum * nc + num[str[i]];
			if(!h[sum])
			{
				h[sum] = true;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}