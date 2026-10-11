#include <iostream>
#include <cstring>
#include "types.h"
#include "party.h"
#include "save.h"

using namespace std;

void writePartyToFile(const PartyList& party, const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "wb");
	if (file == nullptr)
	{
		cout << "Не вдалося відкрити файл для запису!" << endl;
		return;
	}
	fwrite(&party.size, sizeof(int), 1, file); // записуємо розмір табору
	fwrite(party.heroes, sizeof(Character), party.size, file); // записуємо масив героїв
	fclose(file);
	cout << "Табір успішно збережено у файл: " << filename << endl;
}

void readPartyFromFile(PartyList& party, const char* filename)
{
	FILE* file = nullptr;
	fopen_s(&file, filename, "rb");
	if (file== nullptr)
	{
		cout << "Не вдалося відкрити файл для читання! Можливо це перший запуск програми." << endl;
        // 1. Набір героїв до табору
        Character hero1 = {
            "Артур",
            "Воїн",
            5,
            100,
            {10, 5, 3},
            {"Меч", 20}
        };

        Character hero2 = {
            "Мерлін",
            "Маг",
            7,
            80,
            {3, 6, 15},
            {"Посох", 30}
        };

        Character hero3 = {
            "Робін",
            "Лукник",
            4,
            90,
            {6, 14, 5},
            {"Лук", 18}
        };

        recruitHero(party, hero1);
        recruitHero(party, hero2);
        recruitHero(party, hero3);
        return;
	}

	fread(&party.size, sizeof(int), 1, file); // читаємо розмір табору
	party.heroes = new Character[party.size]; // виділяємо пам'ять під масив героїв
	fread(party.heroes, sizeof(Character), party.size, file); // читаємо масив героїв
	fclose(file);
	cout << "Табір успішно завантажено з файлу: " << filename << endl;
}