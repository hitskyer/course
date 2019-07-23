/*
* Copyright: (c) 2019
*
* 文件名称:  Huffman.h	
* 文件标识：
* 摘	要：
*
* 版	本： 1.0
* 作	者： RF_LYF
* 创建日期:	 2019/7/9  8:36
*/
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#define MAXINT 32767

typedef char BYTE;
typedef unsigned int UINT;


typedef struct  
{
	BYTE character;
	UINT weight;
	UINT Parent, lChild, rChild;
}HTNode;

#endif // _HUFFMAN_H