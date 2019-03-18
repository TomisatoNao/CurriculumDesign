//�汾�ţ�v2.1   ��Ȩ���У�1977177093@qq.com
//��Ҫ���⣺�������ƣ�ȴ���ʲ�ͬ�Ķ��� ,�ظ��������� 
//1.1˵������ӳɼ������������ѧ�ţ��ɼ����  �޸�ʱ�䣺 10:22 2019/3/13
//1.2˵����������ȷ�������߼�����				�޸�ʱ��: 10:59 2019/3/13
//2.1˵��������ļ��������������Ľ���������ص��ı��ļ���   �޸�ʱ�䣺20:58 2019/3/15 
//�ظ���������δ������Ƿ���Ҫ�ع�  
 
#include "list.h"
#include <stdio.h>

void MathSort(List *plist) {
	struct Node *current;
	int n = 0;             //�������ж��ٸ��ڵ㣬����ð�����򣬸��Ľڵ����� 
	int j;                //����ð������
	int i;                //����ð������ 
	current = *plist;     //��¼��ǰ�ڵ� 
	struct Node *acurrent;   //��¼��һ���ڵ�
	Item tempItem;
	
	FILE *mathsort;
	if((mathsort = fopen("mathsort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(mathsort, "%-15s%-15s%-15s\n", "����", "ѧ��", "��ѧ�ɼ�");
	
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
	
	printf("\n��ѧ��������:\n\n");
	printf("%-15s%-15s%-15s\n", "����", "ѧ��", "��ѧ�ɼ�");
	
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
	int n = 0;             //�������ж��ٸ��ڵ㣬����ð�����򣬸��Ľڵ����� 
	int j;                //����ð������
	int i;                //����ð������ 
	current = *plist;     //��¼��ǰ�ڵ� 
	struct Node *acurrent;   //��¼��һ���ڵ�
	Item tempItem; 
	
	FILE *englishsort;
	if((englishsort = fopen("englishsort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(englishsort, "%-15s%-15s%-15s\n", "����", "ѧ��", "Ӣ��ɼ�");
	
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
	
	printf("\nӢ����������:\n\n");
	printf("%-15s%-15s%-15s\n", "����", "ѧ��", "Ӣ��ɼ�");
	
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
	int n = 0;             //�������ж��ٸ��ڵ㣬����ð�����򣬸��Ľڵ����� 
	int j;                //����ð������
	int i;                //����ð������ 
	current = *plist;     //��¼��ǰ�ڵ� 
	struct Node *acurrent;   //��¼��һ���ڵ�
	Item tempItem;
	
	FILE *clanguagesort;
	if((clanguagesort = fopen("clanguagesort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(clanguagesort, "%-15s%-15s%-15s\n", "����", "ѧ��", "C���Գɼ�");
	
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
	
	printf("\nC������������:\n\n");
	printf("%-15s%-15s%-15s\n", "����", "ѧ��", "C���Գɼ�");
	
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
	int n = 0;             //�������ж��ٸ��ڵ㣬����ð�����򣬸��Ľڵ����� 
	int j;                //����ð������
	int i;                //����ð������ 
	current = *plist;     //��¼��ǰ�ڵ� 
	struct Node *acurrent;   //��¼��һ���ڵ�
	Item tempItem;
	
	FILE *chinesesort;
	if((chinesesort = fopen("chinesesort.txt", "w")) == NULL) {
		printf("file can not open\n"); 
	}
	fprintf(chinesesort, "%-15s%-15s%-15s\n", "����", "ѧ��", "���ĳɼ�");
	
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
	
	printf("\n������������:\n\n");
	printf("%-15s%-15s%-15s\n", "����", "ѧ��", "���ĳɼ�");
	
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
