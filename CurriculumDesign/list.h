// version:1.3    ��Ȩ���У�1977177093@qq.com 
#ifndef _LIST_H
#define _LIST_H
#define TSIZE 25
#include <stdio.h>
#include <stdbool.h>  //����bool����,ʹ�ú����������ɶ��Ը��� 

/*
	����ṹ�����洢����ѧ����Ϣ 
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
	����ڵ㣬��������������ɣ��Ա��ڴ������ݣ�
	�Լ����ݵ���ɾ�Ĳ� 
*/ 
struct Node {
	Item item;
	struct Node *next;
};

typedef struct Node * List;

/*
	���ܣ����ڳ�ʼ������
*/
void InitlizeList(List *plist);

/*
	���ܣ��ж������Ƿ�Ϊ������
	���ڸ����ڵ���л����Ĳ������	 
*/
bool ListIsEmpty(List *plist);

/*
	���ܣ�������ӽڵ� 
*/
void AddItem(Item item, List *plist);

/*
	���ܣ������ͷ�Ϊ����������������ڴ� 
*/
bool Release(List *plist);

/*
	���ܣ�����ɾ���ڵ� 
*/
void RemoveItem(char name[], List *plist);

/*
	���ܣ�����д������ 
*/
void ReadList(List *plist);

#endif
