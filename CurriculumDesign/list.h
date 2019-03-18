// version:1.3    版权所有：1977177093@qq.com 
#ifndef _LIST_H
#define _LIST_H
#define TSIZE 25
#include <stdio.h>
#include <stdbool.h>  //增加bool类型,使得函数的声明可读性更高 

/*
	定义结构体来存储基本学生信息 
*/
struct Student{
	char m_strName[TSIZE];
	long long int m_lnStudentID;
	int m_nMath;
	int m_nEnglish;
	int m_nCLanguage;
	int m_nChinese;
};

typedef struct Student Item;

/*
	定义节点，来辅助链表的生成，以便于储存数据，
	以及数据的增删改查 
*/ 
struct Node {
	Item item;
	struct Node *next;
};

typedef struct Node * List;

/*
	功能：用于初始化链表
*/
void InitlizeList(List *plist);

/*
	功能：判断链表是否为空链表，
	用于辅助节点进行基本的插入操作	 
*/
bool ListIsEmpty(List *plist);

/*
	功能：用于添加节点 
*/
void AddItem(Item item, List *plist);

/*
	功能：用于释放为生成链表所分配的内存 
*/
bool Release(List *plist);

/*
	功能：用于删除节点 
*/
void RemoveItem(char name[], List *plist);

/*
	功能：用于写出链表 
*/
void ReadList(List *plist);

#endif
