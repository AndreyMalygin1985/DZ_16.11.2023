#include<iostream>
#include<Windows.h>
#include"Worker.h"

using namespace std;

// Создайте класс Worker.
// Необходимо хранить данные : ФИО, Должность, Год поступления на работу, Зарплата.
// Создать массив объектов.Вывести :
//	■ список работников, стаж работы которых на данном предприятии 
//    превосходит заданное число лет;
//	■ список работников, зарплата которых превосходит заданную;
//	■ список работников, занимающих заданную должность.
// Используйте explicit конструктор и константные функции-члены
// (например, для отображения данных о работнике и т.д.)

int main()
{
	SetConsoleOutputCP(1251);
	int choice{};
	Worker slaves[7]
	{
		Worker("Карпова Милана Романовна", "Менеджер", 2000, 50000),
		Worker("Сафонова София Тимофеевна", "Менеджер", 2000, 80000),
		Worker("Верещагина Александра Дамировна", "ИТ", 2001, 30000),
		Worker("Ковалев Богдан Михайлович", "ИТ", 2002, 10000),
		Worker("Жуков Тимур Юрьевич", "Рабочий", 2018, 90000),
		Worker("Смирнов Дмитрий Александрович", "Рабочий", 2004, 55000),
		Worker("Соболев Фёдор Иванович", "Директор", 1999, 150000)
	};

	slaves->getPost();
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "[1] - Показать всех работяг." << endl;
		cout << "[2] - Вывод рабочих, стаж которых на данном предприятии превышает заданное число лет." << endl;
		cout << "[3] - Список рабочих, зарплата которых больше заданной." << endl;
		cout << "[4] - Список рабочих, занимающих заданную должность." << endl;
		cout << "[0] - Выход." << endl << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			slaves->show(slaves, 7);
			break;
		case 2:
		{
			cout << "Введите стаж работы от 1 до 22 лет:  ";
			int experience;
			cin >> experience;
			Worker temp[7];
			int count{ 0 };
			for (size_t i{ 0 }; i < 7; i++)
			{
				if (slaves[i].getYear() <= 2023 - experience)
				{
					temp[count++] = slaves[i];
				}
			}
			cout << "Работники со стажем более " << experience << " лет:\n" << endl;
			slaves->show(temp, count); }
		break;
		case 3:
		{
			cout << "Введите зарплату:  ";
			int zpMore;
			cin >> zpMore;
			Worker zpSlaves[7];
			int count = 0;
			for (size_t i = 0; i < 7; i++) {
				if (slaves[i].getZp() > zpMore) {
					zpSlaves[count++] = slaves[i];
				}
			}
			cout << "Работники с зарплатой выше " << zpMore << ":\n " << endl;
			slaves->show(zpSlaves, count);
		}  break;
		case 4:
		{
			const char* post{ "ИТ" };
			Worker postSlaves[7];
			int count = 0;
			for (size_t i = 0; i < 7; i++)
			{
				if (strcmp(slaves[i].getPost(), post) == 0)
				{
					postSlaves[count++] = slaves[i];
				}
			}
			cout << "Работники с должностью " << post << ":" << endl;
			slaves->show(postSlaves, count);
		}
		break;
		}
	} while (choice != 0);

		return 0;
	}