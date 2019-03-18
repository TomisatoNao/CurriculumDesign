//版本号：v2.1   版权所有：1977177093@qq.com
//主要问题：大量相似，却访问不同的东西 ,重复代码问题 
//1.1说明：添加成绩排序后，姓名，学号，成绩输出  修改时间： 10:22 2019/3/13
//1.2说明：排序不正确，进行逻辑查找				修改时间: 10:59 2019/3/13
//2.1说明：添加文件操作，将排序后的结果输出到相关的文本文件中   修改时间：20:58 2019/3/15 
//重复代码问题未解决，是否需要重构  
 
#include "list.h"
#include <stdio.h>

void MathSort(List *plist) {
	struct Node *current;
	int n = 0;             //计数共有多少个节点，辅助冒泡排序，更改节点数据 
	int j;                //用于冒泡排序
	int i;                //用于冒泡排序 
	current = *plist;     //记录当前节点 
	struct Node *acurrent;   //记录下一个节点
	Item tempItem;
	
	FILE *mathsort;
	if((mathsort = fopen("mathsort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(mathsort, "%-15s%-15s%-15s\n", "姓名", "学号", "数学成绩");
	
	while(current != NULL) {
		current = current->next;
		n++;
	}
	
	for (i = 0; i < n; i++) {
		current = *plist;
		acurrent = current->next;
		for (j = 0; j < n - i - 1; j++) {
			if((current->item.m_nMath) > (acurrent->item.m_nMath)) {
				tempItem = current->item;
				current->item = acurrent->item;
				acurrent->item = tempItem;	
			}
			current = current->next;
			acurrent = acurrent->next;
		}
	}
	
	printf("\n数学排名如下:\n\n");
	printf("%-15s%-15s%-15s\n", "姓名", "学号", "数学成绩");
	
	current = *plist;
	while(current != NULL) {
		printf("%-15s%-15lld%-15d\n",
		current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nMath);
		fprintf(mathsort, "%-15s%-15lld%-15d\n", current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nMath);
		current = current->next;
	}
	
}

void EnglishSort(List *plist) {
	struct Node *current;
	int n = 0;             //计数共有多少个节点，辅助冒泡排序，更改节点数据 
	int j;                //用于冒泡排序
	int i;                //用于冒泡排序 
	current = *plist;     //记录当前节点 
	struct Node *acurrent;   //记录下一个节点
	Item tempItem; 
	
	FILE *englishsort;
	if((englishsort = fopen("englishsort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(englishsort, "%-15s%-15s%-15s\n", "姓名", "学号", "英语成绩");
	
	while(current != NULL) {
		current = current->next;
		n++;
	}
	for (i = 0; i < n; i++) {
		current = *plist;
		acurrent = current->next;
		for (j = 0; j < n - i - 1; j++) {
			if((current->item.m_nEnglish) > (acurrent->item.m_nEnglish)) {
				tempItem = current->item;
				current->item = acurrent->item;
				acurrent->item = tempItem;
			}
			current = current->next;
			acurrent = acurrent->next;
		}
	}
	
	printf("\n英语排名如下:\n\n");
	printf("%-15s%-15s%-15s\n", "姓名", "学号", "英语成绩");
	
	current = *plist;
	while(current != NULL) {
		printf("%-15s%-15lld%-15d\n",
		current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nEnglish);
		fprintf(englishsort, "%-15s%-15lld%-15d\n", current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nEnglish);
		current = current->next;
	}
}

void CLanguageSort(List *plist) {
	struct Node *current;
	int n = 0;             //计数共有多少个节点，辅助冒泡排序，更改节点数据 
	int j;                //用于冒泡排序
	int i;                //用于冒泡排序 
	current = *plist;     //记录当前节点 
	struct Node *acurrent;   //记录下一个节点
	Item tempItem;
	
	FILE *clanguagesort;
	if((clanguagesort = fopen("clanguagesort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(clanguagesort, "%-15s%-15s%-15s\n", "姓名", "学号", "C语言成绩");
	
	while(current != NULL) {
		current = current->next;
		n++;
	}
	
	for (i = 0; i < n; i++) {
		current = *plist;
		acurrent = current->next;
		for (j = 0; j < n - i - 1; j++) {
			if((current->item.m_nCLanguage) > (acurrent->item.m_nCLanguage)) {
				tempItem = current->item;
				current->item = acurrent->item;
				acurrent->item =tempItem;
				
			}
			current = current->next;
			acurrent = acurrent->next;
		}
	}
	
	printf("\nC语言排名如下:\n\n");
	printf("%-15s%-15s%-15s\n", "姓名", "学号", "C语言成绩");
	
	current = *plist;
	while(current != NULL) {
		printf("%-15s%-15lld%-15d\n",
		current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nCLanguage);
		fprintf(clanguagesort, "%-15s%-15lld%-15d\n", current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nCLanguage);
		current = current->next;
	}
}

void ChineseSort(List *plist) {
	struct Node *current;
	int n = 0;             //计数共有多少个节点，辅助冒泡排序，更改节点数据 
	int j;                //用于冒泡排序
	int i;                //用于冒泡排序 
	current = *plist;     //记录当前节点 
	struct Node *acurrent;   //记录下一个节点
	Item tempItem;
	
	FILE *chinesesort;
	if((chinesesort = fopen("chinesesort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(chinesesort, "%-15s%-15s%-15s\n", "姓名", "学号", "语文成绩");
	
	while(current != NULL) {
		current = current->next;
		n++;
	}
	
	for (i = 0; i < n; i++) {
		current = *plist;
		acurrent = current->next;
		for (j = 0; j < n - i - 1; j++) {
			if((current->item.m_nChinese) > (acurrent->item.m_nChinese)) {
				tempItem = current->item;
				current->item = acurrent->item;
				acurrent->item = tempItem;
			}
			current = current->next;
			acurrent = acurrent->next;
		}
	}
	
	printf("\n语文排名如下:\n\n");
	printf("%-15s%-15s%-15s\n", "姓名", "学号", "语文成绩");
	
	current = *plist;
	while(current != NULL) {
		printf("%20s%20lld%20d\n",
		current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nChinese);
		fprintf(chinesesort, "%-15s%-15lld%-15d\n", current->item.m_strName, 
		current->item.m_lnStudentID, current->item.m_nChinese);
		current = current->next;
	}
}
