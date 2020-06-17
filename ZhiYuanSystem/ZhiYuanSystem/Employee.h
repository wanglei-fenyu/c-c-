//普通员工
#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;


class Employee : public Worker
{
public:

	//有参钩造
	Employee(int id,string name,int did);

	//显示个人信息
	void showInfo() ;

	//获取岗位名称
	string getDeptName();
};