#include"Boss.h"

#include"Manager.h"


//�вι���
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ�����: " << this->m_Id << "  ";
	cout << "ְ������: " << this->m_Name << "  ";
	cout << "ְ������: " << this->getDeptName() << "  ";
	cout << "��λְ��: " << "�·�������������Ҿ�����˾��չ����" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}