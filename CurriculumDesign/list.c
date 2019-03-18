// version:2.3(�����˽ڵ��ɾ������������˻�����Ϣ��ɾ������)  ��Ȩ���У�1977177093@qq.com       
//2.1˵��������������ͷָ��ָ������ 
//2.2˵�������ٲ���AddItem������ӽڵ㣬���ڹ���ʵ���н��нڵ�����        �޸�ʱ��:14:41 2019/3/11 
//2.3˵�����ҳ�plist��ʼ���������Ϊ1��Ϊʲô      �޸�ʱ�䣺20:43 2019/3/11
//2.3 �����������InitlizeList����ע�͵�����ȡֱ�ӳ�ʼ���÷���������ԭ��δ�ҳ������� 

#include <stdio.h>   //ΪNULL�ṩԭ�� 
#include "list.h"
#include <stdlib.h> 
#include <string.h>   //Ϊstrcmp�ṩ����ԭ�� 

/*
	�����ʼ��,ÿ�ν������ʱ,�����øú������ض��ļ������ж����Ĳ��� 
*/
void InitlizeList(List *plist) {
	FILE *stdif;
	struct Node *current;
	struct Node *prev;
	Item item;
	
	if ((stdif = fopen("stdif.txt", "r")) == NULL) {
		printf("���ļ�ʧ��\n"); 
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
	�Ƿ�Ϊ���������ڸ���һЩ���ò��� 
*/
bool ListIsEmpty(List *plist) {
	bool ret = true;
	
	if (*plist == NULL) {
		ret = false;	
	}
	
	return ret;
}

/*
	��ӽڵ㣬�����һ���ڵ�Ϊ�սڵ㣬�򽫸ýڵ����ӵ��˽ڵ�� 
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
	current = node;                     //��currentΪNULLʱֱ�Ӱѽڵ㸳ֵ��current�������ڵ�Ϳ���˳�����ӵ������� 
}
*/


/*
	�ͷ��ڴ�,������һ���ڵ㣬�ͷŵ�ǰ�ڵ���������ڴ漴�� 
*/
bool Release(List *plist) {
	struct Node *current;
	struct Node *prev;
	
	current = *plist;
	
	while (current != NULL) {
		prev = current->next;           //������һ�ڵ� 
		free(current);					//�ͷŵ�ǰ�ڵ�										
		current = prev;					//�����һ�ڵ� 
	}
}

/*
	ɾ�����裺���ҵ����������ļ��㣬��ס��һ���ڵ㣬���ҵõ���һ���ڵ㣬
	���ͷ�Ϊ�ýڵ���������ڴ棻 
	ʹ��һ���ڵ�����һ���ڵ������ӣ��Ӷ�ɾ���ýڵ� 
*/
void RemoveItem(char name[], List *plist) {
	struct Node *current;
	struct Node *bcurrent;
	struct Node *acurrent;
	 
	/* 
	 	�����ͷ�����ȱ���ס��һ���ڵ㣬�ͷ��ڴ棬�µ�ͷָ����һ���ڵ�
		 ������м䲿λ������һ���ڵ�ָ����һ���ڵ㼴��                        (��ס���ͷ��ڴ�) 
		 �����β��������ΪNULL���� 
	*/
	 

	 
	while (strcmp(name, current->item.m_strName) != 0 && current != NULL) {
	 	if(current->next == NULL) {
	 		printf("û���ҵ���Ҫɾ������Ϣ���ǳ���Ǹ\n"); 
		}
		bcurrent = current;
		current = current->next;
	}
	  
	/*
	 	�ж�current�ڵ�λ�ã�����ɾ���������͵Ľڵ� 
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
		printf("���ļ�ʧ��\n"); 
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
 
