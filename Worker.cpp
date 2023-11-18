#include <iostream>
#include <Windows.h>
#include "Worker.h"

using namespace std;

void Worker::show(const Worker* slave, int count) const {
    for (int i = 0; i < count; i++) {
        cout << "ФИО: " << slave[i].getFio() << endl;
        cout << "Должность: " << slave[i].getPost() << endl;
        cout << "Год поступления: " << slave[i].getYear() << endl;
        cout << "Зарплата: " << slave[i].getZp() << endl << endl;
    }
    cout << endl;
}