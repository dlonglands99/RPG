#include "Cleric.h"

Cleric::Cleric() {
	std::cout << "A cleric called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

Cleric::Cleric(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int level)
	: GameCharacter(name, health, weightLimit, weapon, armour, food, state), pietyLevel_{ level }{
	std::cout << "A cleric called " + GameCharacter::GetCharacterName() + " has been created" << std::endl;
}

void Cleric::SetPietyLevel(int level) {
	pietyLevel_ = level;
}

int Cleric::GetPietyLevel() const {
	return pietyLevel_;
}

bool Cleric::Attack(GameCharacter& character) {
	GameCharacter::Attack(character);
	return true;
}

void Cleric::PrayFor(GameCharacter& character) {
	std::cout << "Cleric " + GameCharacter::GetCharacterName() + " is praying for " + character.GetCharacterName();
}

void Cleric::Sleep() {
	GameCharacter::Sleep();
}