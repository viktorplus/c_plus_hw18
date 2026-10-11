#pragma once

struct Stats
{
    int strength;       // сила
    int agility;        // спритність
    int intelligence;   // інтелект
};

struct Item
{
    char name[50];      // назва зброї
    int power;          // сила зброї
};

struct Character
{
    char name[100];     // ім'я героя
    char classType[50]; // клас героя ("Воїн", "Маг", "Лучник" тощо)
    int level;          // рівень героя
    int hp;             // здоров'я
    Stats stats;        // вкладена структура - характеристики
    Item weapon;        // вкладена структура - поточна зброя
};

// Обгортка: динамічний масив героїв табору + його поточний розмір РАЗОМ
struct PartyList
{
    Character* heroes = nullptr;     // покажчик на динамічний масив героїв
    int size = 0;                    // скільки героїв реально зараз у таборі
};