#include "WebBrowse.h"


WebBrowse::WebBrowse(void)
{
}


WebBrowse::~WebBrowse(void)
{
}



/****************************************!
*@brief  浏览器的前进功能
*@author liuyanfu
*@date   2019年3月28日	22:50
*@param[out] 
*@return     void  
****************************************/
void WebBrowse::forward()
{
	if(!bstk.Empty())
	{
		fstk.Push((bstk.GetTop())->data);
		bstk.Pop();
		displayCurWeb((fstk.GetTop())->data);
	}
	displayCurWeb(NULL);
}


/****************************************!
*@brief  浏览器的后退功能
*@author liuyanfu
*@date   2019年3月28日	22:51
*@param[out] 
*@return     void  
****************************************/
void WebBrowse::back()
{
	if(!fstk.Empty())
	{
		bstk.Push((fstk.GetTop())->data);
		fstk.Pop();
		displayCurWeb((fstk.GetTop())->data);
	}
	displayCurWeb(NULL);
}


/****************************************!
*@brief  根据输入的网址浏览该网页的内容
*@author liuyanfu
*@date   2019年3月28日	23:27
*@param[out] 
*@param[in]  char * addr  
*@return     void  
****************************************/
void WebBrowse::browseWeb(char *addr)
{
	if(!bstk.Empty())
		bstk.Clear();
	fstk.Push(addr);
	displayCurWeb((fstk.GetTop())->data);
}


/****************************************!
*@brief  显示当前浏览器的内容
*@author liuyanfu
*@date   2019年3月28日	23:27
*@param[out] 
*@param[in]  char * addr  
*@return     void  
****************************************/
void WebBrowse::displayCurWeb(char *addr)
{
	if(addr)
		std::cout << "Current web is : " << addr << std::endl;
	else
		std::cout << "Web error is 404" << std::endl;
}