#include"WorkManager.h"


WorkManager::WorkManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在但是没数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout <<"文件内容为空"<< endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//当文件存在并且有数据存在
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "编号" << this->m_EmpArray[i]->m_Id <<"	";
		cout << "姓名" << this->m_EmpArray[i]->m_Name << "	";
		cout << "部门" << this->m_EmpArray[i]->m_DeptId << endl;
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
	cout << "|------------->欢迎使用职工管理系统<-------------|" << endl;
	cout << "|---------------  0.退出管理程序   --------------|" << endl;
	cout << "|---------------  1.增加职工信息   --------------|" << endl;
	cout << "|---------------  2.显示职工信息   --------------|" << endl;
	cout << "|---------------  3.删除职工信息   --------------|" << endl;
	cout << "|---------------  4.修改职工信息   --------------|" << endl;
	cout << "|---------------  5.查找职工信息   --------------|" << endl;
	cout << "|---------------  6.按照编号排序   --------------|" << endl;
	cout << "|---------------  7.清空所有文档   --------------|" << endl;
	cout << "--------------------------------------------------" << endl;
}






//退出系统
void WorkManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}



void WorkManager::Add_Emp()
{
	cout << "请输入添加职工数量:" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker *[newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			cout << "请选择该职工岗位:" << endl;
			cout << "-> 1.普通职工" << endl;
			cout << "-> 2.经理" << endl;
			cout << "-> 3.老板" << endl;
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
				cout << "输入有误请重新输入!!!" << endl;
				break;
			}
			//将新职工保存到数组
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空的标识
		this->m_FileIsEmpty = false;

		//成功添加后，保存到文件中
		this->save();

		//提示添加成功
		cout << "成功添加" << addNum << "名职工" << endl;
	}
	else
	{
		cout << "输入数据有误！" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件
	//将每个职工数据写入文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}



//统计文件中的人数
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

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


//初始化职工
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

		if (did == 1)  //普通员工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2) //经理
		{
			worker = new Manager(id, name, did);
		}
		else //老板
		{
			worker = new Boss(id, name, did);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工
void WorkManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空！！！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}



//按照编号删除职工
void WorkManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空！！！" << endl;
	}
	else
	{
		//按照编号删除职工
		cout << "请输入要删除职工的编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)//职工存在
		{
			for (int i = index; i < this->m_EmpNum - 1;i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组元素个数

			//数据同步到文件里
			this->save();
			cout << "删除成功。" << endl;
		}
		else
		{
			cout << "删除失败 未找到该职工！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在
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





//修改职工
void WorkManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空！！！" << endl;
	}
	else
	{
		//按照编号删除职工
		cout << "请输入要修改的职工的编号:" << endl;
		int id = 0;
		cin >> id;
		int ret = this->IsExist(id);

		if (ret != -1)
		{
			//查找到
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newname = "";
			int dSelect = 0;

			cout << "查到:" << id << "号职工亲输入新职工号" << endl;
			cin >> newId;
			cout << "请输入新的姓名:"<< endl;
			cin >> newname;
			cout << "请选择新岗位" << endl;
			cout << "-> 1.普通职员" << endl;
			cout << "-> 2.经理" << endl;
			cout << "-> 3.老板" << endl;
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

			//跟新数据到数组中
			this->m_EmpArray[ret] = worker;

			//保存文件中
			this->save();

			cout << "修改成功。" << endl;
		}
		else
		{
			cout << "修改失败，查无此人！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}



//查找职工
void WorkManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空！！！" << endl;
	}
	else
	{
		cout << "请选择查找方式:"<< endl;
		cout << "-> 1.按职工编号查找" << endl;
		cout << "-> 2.按职工姓名查找" << endl;

		int selsct = 0;
		cin >> selsct;
		if (selsct == 1)
		{
			int  id;
			cout << "请输入要查找的职工的编号:" << endl;
			cin >> id;
			int ret = IsExist(id);

			if (ret != -1)
			{
				cout << "查找成功！ 该职工信息如下..." << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查无此人 查找失败！！！" << endl;
			}
		}
		else if (selsct == 2)
		{
			string name;
			cout << "请输入所查找职工的姓名:" << endl;
			cin >> name;

			bool flag = false;//默认未找到


			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "成功查找--->编号:" << this->m_EmpArray[i]->m_Id << "号员工信息如下" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
	 
				}
			}
			if (flag == false)
			{
				cout << "查无此人 查找失败！！！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误 查找失败！！！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序
void WorkManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在 或者 记录为空！！！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式:" << endl;
		cout << "-> 1.升序 (按职工编号)" << endl;
		cout << "-> 2.降序 (按职工编号)" << endl;
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

			//判断一开始认定的最小值或最大值是不是计算的最大值最小值否者交换数据
			if (i != minOrmax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrmax];
				this->m_EmpArray[minOrmax] = temp;
			}
		}
		cout << "排序成功！" << endl;
		this->save();
		this->Show_Emp();
	}

}


//清空文件
void WorkManager:: CLean_File()
{
	cout << "确定清空？" << endl;
	cout << "-> 1.确定" << endl;
	cout << "-> 2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后在创建
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
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}





