#include"Boss.h"

#include"Manager.h"


//有参钩造
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "职工编号: " << this->m_Id << "  ";
	cout << "职工姓名: " << this->m_Name << "  ";
	cout << "职工部门: " << this->getDeptName() << "  ";
	cout << "岗位职责: " << "下发任务给经理，并且决定公司发展方向" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}