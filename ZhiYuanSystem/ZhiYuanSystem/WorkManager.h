#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"Manager.h"
#include"Boss.h"
#include"Employee.h"
#include<fstream>
#define FILENAME "empFile.txt"   //文件

class WorkManager
{
public:
/*******->方法<-*********/

	//钩造
	WorkManager();

	//显示菜单
	void Show_Menu();

	//退出系统
	void exitSystem();

	//增加职工
	void Add_Emp();
	
	//保存文件
	void save();

	//统计文件中的人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//按照编号删除职工
	void Del_Emp();

	//判断职工是否存在
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序
	void Sort_Emp();

	//清空文件
	void CLean_File();

	//析构
	~WorkManager();
	

/*******->属性<-*********/

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker ** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty=false;
	

};