#include <iostream>
#include <cstring>
#include <windows.h>
#include "types.h"
#include "party.h"
#include "save.h"

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    PartyList party;

    // Завантаження табору з файлу
    readPartyFromFile(party, "party.dat");


    // 2. Пошук героя за ім'ям
    Character foundHero = getHeroByName(party, "Робін");
    cout << "\nЗнайдений герой:" << endl;
    cout << "Ім'я: " << foundHero.name << endl;
    cout << "Клас: " << foundHero.classType << endl;
    cout << "Рівень: " << foundHero.level << endl;
    cout << "HP: " << foundHero.hp << endl;
    cout << "Зброя: " << foundHero.weapon.name << endl;

    // 3. Підвищення рівня
    levelUp(party, "Артур");
    Character upgradedHero = getHeroByName(party, "Артур");
    cout << "\nПісля підвищення рівня:" << endl;
    cout << "Ім'я: " << upgradedHero.name << endl;
    cout << "Рівень: " << upgradedHero.level << endl;
    cout << "HP: " << upgradedHero.hp << endl;

    // 4. Заміна зброї
    Item newWeapon = { "Екскалібур", 50 };
    equipWeapon(party, "Артур", newWeapon);

    Character armedHero = getHeroByName(party, "Артур");
    cout << "\nПісля видачі нової зброї:" << endl;
    cout << "Ім'я: " << armedHero.name << endl;
    cout << "Зброя: " << armedHero.weapon.name << endl;
    cout << "Сила зброї: " << armedHero.weapon.power << endl;

    // 5. Бій: отримання шкоди та лікування
	cout << "\n=== Бій: отримання шкоди та лікування ===" << endl;
    Character merlinBefore = getHeroByName(party, "Мерлін");
    cout << "\nДо бою:" << endl;
    cout << "Ім'я: " << merlinBefore.name << endl;
    cout << "HP: " << merlinBefore.hp << endl;

    damageHero(party, "Мерлін", 30);

    Character merlinAfterDamage = getHeroByName(party, "Мерлін");
    cout << "\nПісля отримання ушкодження:" << endl;
    cout << "Ім'я: " << merlinAfterDamage.name << endl;
    cout << "HP: " << merlinAfterDamage.hp << endl;

    healHero(party, "Мерлін", 20);

    Character merlinAfterHeal = getHeroByName(party, "Мерлін");
    cout << "\nПісля лікування:" << endl;
    cout << "Ім'я: " << merlinAfterHeal.name << endl;
    cout << "HP: " << merlinAfterHeal.hp << endl;

    cout << "\n=== Кінець симуляції ===" << endl;

//  7. Обчисліть і виведіть загальну силу табору (totalPartyPower).

	int totalPower = totalPartyPower(party);
    cout << "\nЗагальна сила табору: " << totalPower << endl;

//  8. Знайдіть і виведіть найсильнішого героя (findStrongestHeroIndex).
    int strongestIndex = findStrongestHeroIndex(party);
    if (strongestIndex != -1)
    {
        Character strongestHero = party.heroes[strongestIndex];
        cout << "\nНайсильніший герой:" << endl;
        cout << "Ім'я: " << strongestHero.name << endl;
        cout << "Сила: " << strongestHero.stats.strength + strongestHero.stats.agility + strongestHero.stats.intelligence << endl;
    }
    else
    {
        cout << "\nТабір порожній." << endl;
    }

//  9. Один герой "гине в бою" - видаліть його з табору (dismissHero).
	if (dismissHero(party, "Мерлін"))
	{
		cout << "\nГерой Мерлін був видалений з табору." << endl;
	}
	else
	{
		cout << "\nГероя Мерлін не знайдено для видалення." << endl;
	}

//  10. Виведіть табір ще раз, щоб побачити результат усіх дій.
    cout << "\nТабір після видалення героя:" << endl;
    printParty(party);


    
    // Збереження табору у файл
    writePartyToFile(party, "party.dat");


    // Звільнення пам'яті
    delete[] party.heroes;
    party.heroes = nullptr;
    party.size = 0;

    return 0;
}