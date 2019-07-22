/*
* Copyright: (c) 2019
*
* 文件名称:  ACM2255.cpp	
* 文件标识：
* 摘	要： 已知前序遍历和中序遍历的顺序，重构二叉树并打印后序遍历结果
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/6/3  10:47
*/

#include <stdio.h>
#include <string.h>

char pre[100];
char mid[100];

void postorder(int s1, int s2, int n)
{
	int pos = s2;
	if(n <= 0)
		return;
	while(mid[pos] != pre[s1])
		pos++;
	postorder(s1+1, s2, pos-s2);
	postorder(s1+pos-s2+1, pos+1, n-pos-1+s2);
	printf("%c", pre[s1]);
}


int main()
{
	while(~scanf("%s%s",pre, mid))
	{
		int len = strlen(pre);
		postorder(0,0,len);
		printf("\n");
	}
	return 0;
}