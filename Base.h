#ifndef _Base_H
#define _Base_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Base
{
public:
	Base(Base* parent_ptr, string name); // конструктор
	Base(Base* parent_ptr); //перегрузка конструктора для создания базоваго объекта класса Base
	string GetName();
	void SetName(string name);
	void SetParentPtr(Base* parent_ptr); // метод для изменения указателя на родителя
	Base* GetParentPtr(); // метод получения указателя на головной объект текущего объекта
	void ShowTree(); // основной метод для вывода всего иерархического дерева
	void BuildTreeObjects();
	int exec_app();
protected:
	Base* parent_ptr; //указатель на родителя
	string name = "name"; //имя объекта, которое по умолчанию имеет имя name
	vector<Base*> children; //вектор указателей на детей
};

#endif