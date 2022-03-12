#include <iostream>
#include "Base.h"


int main()
{
	Base obj_base(nullptr); // создаем ГЛАВНЫЙ объект
	obj_base.BuildTreeObjects(); // Построение дерева объектов
	return obj_base.exec_app(); // запуск системы
}