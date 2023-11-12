//Класс Фабрика хранит данные о мебели, работниках и машинах.Для мебели
//определено : тип мебели, габариты(высота, ширина, глубина), цвет, материал,
//стоимость.Для работника определено : ФИО, должность, заработная плата,
//адрес проживания, телефон.Для машины определено : марка, модель,
//гос.номер.
#include <iostream>
#include "keeper.h"
#include "deque.h"
#include "queue.h"
#include "stack.h"
#include "list.h"
#include "menu.h"
using namespace std;
string main_menu = "1-Дек\n2-Стек\n3-Список\n4-Выход\n";
int main()
{
	setlocale(LC_ALL, "russian");
	Keeper<Deque> deque;
	Keeper<Stack> stack;
	Keeper<List> list;
	int button;
	bool flag = true;
	while (flag)
	{
		system("cls");
		std::cout << main_menu;
		std::cin >> button;
		switch (button) {
		case 1:
			Menu(deque, "Deque.txt");
			break;
		case 2:
			Menu(stack, "Stack.txt");
			break;
		case 3:
			Menu(list, "List.txt");
			break;
		case 4:
			flag = false;
			std::cout << "Work is over\n";
			break;
		default:
			std::cout << "Wrong value\n";
			system("pause");
			break;
		}
	}
	return 0;
}