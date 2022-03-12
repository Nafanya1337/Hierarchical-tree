#ifndef _Base_H
#define _Base_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Base
{
public:
	Base(Base* parent_ptr, string name); // �����������
	Base(Base* parent_ptr); //���������� ������������ ��� �������� �������� ������� ������ Base
	string GetName();
	void SetName(string name);
	void SetParentPtr(Base* parent_ptr); // ����� ��� ��������� ��������� �� ��������
	Base* GetParentPtr(); // ����� ��������� ��������� �� �������� ������ �������� �������
	void ShowTree(); // �������� ����� ��� ������ ����� �������������� ������
	void BuildTreeObjects();
	int exec_app();
protected:
	Base* parent_ptr; //��������� �� ��������
	string name = "name"; //��� �������, ������� �� ��������� ����� ��� name
	vector<Base*> children; //������ ���������� �� �����
};

#endif