#include"Employee.h"


//�вι���
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����: " << this->m_Id << "  ";
	cout << "ְ������: " << this->m_Name << "  ";
	cout << "ְ������: " << this->getDeptName() << "  ";
	cout << "��λְ��: " << "��ɾ������ҹ�������" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("��ͨԱ��");
}