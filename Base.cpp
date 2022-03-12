#include "Base.h"
#include "A.h"
#include "B.h"


// ������������������� ����������� � �����������: ��������� �� �������� ������ � ������ �������� � ������������ �������
Base::Base(Base* parent_ptr, string name)
{
	this->parent_ptr = parent_ptr;
	this->name = name;
	if (parent_ptr != nullptr) parent_ptr->children.push_back(this); // ����� ���������� � ������ �������� ��������� �� ������ �������
}

//���������� ������������ ��� �������� �������� ������� ������ Base
Base::Base(Base* parent_ptr)
{
	this->parent_ptr = parent_ptr;
}

// ����� ����������� ����� �������
void Base::SetName(string name)
{
	this->name = name;
}

// ����� ��������� ����� �������
string Base::GetName()
{
	return name;
}

// ����� ��������������� ��������� ������� ��� �������� � ������ ��������
void Base::SetParentPtr(Base* parent_ptr)
{
	this->parent_ptr = parent_ptr;
}

// ����� ��������� ��������� �� �������� ������ �������� �������
Base* Base::GetParentPtr()
{
	return parent_ptr;
}

// �������� ����� ��� ������ ����� �������������� ������
void Base::ShowTree()
{
	cout << this->GetName() << " ";
	for (int i = 0; i < this->children.size(); i++)
	{
		if (children[i]->children.size() > 0) // ���� �����-�� �� ����� ����� ����� �����, �� ������� � ��� ������
		{
			cout << children[i]->GetName();
			cout << endl;
			children[i]->ShowTree(); //���������� ������� ��� ������������� �������
		}
		else // ����� ������� ��� �������
		{
			cout << children[i]->GetName() << " ";
		}
	}
}

// �������� ����� ��� ���������� �������������� ������
void Base::BuildTreeObjects()
{
	string base, name_parrent, newchildren;
	A* obj1 = nullptr; // �������� ����������� ���������
	B* obj2 = nullptr;
	cin >> base;
	this->SetName(base);
	while (true)
	{
		cin >> name_parrent >> newchildren;
		if (name_parrent != newchildren) // ���� ��� ������ ������ �� ��������� ����� ������ ����������(����)
		{
			if (this->name == name_parrent) // ���� ��� �������� ������ ��������� � ������ ��������� ������ ������
			{
				obj1 = new A(this, newchildren); // �������� �������� �������� �������� ������
				obj2 = nullptr; // �������� ���������� ������
			}
			else
			{
				if (obj2 == nullptr or obj1->GetName() == name_parrent) // ���� ������ �� ������ 2 - �������� ��� ������ 2 ����������� ��� ���������� ��������� �������
				{
					obj2 = new B(obj1, newchildren); // �� ������� ����� ������
				}
				else // ����� ���� ���� ������� �������� � ��� ���� ������������ ��������
				{
					obj2 = new B(obj2, newchildren); // ������� ����� ����������, ������� ����� ��������� �� ������
					// ���������� �� ���������� ��������� �� ������� ��� ����� ��������� ��������
					obj1->SetParentPtr(obj1); // �������� ��������� �� �������� 1 �������
				}

			}
		}
		else break; // ����� ��������� ����
	}
	cout << GetName() << endl; // ������� ������������ ��������� �������
	this->ShowTree(); //������� ������ ��������
}

// ����� ������� ����������
int Base::exec_app() 
{
	return 0;
}