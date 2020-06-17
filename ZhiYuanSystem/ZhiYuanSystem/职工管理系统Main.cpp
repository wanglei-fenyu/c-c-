#include<iostream>
#include"WorkManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

int main()
{

	WorkManager *wm = new WorkManager();

	int choice;

	while (1)
	{
		//展示菜单
		wm->Show_Menu();

		cout << "请选择你的操作:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		//退出系统
			wm->exitSystem();
			break;
		case 1:		//增加职工
			wm->Add_Emp();
			break;
		case 2:		//显示职工
			wm->Show_Emp();
			break;
		case 3:		//删除职工
			wm->Del_Emp();
			break;
		case 4:		//修改职工
			wm->Mod_Emp();
			break;
		case 5:		//查找职工
			wm->Find_Emp();
			break;
		case 6:		//职工排序
			wm->Sort_Emp();
			break;
		case 7:		//清空文档
			wm->CLean_File();
			break;

		default:
			system("cls"); //更新屏幕
			break;
		}

	}


	delete wm;
	
	return 0;
}












