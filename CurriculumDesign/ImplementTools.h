// version:1.1    ��Ȩ���У�1977177093@qq.com
//����˵��Ƴɼ������Ĺ��ܺ���       �޸�ʱ�䣺11:15 2019/3/12

#ifndef _IMPLEMENTTOOLS_H
#define _IMPLEMENTTOOLS_H

#include "list.h"

/*
	���ܣ����ڳɼ���ѯ
	 	�ṩ���ֳɼ���ѯ��ʽ��һ��Ϊ�����ֽ��в�ѯ��һ��Ϊ��ѧ�Ž��в�ѯ 
*/
void ScoreQery(List *plist);

/*
	���ܣ����ڵ��Ƴɼ�¼��
		�ṩ��Ŀѡ��ѡ���Ŀ�󣬴������ж���������Ϣ�������������������ؿ�Ŀ�ɼ���д�������� 
*/
void SgSbScEntry(List *plist);

/* 
	���ܣ�����ѧ����Ϣ¼�� 
*/ 
void IfmtEntry(List *plist);

/*
	���ܣ�����ͳ�ƹҿƳ������Ƶ�ѧ�� 
*/
void TwoFail(List *plist);

/*
	���ܣ����ڵ��Ƴɼ������� 
*/
void SgScSort(List *plist);
#endif
