// version:3.2    ��Ȩ���У�1977177093@qq.com   1.1��ScoreQery�������߼�������һ�����޸�    //1.3˵��:�޸���ͷָ��ָ������ 
//1.4˵������ѧ����Ϣ¼��ģ������޸ģ��ڼ򵥵Ĳ����У��������������Ϣ����û�����ӵ�������     �޸�ʱ�䣺15:09 2019/3/11 
//1.5˵������ѧ��������Ϣ¼������޸ģ�ȷ������ָ����ָ���λ�ã�������������ʼ��λ��       �޸�ʱ�䣺 9:07 2019/3/12
//1.6˵������������û�����ӵ������ԭ��	(Ӧ���ǵ�ַ�����⣬���½ڵ�δ���ӵ�������)			�޸�ʱ�䣺9:25 2019/3/12
//1.7˵������ʼͳ�Ʋ������Ŀ�������Ƶ�ͬѧ���� 
//1.8˵�����޸ĳɼ�����ģ�����δ֪�ڴ�����
//1.9˵���� ��ӵ��Ƴɼ�����
//2.0˵����������Ϣ¼��ʱ������¼���޷���ȷ���ӵ�����ĩβ���Դ�������и���         �޸�ʱ�䣺10:13 2019/3/13
//3.0����������1.�������Ϣʱ������������Ϣ������ʾ   ����2.����ӳɼ�ʱ��������ӳɼ�������ʾ
//3.1˵�����ҿ����Ƶ��޷�����         �޸�ʱ�䣺11:03 2019/3/15
//3.2˵�����Թҿ����ƵĽ���ͳ�ƣ����������������Ӧ���ļ��� 
 

#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>
#include <string.h>
#include "SgSbScEntrySon.h"
#include "SgScSortSon.h"
#include "list.h"

/*
	��������⣬��η������˵��Ĳ����߼���  

*/ 
void ScoreQery(List *plist) {
	system("cls");       //����ģ��ִ���������� 
	printf("���ѽ���ɼ�����ģ��\n");
	
	if(*plist == NULL) {
		return; 
	}
	
	int i = 1;     //���������û�ѡ����δ�ҵ�ʱ���û��Ƿ�����в��ҹ��� 
	char name[TSIZE];
	struct Node *current;
	
	
	while(i) {
		int flag = 0;  //����������ҵ��ˡ�Ĭ��Ϊ�ҵ��ˣ�û�ҵ�������Ϊ1
		
		current = *plist;         //ÿ�ν���ѭ��������ʼ����ǰ�ڵ�
		
		printf("��������Ҫ���в��ҵ���Ա��Ϣ������:\n");
		scanf("%s",name);
		
		while(strcmp(current->item.m_strName, name) != 0) {
			
			if((current = current->next) == NULL) {
				flag = 1;
				break;                     //ʹ��break����Ȼwhile�е��������δ֪�ڴ棬���³��� 
			}
			
		}
		
		if (flag == 0) {
			printf("��Ҫ���ҵ���Ϣ���£�\n" 
				   "����:%s ѧ��:%lld ��ѧ:%d " 
				   "Ӣ��:%d C����:%d ����:%d\n",
			current->item.m_strName, current->item.m_lnStudentID,
			current->item.m_nMath, current->item.m_nEnglish,
			current->item.m_nCLanguage, current->item.m_nChinese);
			i = 0;
		}
		else {
			printf("�Բ���û���ҵ�����Ҫ���ҵ���Ա��Ϣ\n");
			printf("1.��������       0.�������˵�\n");
			scanf("%d", &i);  
		}
	}
}

void SgSbScEntry(List *plist) {
	system("cls");
	printf("���Խ��뵥�Ƴɼ�¼��ģ��\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	int i;     					//����ѡ����¼���Ŀ
	int j = 1;                      //����ѭ���������з���¼�� 
	struct Node *current;
	
	current = *plist;
	
	while (j) {
		printf("\n1.��ѧ\t2.Ӣ��\t3.c����\t4.����\n");
		printf("������:\n"); 
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
		
		printf("0.����¼��������Ŀ 1.����¼��������Ŀ\n");
		printf("������:\n");
		scanf("%d", &j);
	}
	
}

/*
	���ҵ�����ĩβ���ٽ��½ڵ���ӵ���������ڴ���ȥ 
*/ 
void IfmtEntry(List *plist) {
	system("cls");
	printf("���ѽ��������Ϣ¼��ģ��\n");

	char name[TSIZE];
	int j = 1;                       //���ڸ����û��Ƿ������ӽڵ� 
	struct Node *current = *plist;    //���ڸ�������
	struct Node *prev;
	Item item;
	item.m_nChinese = -1;
	item.m_nCLanguage = -1;
	item.m_nMath = -1;
	item.m_nEnglish = -1;

	if(*plist != NULL) {
		printf("�����ѧ����Ϣ����:\n\n");
		printf("%-15s%-15s\n", "����","ѧ��"); 
	}
	
	while(current != NULL) {
		prev = current;               //�������ν��벻����ȷ���ӵ���������� 
		
		printf("%-15s%-15lld\n", current->item.m_strName, current->item.m_lnStudentID);
		
		current = current->next;
	}
	
//	prev = current;               //�������ν��벻����ȷ���ӵ����������,�����ڴ��д����ʱ�䣺10:18 2019/3/13��

	printf("\n���ѧ����Ϣ:\n"); 
	
	while(j) {
		current = (struct Node *)malloc(sizeof(struct Node));    //�˴����޸�current ��ָ��ĵ�ַ���޸Ĺ���������
		 
		
		if(*plist == NULL) {
			*plist = current;           //�˴��޸ĵ��Ǵ���ָ�����ɸ�����ֵ��ȴû���޸�ָ�������ֵ���Ը��� 
		}
		else {
			prev->next = current;	
		}
		
		current->next = NULL;
		printf("\n���� : ");
		scanf("%s", name);
		strcpy(item.m_strName, name);
		printf("ѧ�� : ");
		scanf("%lld", &item.m_lnStudentID);
		current->item = item;
		
		printf("\n0.����¼��\t1.����¼��\n");
		scanf("%d", &j);
		prev = current;
	}
	
}

void TwoFail(List *plist) {
	system("cls");
	printf("���Ѿ�����ҿƳ���������Ա����ͳ��ģ��\n\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	FILE *twofail;
	if((twofail = fopen("twofail.txt", "w")) == NULL) {
		printf("file can not open\n");
		exit(1);
	}
	
	fprintf(twofail, "%-15s%-15s\n", "����", "ѧ��");
	
	struct Node *current;
	
	printf("������Ա����:\n"); 
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
			printf("����: %s ѧ��: %lld\n\n", item.m_strName, item.m_lnStudentID);
			fprintf(twofail, "%-15s%-15lld\n", item.m_strName, item.m_lnStudentID);
			
		}
		current = current->next;	
	}
	printf("����Ϊ�ҿ����Ƶ�ѧ������(10s����Զ��������˵�)\n");
	printf("ps:�����Ѿ��������Ӧ�ļ���(twofail.txt)\n");
	Sleep(10000);
}

void SgScSort(List *plist) {
	system("cls");
	printf("���ѽ��뵥�Ƴɼ�����ģ��\n");
	
	if(*plist == NULL) {			
		return;
	}
	
	int i;     					//����ѡ����¼���Ŀ
	int j = 1;                      //����ѭ���������з���¼�� 
	struct Node *current;
	
	current = *plist;
	
	while (j) {
		printf("\n1.��ѧ\t2.Ӣ��\t3.c����\t4.����\n");
		printf("������:\n"); 
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
		
		printf("\n0.���ٲ鿴������Ŀ���� 1.�����鿴������Ŀ����\n");
		printf("������:\n");
		scanf("%d", &j);
	}
	
}
