#pragma once

struct Date {
    int day;
    int month;
    int year;
};

class Student {
private:
    char name[50]{};
    Date birthDate{};

    char phone[30]{};
    char city[50]{};
    char country[50]{};
    char institution[100]{};
    char group[20]{};

public:
    // Имя
    const char* getName() const {
        return name;
    }

    void setName(const char* value) {
        strncpy_s(name, sizeof(name), value, _TRUNCATE); //если строка не помещается, обрезать её, оставив место для '\0'
    }

    // Дата рождения
    Date getBirthDate() const {
        return birthDate;
    }

    void setBirthDate(Date value) {
        if (value.day < 1 || value.day > 31 || value.month < 1 || value.month > 12 || value.year < 1900) {
            std::cout << "Invalid date!" << std::endl;
            return;
        }
        birthDate = value;
    }

    // Телефон
    const char* getPhone() const {
        return phone;
    }

    void setPhone(const char* value) {
        strncpy_s(phone, sizeof(phone), value, _TRUNCATE);
    }

    // Город
    const char* getCity() const {
        return city;
    }

    void setCity(const char* value) {
        strncpy_s(city, sizeof(city), value, _TRUNCATE);
    }

    // Страна
    const char* getCountry() const {
        return country;
    }

    void setCountry(const char* value) {
        strncpy_s(country, sizeof(country), value, _TRUNCATE);
    }

    // Учебное заведение
    const char* getInstitution() const {
        return institution;
    }

    void setInstitution(const char* value) {
        strncpy_s(institution, sizeof(institution), value, _TRUNCATE);
    }

    // Группа
    const char* getGroup() const {
        return group;
    }

    void setGroup(const char* value) {
        strncpy_s(group, sizeof(group), value, _TRUNCATE);
    }
};