// version:2.3(更新了节点的删除，算是完成了基本信息的删除部分)  版权所有：1977177093@qq.com       
//2.1说明：更新了链表头指针指向问题 
//2.2说明：不再采用AddItem进行添加节点，而在工具实现中进行节点的添加        修改时间:14:41 2019/3/11 
//2.3说明：找出plist初始化出来后变为1是为什么      修改时间：20:43 2019/3/11
//2.3 解决方法，将InitlizeList函数注释掉，采取直接初始化得方法，真正原因未找出，待查 

#include <stdio.h>   //为NULL提供原型 
#include "list.h"
#include <stdlib.h> 
#include <string.h>   //为strcmp提供函数原型 

/*
	链表初始化,每次进入程序时,都调用该函数打开特定文件，进行读出的操作 
*/
void InitlizeList(List *plist) {
	FILE *stdif;
	struct Node *current;
	struct Node *prev;
	Item item;
	
	if ((stdif = fopen("stdif.txt", "r")) == NULL) {
		printf("打开文件失败\n"); 
	}
	
	
	while ((fscanf(stdif,"%s %lld %d %d %d %d", item.m_strName, 
	&item.m_lnStudentID, &item.m_nMath, &item.m_nEnglish, &item.m_nCLanguage,
	&item.m_nChinese)) != EOF) {
		current = (struct Node*)malloc(sizeof(struct Node));
		current->next = NULL;
		current->item = item;
		
		if (*plist == NULL) {
			*plist = current;
		}
		else {
			prev->next = current;
		}
		
		prev = current;
	}
	
	fclose(stdif);	
}

/*
	是否为空链表，用于辅助一些常用操作 
*/
bool ListIsEmpty(List *plist) {
	bool ret = true;
	
	if (*plist == NULL) {
		ret = false;	
	}
	
	return ret;
}

/*
	添加节点，如果下一个节点为空节点，则将该节点连接到此节点后 
*/
/*
void AddItem(Item item, List *plist) {
	struct Node *node;       
	struct Node *current;
	
	current = *plist;
	
	node = (struct Node *) malloc (sizeof(struct Node));
	node->item = item;
	node->next = NULL;
	

	while(current != NULL) {
		current = current->next;
	}
	current = node;                     //当current为NULL时直接把节点赋值给current，这样节点就可以顺利连接到链表上 
}
*/


/*
	释放内存,保存下一个节点，释放当前节点所分配的内存即可 
*/
bool Release(List *plist) {
	struct Node *current;
	struct Node *prev;
	
	current = *plist;
	
	while (current != NULL) {
		prev = current->next;           //保存下一节点 
		free(current);					//释放当前节点										
		current = prev;					//获得下一节点 
	}
}

/*
	删除所需：先找到符合条件的几点，记住上一个节点，并且得到下一个节点，
	先释放为该节点所分配的内存； 
	使上一个节点与下一个节点相连接，从而删除该节点 
*/
void RemoveItem(char name[], List *plist) {
	struct Node *current;
	struct Node *bcurrent;
	struct Node *acurrent;
	 
	/* 
	 	如果是头，则先保存住下一个节点，释放内存，新的头指向下一个节点
		 如果是中间部位，则将上一个节点指向下一个节点即可                        (记住需释放内存) 
		 如果是尾则将它设置为NULL即可 
	*/
	 

	 
	while (strcmp(name, current->item.m_strName) != 0 && current != NULL) {
	 	if(current->next == NULL) {
	 		printf("没有找到您要删除的信息，非常抱歉\n"); 
		}
		bcurrent = current;
		current = current->next;
	}
	  
	/*
	 	判断current节点位置，用于删除各种类型的节点 
	*/
	
	if(current == *plist) {
		acurrent = current->next;
		free(current);
		*plist = acurrent;
	}
	else if(current == NULL) {
		free(current);
		bcurrent->next = NULL;
	}
	else {
		acurrent = current->next;
		bcurrent->next = acurrent;
		free(current);
	}
}

void ReadList(List *plist) {
	FILE *stdif;
	struct Node *current;
	
	if ((stdif = fopen("stdif.txt", "w")) == NULL) {
		printf("打开文件失败\n"); 
	}
	
	current = *plist;
	while(current != NULL) {
		Item item;
		item = current->item;
		fprintf(stdif, "\n%-15s%-15lld%-15d%-15d%-15d%-15d\n", item.m_strName, 
		item.m_lnStudentID, item.m_nMath, item.m_nEnglish, item.m_nCLanguage,
		item.m_nChinese);
		current = current->next;
	}

	fclose(stdif);
} 
 
