//��ͨԱ��
#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;


class Manager : public Worker
{
public:

	//�вι���
	Manager(int id, string name, int did);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDeptName();
};