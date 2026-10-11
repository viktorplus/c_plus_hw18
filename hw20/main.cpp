#include <iostream>
#include <windows.h>
#include "Student.h"

using namespace std;

//Завдання
//Реалізуйте клас "Студент".
//Необхідно зберігати у змінних - членах класу :
//Ім'я, дату народження, контактний телефон, місто, країну, назву навчального закладу, номер групи.
//Реалізуйте функції - члени класу для введення даних, виведення даних, реалізуйте аксесори для доступу до окремих змінних - членів.


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Student student;

    // Заполняем данные через сеттеры
    student.setName("Іван Петренко");
    student.setBirthDate({ 15, 6, 2005 });
    student.setPhone("+380501234567");
    student.setCity("Київ");
    student.setCountry("Україна");
    student.setInstitution("Комп'ютерна академія");
    student.setGroup("П-21");

    // Получаем данные через геттеры
    cout << "Ім'я: " << student.getName() << endl;

    Date date = student.getBirthDate();
    cout << "Дата народження: "
        << date.day << "." << date.month << "." << date.year << endl;

    cout << "Телефон: " << student.getPhone() << endl;
    cout << "Місто: " << student.getCity() << endl;
    cout << "Країна: " << student.getCountry() << endl;
    cout << "Навчальний заклад: " << student.getInstitution() << endl;
    cout << "Група: " << student.getGroup() << endl;

    return 0;
}