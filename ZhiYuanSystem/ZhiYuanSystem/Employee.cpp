#include"Employee.h"


//有参钩造
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "职工编号: " << this->m_Id << "  ";
	cout << "职工姓名: " << this->m_Name << "  ";
	cout << "职工部门: " << this->getDeptName() << "  ";
	cout << "岗位职责: " << "完成经理交给我工作任务" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//获取岗位名称
string Employee::getDeptName()
{
	return string("普通员工");
}