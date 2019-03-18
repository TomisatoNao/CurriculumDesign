// version:1.1    版权所有：1977177093@qq.com 

#ifndef _BASICTOOLS_H
#define _BASICTOOLS_H

/*
	功能：设置窗口名称，宽高，颜色 
	以及显示具体打开窗口的日期 
*/
void SetWindows();

/*
	功能：提供选择菜单
	为学生录入信息系统提供基本的功能选择 
*/
void MainMenu();

/*
	功能：主菜单选择工具，传入参数用于中转调用相应的工具 
*/
void MainMenuSelct(int i, List *plist);

#endif
