//版本号：v1.5    版权所有：1977177093@qq.com
//1.1说明：晚上成绩录入模块操作逻辑      时间：14:11 2019/3/11
//1.2说明： 没进入一个模块进行清屏操作    时间：14:23 2019/3/11 
//1.3说明：发现语文成绩录入模块写错，进行修改      修改时间：9:42 2019/3/12 
//1.4说明：单科成绩录入修改后不再继续刷新，以直观观察成绩  修改时间： 10:21 2019/3/13
/*
	1.5说明：发现问题，在反复操作，信息录入，单科成绩录入的模块中，需要多次输入同一个人的成绩，这
	样的逻辑是不科学的         待修改              修改时间：10:27 2019/3/13 
*/


//说明：因为单科成绩分别录入导致录入规则相同，所以进行简单的抽调放入一个源文件中，方便后期的修改
//存在问题：大量相似，却访问不同的数据 

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void MathEntry(List *plist) {
	printf("\n您以成功进入数学成绩录入模块!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("姓名：%s 学号：%lld 的数学成绩为:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nMath == -1) {
			scanf("%d", &current->item.m_nMath);
		}
		else {
			printf("%d\n", current->item.m_nMath);
		}
		current = current->next;
	}
	
	printf("\n数学成绩录入完毕!\n"); 
}

void EnglishEntry(List *plist) {
	printf("\n您以成功进入英语成绩录入模块!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("姓名：%s 学号：%lld 的英语成绩为:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nEnglish == -1) {
			scanf("%d", &current->item.m_nEnglish);
		}
		else {
			printf("%d\n", current->item.m_nEnglish);
		}
		current = current->next;
	}
	
	printf("\n英语成绩录入完毕!\n"); 
}

void CLanguageEntry(List *plist) {
	printf("\n您以成功进入C语言成绩录入模块!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("姓名：%s 学号：%lld 的C语言成绩为:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nCLanguage == -1) {
			scanf("%d", &current->item.m_nCLanguage);
		}
		else {
			printf("%d\n", current->item.m_nCLanguage);
		}
		current = current->next;
	}
	
	printf("\nc语言成绩录入完毕!\n");
}

void ChineseEntry(List *plist) {
	printf("\n您以成功进入语文成绩录入模块!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("姓名：%s 学号：%lld 的语文成绩为:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nEnglish == -1) {
			scanf("%d", &current->item.m_nChinese);
		}
		else {
			printf("%d\n", current->item.m_nChinese);
		}
		current = current->next;
	}
	
	printf("\n语文成绩录入完毕!\n"); 
}
