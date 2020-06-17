#include"Manager.h"


//有参钩造
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "职工编号: " << this->m_Id << "  ";
	cout << "职工姓名: " << this->m_Name << " ";
	cout << "职工部门: " << this->getDeptName() << "  ";
	cout << "岗位职责: " << "完成老板交给我工作任务,下发任务给普通员工" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}