// version:1.1    版权所有：1977177093@qq.com
//添加了单科成绩排名的功能函数       修改时间：11:15 2019/3/12

#ifndef _IMPLEMENTTOOLS_H
#define _IMPLEMENTTOOLS_H

#include "list.h"

/*
	功能：用于成绩查询
	 	提供两种成绩查询方式，一种为用名字进行查询，一种为用学号进行查询 
*/
void ScoreQery(List *plist);

/*
	功能：用于单科成绩录入
		提供科目选择，选择科目后，从链表中读出名字信息，依次输出，并输入相关科目成绩，写入链表中 
*/
void SgSbScEntry(List *plist);

/* 
	功能：用于学生信息录入 
*/ 
void IfmtEntry(List *plist);

/*
	功能：用于统计挂科超过两科的学生 
*/
void TwoFail(List *plist);

/*
	功能：用于单科成绩的排名 
*/
void SgScSort(List *plist);
#endif
