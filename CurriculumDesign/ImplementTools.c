// version:3.2    版权所有：1977177093@qq.com   1.1对ScoreQery函数的逻辑进行了一定的修改    //1.3说明:修改了头指针指向问题 
//1.4说明：对学生信息录入模块进行修改，在简单的测试中，发现所输入的信息，并没有连接到链表上     修改时间：15:09 2019/3/11 
//1.5说明：对学生基本信息录入进行修改，确保传入指针所指向的位置，就是我们所开始的位置       修改时间： 9:07 2019/3/12
//1.6说明：查找数据没有链接到链表的原因	(应该是地址的问题，导致节点未连接到链表中)			修改时间：9:25 2019/3/12
//1.7说明：开始统计不及格科目超过两科的同学名单 
//1.8说明：修改成绩查找模块访问未知内存问题
//1.9说明： 添加单科成绩排序
//2.0说明：基本信息录入时，二次录入无法正确连接到链表末尾，对此情况进行改正         修改时间：10:13 2019/3/13
//3.0新需求：需求1.在添加信息时，对已输入信息进行显示   需求2.在添加成绩时，对已添加成绩进行显示
//3.1说明：挂科两科的无法进入         修改时间：11:03 2019/3/15
//3.2说明：对挂科两科的进行统计，并将名单输出到对应的文件中 
 

#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <string.h>
#include "SgSbScEntrySon.h"
#include "SgScSortSon.h"
#include "list.h"

/*
	待解决问题，如何返回主菜单的操作逻辑，  

*/ 
void ScoreQery(List *plist) {
	system("cls");       //进入模块执行清屏操作 
	printf("您已进入成绩查找模块\n");
	
	if(*plist == NULL) {
		return; 
	}
	
	int i = 1;     //定义用于用户选择，在未找到时，用户是否还想进行查找工作 
	char name[TSIZE];
	struct Node *current;
	
	
	while(i) {
		int flag = 0;  //定义标记如果找到了。默认为找到了，没找到就设置为1
		
		current = *plist;         //每次进入循环，都初始化当前节点
		
		printf("请输入您要进行查找的人员信息的名字:\n");
		scanf("%s",name);
		
		while(strcmp(current->item.m_strName, name) != 0) {
			
			if((current = current->next) == NULL) {
				flag = 1;
				break;                     //使用break，不然while中的语句会访问未知内存，导致出错 
			}
			
		}
		
		if (flag == 0) {
			printf("您要查找的信息如下：\n" 
				   "姓名:%s 学号:%lld 数学:%d " 
				   "英语:%d C语言:%d 语文:%d\n",
			current->item.m_strName, current->item.m_lnStudentID,
			current->item.m_nMath, current->item.m_nEnglish,
			current->item.m_nCLanguage, current->item.m_nChinese);
			i = 0;
		}
		else {
			printf("对不起，没有找到您所要查找的人员信息\n");
			printf("1.继续操作       0.返回主菜单\n");
			scanf("%d", &i);  
		}
	}
}

void SgSbScEntry(List *plist) {
	system("cls");
	printf("您以进入单科成绩录入模块\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	int i;     					//用于选择所录入科目
	int j = 1;                      //用于循环辅助进行反复录入 
	struct Node *current;
	
	current = *plist;
	
	while (j) {
		printf("\n1.数学\t2.英语\t3.c语言\t4.语文\n");
		printf("请输入:\n"); 
		scanf("%d", &i);
		
		switch (i) {
			case 1:
				MathEntry(plist);
				break;
			case 2:
				EnglishEntry(plist);
				break;
			case 3:
				CLanguageEntry(plist);
				break;
			case 4:
				ChineseEntry(plist);
				break;
		}
		
		printf("0.不在录入其他科目 1.继续录入其他科目\n");
		printf("请输入:\n");
		scanf("%d", &j);
	}
	
}

/*
	先找到链表末尾，再讲新节点添加到新申请的内存上去 
*/ 
void IfmtEntry(List *plist) {
	system("cls");
	printf("您已进入基本信息录入模块\n");

	char name[TSIZE];
	int j = 1;                       //用于辅助用户是否继续添加节点 
	struct Node *current = *plist;    //用于辅助输入
	struct Node *prev;
	Item item;
	item.m_nChinese = -1;
	item.m_nCLanguage = -1;
	item.m_nMath = -1;
	item.m_nEnglish = -1;

	if(*plist != NULL) {
		printf("已添加学生信息如下:\n\n");
		printf("%-15s%-15s\n", "姓名","学号"); 
	}
	
	while(current != NULL) {
		prev = current;               //修正二次进入不能正确连接到链表的问题 
		
		printf("%-15s%-15lld\n", current->item.m_strName, current->item.m_lnStudentID);
		
		current = current->next;
	}
	
//	prev = current;               //修正二次进入不能正确连接到链表的问题,出现内存读写错误（时间：10:18 2019/3/13）

	printf("\n添加学生信息:\n"); 
	
	while(j) {
		current = (struct Node *)malloc(sizeof(struct Node));    //此处将修改current 所指向的地址，修改过后，再连接
		 
		
		if(*plist == NULL) {
			*plist = current;           //此处修改的是传入指针生成副本的值，却没有修改指正本身的值，以更正 
		}
		else {
			prev->next = current;	
		}
		
		current->next = NULL;
		printf("\n姓名 : ");
		scanf("%s", name);
		strcpy(item.m_strName, name);
		printf("学号 : ");
		scanf("%lld", &item.m_lnStudentID);
		current->item = item;
		
		printf("\n0.不再录入\t1.继续录入\n");
		scanf("%d", &j);
		prev = current;
	}
	
}

void TwoFail(List *plist) {
	system("cls");
	printf("您已经进入挂科超过两科人员名单统计模块\n\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	FILE *twofail;
	if((twofail = fopen("twofail.txt", "w")) == NULL) {
		printf("file can not open\n");
		exit(1);
	}
	
	fprintf(twofail, "%-15s%-15s\n", "姓名", "学号");
	
	struct Node *current;
	
	printf("具体人员如下:\n"); 
	current = *plist;
	
	while(current != NULL) {
		Item item;
		item = current->item;
		if ((item.m_nChinese<60 && item.m_nCLanguage<60) ||
		(item.m_nChinese<60 && item.m_nEnglish<60) ||
		(item.m_nChinese<60 && item.m_nMath<60) ||
		(item.m_nEnglish<60 &&item.m_nCLanguage<60) ||
		(item.m_nCLanguage<60 && item.m_nMath<60) ||
		(item.m_nEnglish<60 && item.m_nMath<60)) {
			printf("姓名: %s 学号: %lld\n\n", item.m_strName, item.m_lnStudentID);
			fprintf(twofail, "%-15s%-15lld\n", item.m_strName, item.m_lnStudentID);
			
		}
		current = current->next;	
	}
	printf("以上为挂科两科的学生名单(10s后会自动返回主菜单)\n");
	printf("ps:名单已经输出到对应文件中(twofail.txt)\n");
	Sleep(10000);
}

void SgScSort(List *plist) {
	system("cls");
	printf("您已进入单科成绩排序模块\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	int i;     					//用于选择所录入科目
	int j = 1;                      //用于循环辅助进行反复录入 
	struct Node *current;
	
	current = *plist;
	
	while (j) {
		printf("\n1.数学\t2.英语\t3.c语言\t4.语文\n");
		printf("请输入:\n"); 
		scanf("%d", &i);
		
		switch (i) {
			case 1:
				MathSort(plist);
				break;
			case 2:
				EnglishSort(plist);
				break;
			case 3:
				CLanguageSort(plist);
				break;
			case 4:
				ChineseSort(plist);
				break;
		}
		
		printf("\n0.不再查看其它科目排名 1.继续查看其它科目排名\n");
		printf("请输入:\n");
		scanf("%d", &j);
	}
	
}
