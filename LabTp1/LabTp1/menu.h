#pragma once
#pragma once
#include "keeper.h"
#include "queue.h"
#include "deque.h"
#include "list.h"
#include "stack.h"
#include <iostream>
string menu = "1-�������� �������\n2-������� �������\n3-�������� ������\n4-��������� � ����\n5-������� �� �����\n6-��������� � ���������� ����\n";
template<typename T>
void Menu(T object, string file)
{
	int choose, i;
	bool flag = true;
	setlocale(LC_ALL, "russian");
	while (flag)
	{
		system("cls");
		std::cout << menu;
		std::cin >> choose;
		system("cls");
		switch (choose) {
		case 1:
			object.Push();
			system("pause");
			break;
		case 2:
			object.Show();
			object.Pop();
			system("pause");
			break;
		case 3:
			object.Show();
			system("pause");
			break;
		case 4:
			object.InFile(file);
			system("pause");
			break;
		case 5:
			object.FromFile(file);
			system("pause");
			break;
		case 6:
			flag = false;
			std::cout << "Returning\n";
			system("pause");
			break;
		default:
			std::cout << "Wrong input\n";
			system("pause");
			break;
		}
	}
}