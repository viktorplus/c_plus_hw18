#pragma once

// ================== ЕТАП 1: CREATE + READ ПРОТОТИПИ ==================

void recruitHero(PartyList& party, Character newHero);
int findHeroIndex(const PartyList& party, const char* searchName);
Character getHeroByName(const PartyList& party, const char* searchName);
void printParty(const PartyList& party);

// ================== ЕТАП 2: UPDATE ПРОТОТИПИ ==================

bool levelUp(PartyList& party, const char* searchName);
bool equipWeapon(PartyList& party, const char* searchName, Item newWeapon);
bool damageHero(PartyList& party, const char* searchName, int amount);
bool healHero(PartyList& party, const char* searchName, int amount);

// ================== ЕТАП 3: DELETE + АНАЛІТИКА ПРОТОТИПИ ==================

bool dismissHero(PartyList& party, const char* searchName);
int totalPartyPower(const PartyList& party);
int findStrongestHeroIndex(const PartyList& party);
void sortByLevelDescending(PartyList& party);
