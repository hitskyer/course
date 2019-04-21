/*
* Copyright: (c) 2019
*
* 文件名称:  singleton.h	
* 文件标识：
* 摘	要： 一个简易的单件类，需继承使用
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/4/15  16:15
*/

#ifndef _SINGLETON_H
#define _SINGLETON_H


template<typename T>
class singleton_basic
{
protected:
	singleton_basic(){}

	typedef singleton_basic<T> base_t;
public:
	static T& instance()
	{
		static T obj;

		return obj;
	}
};

#endif	//_SINGLETON_H