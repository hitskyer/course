/*
* Copyright: (c) 2019
*
* 文件名称:  ACM1035.cpp	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/19  10:46
*/

#include <stdio.h>
#include <string.h>
char dict[10001][16];
char stemp[16];

/**
* @brief
*
* @method:    Del
* @access:    public 
* @param:     char * pstr
* @param:     char * dict
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/4/20  12:24 
*/
bool Del(char *pstr, char *dict)
{
	int dis = strlen(pstr) - strlen(dict);
	if(dis != 1)
		return false;
	else
	{
		int diff = 0;
		while(*pstr)
		{
			if(*pstr != *dict)
			{
				pstr++;
				diff++;
				if(diff > 1)
					return false;
			}
			else
			{
				pstr++;
				dict++;
			}			
		}
		return true;
	}
}


/**
* @brief
*
* @method:    Rep
* @access:    public 
* @param:     char * pstr
* @param:     char * dict
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/4/20  12:24 
*/
bool Rep(char *pstr, char *dict)
{
	int dis = strlen(pstr) - strlen(dict);
	if(dis != 0)
		return false;
	else
	{
		int diff = 0;
		while(*pstr)
		{
			if(*pstr != *dict)
			{
				pstr++;
				dict++;
				diff++;
				if(diff > 1)
					return false;
			}
			else
			{
				pstr++;
				dict++;
			}
		}
		return true;
	}
}


/**
* @brief
*
* @method:    Add
* @access:    public 
* @param:     char * pstr
* @param:     char * dict
* @Return:    bool
* @author:    RF_LYF
* @since:   2019/4/20  12:25 
*/
bool Add(char *pstr, char *dict)
{
	int dis = strlen(dict) - strlen(pstr);
	if(dis != 1)
		return false;
	else
	{
		int diff = 0;
		while(*pstr)
		{
			if(*pstr != *dict)
			{
				dict++;
				diff++;
				if(diff > 1)
					return false;
			}
			else
			{
				pstr++;
				dict++;
			}
		}
		return true;
	}
}

int main()
{
	int nDictLen = 0;
	while(scanf("%s", dict[nDictLen]) && strcmp(dict[nDictLen], "#"))
		nDictLen++;
	int nFlag ;
	bool brtn = false;
	char *word;
	while(scanf("%s", stemp) && strcmp(stemp, "#"))
	{
		nFlag = 0;
		word = stemp;
		for(int i = 0; i < nDictLen; ++i)
		{
			if(strcmp(word, dict[i]) == 0)
			{
				printf("%s is correct\n", word);
				nFlag = 1;
				break;
			}
		}
		if(!nFlag)
		{
			printf("%s:", word);
			for(int i =0; i < nDictLen; ++i)
			{
				if(Del(word, dict[i]))
					printf(" %s", dict[i]);
				if(Rep(word, dict[i]))
					printf(" %s", dict[i]);
				if(Add(word, dict[i]))
					printf(" %s", dict[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
