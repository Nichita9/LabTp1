#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;
template <class T>
class Keeper
{
public:
	Keeper(int num);
	Keeper();
	~Keeper();
	Keeper(const Keeper<T>& obj);
	void Push();
	void Pop();
	void Show();
	void InFile(string& file);
	void FromFile(string& file);
private:
	T object;
	int size;
};
template<class T>
Keeper<T>::Keeper(int num)
{
	object.object(num);
	size = 1;
}

template<class T>
Keeper<T>::Keeper()
{
	cout << "Вызван конструктор по умолчанию Keeper\n";
	size = 0;
}
template<class T>
Keeper<T>::Keeper(const Keeper<T>& obj)
{
	object = obj.object;
	size = obj.size;
}

template<class T>
Keeper<T>::~Keeper()
{
	cout << "Вызван деструктор Keeper\n";
	object.~object();
}

template<class T>
void Keeper<T>::Push()
{
	cin >> object;
	++size;
	cout << "\nДобавлен новый объект\n";
}

template<class T>
void Keeper<T>::Pop()
{
	try
	{
		if (size == 0)
		{
			exception empty("Объект пуст");
			throw empty;
		}
		object--;
		--size;
		cout << "\nЭлемент удален\n";
	}
	catch (exception& error)
	{
		cout << error.what() << endl;
	}
}
template<class T>
void Keeper<T>::Show()
{
	try
	{
		if (size == 0)
		{
			exception empty("Объект пуст");
			throw empty;
		}
		cout << object << endl;
	}
	catch (exception& error)
	{
		cout << error.what() << endl;
	}
}
template<class T>
void Keeper<T>::InFile(string& file)
{
	ofstream fout(file, ios::out);
	try
	{
		if (size == 0)
		{
			exception empty("Объект пуст");
			throw empty;
		}
		fout << size << endl;
		fout << object;
		cout << "Запись успешна" << endl;
	}
	catch (exception& error)
	{
		cout << error.what() << endl;
		fout.close();
	}
}
template <class T>
void Keeper<T>::FromFile(string& file)
{
	ifstream fin(file, ios::in);
	try {
		if (!fin.is_open()) {
			exception error("Ошибка открытия файла");
			throw error;
		}
		if (fin.peek() == EOF) {
			exception empty("Файл пуст");
			throw empty;
		}
		while (size != 0)
		{
			object -= 1;
			size -= 1;
		}
		fin >> object;
		size = object.GetSize();
		fin.close();
		cout << "Чтение успешно" << endl;
	}
	catch (exception& error)
	{
		cout << error.what() << endl;
		fin.close();
	}
}
