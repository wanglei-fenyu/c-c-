#include"Manager.h"


//�вι���
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ�����: " << this->m_Id << "  ";
	cout << "ְ������: " << this->m_Name << " ";
	cout << "ְ������: " << this->getDeptName() << "  ";
	cout << "��λְ��: " << "����ϰ彻���ҹ�������,�·��������ͨԱ��" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}