#include "Orc.h"

Orc::Orc() {
	std::cout << "An orc called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

Orc::Orc(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int ferocious, int strength) :
	GameCharacter(name, health, weightLimit, weapon, armour, food, state), ferociousness_{ ferocious }, strength_{ strength }{
	std::cout << "An orc called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

void Orc::SetFerociousness(int ferocious) {
	ferociousness_ = ferocious;
}

int Orc::GetFerociousness() const {
	return ferociousness_;
}

void Orc::SetStrength(int strength) {
	strength_ = strength;
}

int Orc::GetStrength() const {
	return strength_;
}

bool Orc::Attack(GameCharacter& character) {
	GameCharacter::Attack(character);
	return true;
}

void Orc::Scream(GameCharacter& character) {
	std::cout << "Orc " + GameCharacter::GetCharacterName() + " is screaming at " + character.GetCharacterName();
}

void Orc::Sleep() {
	GameCharacter::Sleep();
}
