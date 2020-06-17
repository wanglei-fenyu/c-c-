#include"WorkManager.h"


WorkManager::WorkManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڵ���û����
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout <<"�ļ�����Ϊ��"<< endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//���ļ����ڲ��������ݴ���
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "���" << this->m_EmpArray[i]->m_Id <<"	";
		cout << "����" << this->m_EmpArray[i]->m_Name << "	";
		cout << "����" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
	
}

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum;i++)
		{
			this->m_EmpArray[i] = NULL;
		}
		
		delete[] this->m_EmpArray;
	}
}


void WorkManager::Show_Menu()
{
	cout << "--------------------------------------------------" << endl;
	cout << "|------------->��ӭʹ��ְ������ϵͳ<-------------|" << endl;
	cout << "|---------------  0.�˳��������   --------------|" << endl;
	cout << "|---------------  1.����ְ����Ϣ   --------------|" << endl;
	cout << "|---------------  2.��ʾְ����Ϣ   --------------|" << endl;
	cout << "|---------------  3.ɾ��ְ����Ϣ   --------------|" << endl;
	cout << "|---------------  4.�޸�ְ����Ϣ   --------------|" << endl;
	cout << "|---------------  5.����ְ����Ϣ   --------------|" << endl;
	cout << "|---------------  6.���ձ������   --------------|" << endl;
	cout << "|---------------  7.��������ĵ�   --------------|" << endl;
	cout << "--------------------------------------------------" << endl;
}






//�˳�ϵͳ
void WorkManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}



void WorkManager::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker *[newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ:" << endl;
			cout << "-> 1.��ְͨ��" << endl;
			cout << "-> 2.����" << endl;
			cout << "-> 3.�ϰ�" << endl;
			cin >> dSelect;

			Worker * worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				i = i - 1;
				cout << "������������������!!!" << endl;
				break;
			}
			//����ְ�����浽����
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�ʶ
		this->m_FileIsEmpty = false;

		//�ɹ���Ӻ󣬱��浽�ļ���
		this->save();

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��ְ��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�
	//��ÿ��ְ������д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}



//ͳ���ļ��е�����
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;
}


//��ʼ��ְ��
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker *worker = NULL;

		if (did == 1)  //��ͨԱ��
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2) //����
		{
			worker = new Manager(id, name, did);
		}
		else //�ϰ�
		{
			worker = new Boss(id, name, did);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾְ��
void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������� ���� ��¼Ϊ�գ�����" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//�����������
	system("pause");
	system("cls");
}



//���ձ��ɾ��ְ��
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������� ���� ��¼Ϊ�գ�����" << endl;
	}
	else
	{
		//���ձ��ɾ��ְ��
		cout << "������Ҫɾ��ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//ְ������
		{
			for (int i = index; i < this->m_EmpNum - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//��������Ԫ�ظ���

			//����ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�� δ�ҵ���ְ��������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����
int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}





//�޸�ְ��
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������� ���� ��¼Ϊ�գ�����" << endl;
	}
	else
	{
		//���ձ��ɾ��ְ��
		cout << "������Ҫ�޸ĵ�ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);

		if (ret != -1)
		{
			//���ҵ�
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newname = "";
			int dSelect = 0;

			cout << "�鵽:" << id << "��ְ����������ְ����" << endl;
			cin >> newId;
			cout << "�������µ�����:"<< endl;
			cin >> newname;
			cout << "��ѡ���¸�λ" << endl;
			cout << "-> 1.��ְͨԱ" << endl;
			cout << "-> 2.����" << endl;
			cout << "-> 3.�ϰ�" << endl;
			cin >> dSelect;
			Worker *worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newname, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newname, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newname, dSelect);
				break;
			default:
				break;
			}

			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			//�����ļ���
			this->save();

			cout << "�޸ĳɹ���" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}



//����ְ��
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������� ���� ��¼Ϊ�գ�����" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ:"<< endl;
		cout << "-> 1.��ְ����Ų���" << endl;
		cout << "-> 2.��ְ����������" << endl;

		int selsct = 0;
		cin >> selsct;
		if (selsct == 1)
		{
			int  id;
			cout << "������Ҫ���ҵ�ְ���ı��:" << endl;
			cin >> id;
			int ret = IsExist(id);

			if (ret != -1)
			{
				cout << "���ҳɹ��� ��ְ����Ϣ����..." << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "���޴��� ����ʧ�ܣ�����" << endl;
			}
		}
		else if (selsct == 2)
		{
			string name;
			cout << "������������ְ��������:" << endl;
			cin >> name;

			bool flag = false;//Ĭ��δ�ҵ�


			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "�ɹ�����--->���:" << this->m_EmpArray[i]->m_Id << "��Ա����Ϣ����" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
	 
				}
			}
			if (flag == false)
			{
				cout << "���޴��� ����ʧ�ܣ�����" << endl;
			}
		}
		else
		{
			cout << "����ѡ������ ����ʧ�ܣ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������� ���� ��¼Ϊ�գ�����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ:" << endl;
		cout << "-> 1.���� (��ְ�����)" << endl;
		cout << "-> 2.���� (��ְ�����)" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrmax = i;
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrmax]->m_Id>this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrmax]->m_Id<this->m_EmpArray[j]->m_Id)
					{
						minOrmax = j;
					}
				}
			}

			//�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ�������ֵ��Сֵ���߽�������
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "����ɹ���" << endl;
		this->save();
		this->Show_Emp();
	}

}


//����ļ�
void WorkManager:: CLean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "-> 1.ȷ��" << endl;
	cout << "-> 2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//������ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ����ڴ���
		ofs.close();
		
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				 this->m_EmpArray[i] = NULL;
				 
			}

			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}





