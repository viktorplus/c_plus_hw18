#include <iostream>
#include <cstring>
#include "types.h"
#include "party.h"
#include "save.h"

using namespace std;

// ================== ЕТАП 1: CREATE + READ ==================

// 1.1. Додати героя в кінець масиву
void recruitHero(PartyList& party, Character newHero)
{
    Character* newHeroes = new Character[party.size + 1];

    for (int i = 0; i < party.size; i++)
    {
        newHeroes[i] = party.heroes[i];
    }

    newHeroes[party.size] = newHero;

    delete[] party.heroes;
    party.heroes = newHeroes;
    party.size++;
}

// 1.2. Знайти індекс героя за ім'ям
int findHeroIndex(const PartyList& party, const char* searchName)
{
    for (int i = 0; i < party.size; i++)
    {
        if (strcmp(party.heroes[i].name, searchName) == 0)
        {
            return i;
        }
    }

    return -1;
}

// 1.3. Повернути копію героя за ім'ям
Character getHeroByName(const PartyList& party, const char* searchName)
{
    Character emptyHero{};
    emptyHero.level = -1;

    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        return emptyHero;
    }

    return party.heroes[index];
}

// 1.4. Вивести весь табір
void printParty(const PartyList& party)
{
    if (party.heroes == nullptr || party.size <= 0)
    {
        cout << "Табір порожній!" << endl;
        return;
    }

    cout << "\n===== TABIR HEROIV =====" << endl;

    for (int i = 0; i < party.size; i++)
    {
        cout << "\nГерой #" << i + 1 << endl;
        cout << "Ім'я: " << party.heroes[i].name << endl;
        cout << "Клас: " << party.heroes[i].classType << endl;
        cout << "Рівень: " << party.heroes[i].level << endl;
        cout << "HP: " << party.heroes[i].hp << endl;
        cout << "Сила: " << party.heroes[i].stats.strength << endl;
        cout << "Спритність: " << party.heroes[i].stats.agility << endl;
        cout << "Інтелект: " << party.heroes[i].stats.intelligence << endl;
        cout << "Зброя: " << party.heroes[i].weapon.name << endl;
        cout << "Сила зброї: " << party.heroes[i].weapon.power << endl;
    }

    cout << endl;
}

// ================== ЕТАП 2: UPDATE ==================

// 2.1. Підвищити рівень героя
bool levelUp(PartyList& party, const char* searchName)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        cout << "Героя не знайдено!" << endl;
        return false;
    }

    party.heroes[index].level += 1;
    party.heroes[index].hp += 10;

    cout << "Герой " << party.heroes[index].name
        << " підвищив рівень до " << party.heroes[index].level
        << ". HP: " << party.heroes[index].hp << endl;

    return true;
}

// 2.2. Виправити зброю героя
bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        cout << "Героя не знайдено!" << endl;
        return false;
    }

    party.heroes[index].weapon = newWeapon;

    cout << "Герою " << party.heroes[index].name
        << " видано зброю: " << newWeapon.name
        << " (сила " << newWeapon.power << ")" << endl;

    return true;
}

// 2.3. Нанести шкоду
bool damageHero(PartyList& party, const char* searchName, int amount)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        cout << "Героя не знайдено!" << endl;
        return false;
    }

    party.heroes[index].hp -= amount;
    if (party.heroes[index].hp < 0)
    {
        party.heroes[index].hp = 0;
    }

    cout << "Герой " << party.heroes[index].name
        << " отримав шкоду " << amount
        << ". HP: " << party.heroes[index].hp << endl;

    return true;
}

// 2.4. Лікування героя
bool healHero(PartyList& party, const char* searchName, int amount)
{
    int index = findHeroIndex(party, searchName);
    if (index == -1)
    {
        cout << "Героя не знайдено!" << endl;
        return false;
    }

    party.heroes[index].hp += amount;
    if (party.heroes[index].hp > 100)
    {
        party.heroes[index].hp = 100;
    }

    cout << "Герой " << party.heroes[index].name
        << " вилікувався на " << amount
        << ". HP: " << party.heroes[index].hp << endl;

    return true;
}

//  ================== ЕТАП 3: DELETE + аналітика ==================

//  Завдання 3.1. Напишіть функцію
//      bool dismissHero(PartyList& party, const char* searchName);
//  яка видаляє героя з табору за іменем за принципом:
//  -   виділити новий масив на -1,
//  -   скопіювати всіх, окрім видаленого, звільнити старий масив.
//  -   Не забудьте про особливий випадок, коли герой останній у таборі!

bool dismissHero(PartyList& party, const char* searchName)
{
	int index = findHeroIndex(party, searchName);
	if (index == -1)
	{
		cout << "Героя не знайдено!" << endl;
		return false;
	}
	Character* newHeroes = new Character[party.size - 1];
	for (int i = 0, j = 0; i < party.size; i++)
	{
		if (i != index)
		{
			newHeroes[j++] = party.heroes[i];
		}
	}
	delete[] party.heroes;
	party.heroes = newHeroes;
	party.size--;
	cout << "Герой " << searchName << " був звільнений з табору." << endl;
	return true;
}

//  Завдання 3.2. Напишіть функцію
//      int totalPartyPower(const PartyList& party);
//  -   яка обчислює ЗАГАЛЬНУ силу всього табору - суму по всіх героях виразу (level * 10 + weapon.power) для кожного героя.

int totalPartyPower(const PartyList& party)
{
	int totalPower = 0;
	for (int i = 0; i < party.size; i++)
	{
		totalPower += (party.heroes[i].level * 10 + party.heroes[i].weapon.power);
	}
	return totalPower;
}

//  Завдання 3.3. Напишіть функцію
//      int findStrongestHeroIndex(const PartyList& party);
//  -   яка повертає ІНДЕКС героя з найбільшим значенням (stats.strength + stats.agility + stats.intelligence).
//  -   Якщо табір порожній - поверніть -1.
int findStrongestHeroIndex(const PartyList& party)
{
	if (party.size == 0)
	{
		return -1;
	}

	int strongestIndex = 0;
	int maxPower = party.heroes[0].stats.strength + party.heroes[0].stats.agility + party.heroes[0].stats.intelligence;

	for (int i = 1; i < party.size; i++)
	{
		int currentPower = party.heroes[i].stats.strength + party.heroes[i].stats.agility + party.heroes[i].stats.intelligence;
		if (currentPower > maxPower)
		{
			maxPower = currentPower;
			strongestIndex = i;
		}
	}

	return strongestIndex;
}

//  Завдання 3.4. Напишіть функцію
//      void sortByLevelDescending(PartyList& party);
//  -   яка сортує масив героїв за СПАДАННЯМ рівня (level), методом бульбашки

void sortByLevelDescending(PartyList& party)
{
	for (int i = 0; i < party.size - 1; i++)
	{
		for (int j = 0; j < party.size - i - 1; j++)
		{
			if (party.heroes[j].level < party.heroes[j + 1].level)
			{
				Character temp = party.heroes[j];
				party.heroes[j] = party.heroes[j + 1];
				party.heroes[j + 1] = temp;
			}
		}
	}
}