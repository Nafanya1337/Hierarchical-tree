#include "Base.h"
#include "A.h"
#include "B.h"


// параметризированный конструктор с параметрами: указатель на головной объект в дереве иерархии и наименование объекта
Base::Base(Base* parent_ptr, string name)
{
	this->parent_ptr = parent_ptr;
	this->name = name;
	if (parent_ptr != nullptr) parent_ptr->children.push_back(this); // сразу записываем в вектор родителя указатель на нового ребенка
}

//перегрузка конструктора для создания базоваго объекта класса Base
Base::Base(Base* parent_ptr)
{
	this->parent_ptr = parent_ptr;
}

// метод определения имени объекта
void Base::SetName(string name)
{
	this->name = name;
}

// метод получения имени объекта
string Base::GetName()
{
	return name;
}

// метод переопределения головного объекта для текущего в дереве иерархии
void Base::SetParentPtr(Base* parent_ptr)
{
	this->parent_ptr = parent_ptr;
}

// метод получения указателя на головной объект текущего объекта
Base* Base::GetParentPtr()
{
	return parent_ptr;
}

// основной метод для вывода всего иерархического дерева
void Base::ShowTree()
{
	cout << this->GetName() << " ";
	for (int i = 0; i < this->children.size(); i++)
	{
		if (children[i]->children.size() > 0) // если какой-то из детей имеет своих детей, то выводим и его дерево
		{
			cout << children[i]->GetName();
			cout << endl;
			children[i]->ShowTree(); //рекурсивно выводим все иерархические деревья
		}
		else // иначе выводим имя ребенка
		{
			cout << children[i]->GetName() << " ";
		}
	}
}

// основной метод для построения иерархического дерева
void Base::BuildTreeObjects()
{
	string base, name_parrent, newchildren;
	A* obj1 = nullptr; // обнуляем изначальные указатели
	B* obj2 = nullptr;
	cin >> base;
	this->SetName(base);
	while (true)
	{
		cin >> name_parrent >> newchildren;
		if (name_parrent != newchildren) // если имя класса предка не равняется имени класса наследника(дитя)
		{
			if (this->name == name_parrent) // если имя базового класса совпадает с именем вводимого класса предка
			{
				obj1 = new A(this, newchildren); // создание дочерних объектов базового класса
				obj2 = nullptr; // обнуляем наследумый объект
			}
			else
			{
				if (obj2 == nullptr or obj1->GetName() == name_parrent) // если ссылка на объект 2 - обнулена ИЛИ объект 2 принадлежит уже созданному головному объекту
				{
					obj2 = new B(obj1, newchildren); // то создаем новый объект
				}
				else // иначе ЕСЛИ надо создать иерархию в уже ныне существующей иерархии
				{
					obj2 = new B(obj2, newchildren); // создаем новую переменную, которая будет ссылаться на старую
					// фактически мы перемещаем указатели на объекты для новых созданных объектов
					obj1->SetParentPtr(obj1); // изменяем указатель на родителя 1 объекта
				}

			}
		}
		else break; // иначе прерываем ввод
	}
	cout << GetName() << endl; // выводим наименование головного объекта
	this->ShowTree(); //выводим дерево иерархии
}

// метод запуска приложения
int Base::exec_app() 
{
	return 0;
}