#include "Brawler.h"

Brawler::Brawler() {
	std::cout << "A brawler called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

Brawler::Brawler(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int punchDamage, int strength)
	:GameCharacter(name, health, weightLimit, weapon, armour, food, state), punchDamage_{ punchDamage }, strength_{ strength }{
	std::cout << "A brawler called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

void Brawler::SetPunchDamage(int damage) {
	punchDamage_ = damage;
}

int Brawler::GetPunchDamage() const {
	return punchDamage_;
}

void Brawler::SetStrength(int strength) {
	strength_ = strength;
}

int Brawler::GetStrength() const {
	return strength_;
}

bool Brawler::Attack(GameCharacter& character) {
	GameCharacter::Attack(character);
	return true;
}

bool Brawler::Brawl(GameCharacter& character) {
	std::cout << "Brawler " + GameCharacter::GetCharacterName() + " is brawling " + character.GetCharacterName();
	return true;
}

void Brawler::Sleep() {
	GameCharacter::Sleep();
}
