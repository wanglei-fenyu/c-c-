#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"Manager.h"
#include"Boss.h"
#include"Employee.h"
#include<fstream>
#define FILENAME "empFile.txt"   //�ļ�

class WorkManager
{
public:
/*******->����<-*********/

	//����
	WorkManager();

	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//����ְ��
	void Add_Emp();
	
	//�����ļ�
	void save();

	//ͳ���ļ��е�����
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//���ձ��ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����
	void Sort_Emp();

	//����ļ�
	void CLean_File();

	//����
	~WorkManager();
	

/*******->����<-*********/

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker ** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty=false;
	

};