//�汾�ţ�v1.5    ��Ȩ���У�1977177093@qq.com
//1.1˵�������ϳɼ�¼��ģ������߼�      ʱ�䣺14:11 2019/3/11
//1.2˵���� û����һ��ģ�������������    ʱ�䣺14:23 2019/3/11 
//1.3˵�����������ĳɼ�¼��ģ��д�������޸�      �޸�ʱ�䣺9:42 2019/3/12 
//1.4˵�������Ƴɼ�¼���޸ĺ��ټ���ˢ�£���ֱ�۹۲�ɼ�  �޸�ʱ�䣺 10:21 2019/3/13
/*
	1.5˵�����������⣬�ڷ�����������Ϣ¼�룬���Ƴɼ�¼���ģ���У���Ҫ�������ͬһ���˵ĳɼ�����
	�����߼��ǲ���ѧ��         ���޸�              �޸�ʱ�䣺10:27 2019/3/13 
*/


//˵������Ϊ���Ƴɼ��ֱ�¼�뵼��¼�������ͬ�����Խ��м򵥵ĳ������һ��Դ�ļ��У�������ڵ��޸�
//�������⣺�������ƣ�ȴ���ʲ�ͬ������ 

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void MathEntry(List *plist) {
	printf("\n���Գɹ�������ѧ�ɼ�¼��ģ��!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("������%s ѧ�ţ�%lld ����ѧ�ɼ�Ϊ:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nMath == -1) {
			scanf("%d", &current->item.m_nMath);
		}
		else {
			printf("%d\n", current->item.m_nMath);
		}
		current = current->next;
	}
	
	printf("\n��ѧ�ɼ�¼�����!\n"); 
}

void EnglishEntry(List *plist) {
	printf("\n���Գɹ�����Ӣ��ɼ�¼��ģ��!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("������%s ѧ�ţ�%lld ��Ӣ��ɼ�Ϊ:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nEnglish == -1) {
			scanf("%d", &current->item.m_nEnglish);
		}
		else {
			printf("%d\n", current->item.m_nEnglish);
		}
		current = current->next;
	}
	
	printf("\nӢ��ɼ�¼�����!\n"); 
}

void CLanguageEntry(List *plist) {
	printf("\n���Գɹ�����C���Գɼ�¼��ģ��!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("������%s ѧ�ţ�%lld ��C���Գɼ�Ϊ:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nCLanguage == -1) {
			scanf("%d", &current->item.m_nCLanguage);
		}
		else {
			printf("%d\n", current->item.m_nCLanguage);
		}
		current = current->next;
	}
	
	printf("\nc���Գɼ�¼�����!\n");
}

void ChineseEntry(List *plist) {
	printf("\n���Գɹ��������ĳɼ�¼��ģ��!\n\n");
	
	struct Node *current;
	current = *plist;
	
	while (current != NULL) {
		printf("������%s ѧ�ţ�%lld �����ĳɼ�Ϊ:", current->item.m_strName, current->item.m_lnStudentID);
		if(current->item.m_nEnglish == -1) {
			scanf("%d", &current->item.m_nChinese);
		}
		else {
			printf("%d\n", current->item.m_nChinese);
		}
		current = current->next;
	}
	
	printf("\n���ĳɼ�¼�����!\n"); 
}
