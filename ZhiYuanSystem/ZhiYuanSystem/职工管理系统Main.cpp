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
		//չʾ�˵�
		wm->Show_Menu();

		cout << "��ѡ����Ĳ���:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:		//�˳�ϵͳ
			wm->exitSystem();
			break;
		case 1:		//����ְ��
			wm->Add_Emp();
			break;
		case 2:		//��ʾְ��
			wm->Show_Emp();
			break;
		case 3:		//ɾ��ְ��
			wm->Del_Emp();
			break;
		case 4:		//�޸�ְ��
			wm->Mod_Emp();
			break;
		case 5:		//����ְ��
			wm->Find_Emp();
			break;
		case 6:		//ְ������
			wm->Sort_Emp();
			break;
		case 7:		//����ĵ�
			wm->CLean_File();
			break;

		default:
			system("cls"); //������Ļ
			break;
		}

	}


	delete wm;
	
	return 0;
}












