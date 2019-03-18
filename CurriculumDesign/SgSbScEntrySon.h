//版本号：v1.0      版权所有：1977177093@qq.com 
//说明：用于存放单科成绩录入的子函数

#ifndef _SGSBSCENTRYSON_H
#define _SGSBSCENTRYSON_H
 
#include "list.h"

/*
	功能：用于录入数学成绩 
*/
void MathEntry(List *plist);

/*
	功能：用于录入英语成绩 
*/
void EnglishEntry(List *plist);

/*
	功能：用于录入c语言成绩 
*/
void CLanguageEntry(List *plist);

/*
	功能：用于录入中文成绩 
*/
void ChineseEntry(List *plist);

#endif
