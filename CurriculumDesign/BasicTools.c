// version:1.0    版权所有：1977177093@qq.com 

#include <windows.h>    //提供api函数，对界面进行一定的设置
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void SetWindow(){
	system("title 学生成绩录入工具");//设置cmd窗口标题
	system("mode con cols=70 lines=25");//窗口宽度高度
	system("date /T");
	system("TIME /T");
}

void MainMenu(){
	printf("╪╪╪╪╪╪╧╧╧╧╧╧╧╪╪╪╪╪╪\n");
	printf("╔═══╧╧ 学生成绩录入 ╧╧═══╗\n");
	printf("║※0.成绩查询                      ║\n");
	printf("║※1.学生单科成绩录入              ║\n");
	printf("║※2.学生基本信息录入              ║\n");
	printf("║※3.挂科两门以上同学统计　        ║\n");
	printf("║※4.单科成绩排名                  ║\n");
	printf("║※5.退出程序(写入stdif.txt中)     ║\n");
	printf("╚═════════════════╝\n");
	
	printf("ps:当没有信息被存入时，调用对信息进行访问的模块，会直接重返主菜单\n");
}


void MainMenuSelct(int i, List *plist){
	switch (i){
		case 0:
			ScoreQery(plist);     //成绩查询函数， 
			break;
		case 1:
			SgSbScEntry(plist);    //单科成绩录入函数，
			break;
		case 2:
			IfmtEntry(plist);      //学生基本信息录入函数，
			break;
		case 3:
			TwoFail(plist);       //挂科统计函数，
			break; 
		case 4:
			SgScSort(plist);     //单科排名查询函数
			break;
		case 5:
			ReadList(plist);
			Release(plist);                 //释放内存 
			system("cls"); 
			printf("\n谢谢您对学生成绩录入工具的信赖，开发人员在此特别鸣谢\n");
			exit(0);
			break;
	}
}
