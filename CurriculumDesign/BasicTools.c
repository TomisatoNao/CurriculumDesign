// version:1.0    ��Ȩ���У�1977177093@qq.com 

#include <windows.h>    //�ṩapi�������Խ������һ��������
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void SetWindow(){
	system("title ѧ���ɼ�¼�빤��");//����cmd���ڱ���
	system("mode con cols=70 lines=25");//���ڿ�ȸ߶�
	system("date /T");
	system("TIME /T");
}

void MainMenu(){
	printf("�n�n�n�n�n�n�k�k�k�k�k�k�k�n�n�n�n�n�n\n");
	printf("�X�T�T�T�k�k ѧ���ɼ�¼�� �k�k�T�T�T�[\n");
	printf("�U��0.�ɼ���ѯ                      �U\n");
	printf("�U��1.ѧ�����Ƴɼ�¼��              �U\n");
	printf("�U��2.ѧ��������Ϣ¼��              �U\n");
	printf("�U��3.�ҿ���������ͬѧͳ�ơ�        �U\n");
	printf("�U��4.���Ƴɼ�����                  �U\n");
	printf("�U��5.�˳�����(д��stdif.txt��)     �U\n");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	
	printf("ps:��û����Ϣ������ʱ�����ö���Ϣ���з��ʵ�ģ�飬��ֱ���ط����˵�\n");
}


void MainMenuSelct(int i, List *plist){
	switch (i){
		case 0:
			ScoreQery(plist);     //�ɼ���ѯ������ 
			break;
		case 1:
			SgSbScEntry(plist);    //���Ƴɼ�¼�뺯����
			break;
		case 2:
			IfmtEntry(plist);      //ѧ��������Ϣ¼�뺯����
			break;
		case 3:
			TwoFail(plist);       //�ҿ�ͳ�ƺ�����
			break; 
		case 4:
			SgScSort(plist);     //����������ѯ����
			break;
		case 5:
			ReadList(plist);
			Release(plist);                 //�ͷ��ڴ� 
			system("cls"); 
			printf("\nлл����ѧ���ɼ�¼�빤�ߵ�������������Ա�ڴ��ر���л\n");
			exit(0);
			break;
	}
}
