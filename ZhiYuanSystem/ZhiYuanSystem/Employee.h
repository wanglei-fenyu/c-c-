//��ͨԱ��
#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;


class Employee : public Worker
{
public:

	//�вι���
	Employee(int id,string name,int did);

	//��ʾ������Ϣ
	void showInfo() ;

	//��ȡ��λ����
	string getDeptName();
};