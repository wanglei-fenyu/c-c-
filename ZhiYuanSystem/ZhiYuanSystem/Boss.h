//��ͨԱ��
#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;


class Boss : public Worker
{
public:

	//�вι���
	Boss(int id, string name, int did);

	//��ʾ������Ϣ
	void showInfo();

	//��ȡ��λ����
	string getDeptName();
};