#include "BlackWitch.h"

BlackWitch::BlackWitch() {
	std::cout << "A black witch called " + GameCharacter::GetCharacterName() + " was created" << std::endl;
}

BlackWitch::BlackWitch(std::string name, float health, float weightLimit, Weapon weapon, Armour armour, int food, CharacterState state, int magic, int power)
	:GameCharacter(name, health, weightLimit, weapon, armour, food, state), magicProficiency_{ magic }, darkPower_{ power }{
	std::cout << "A black witch called " + GameCharacter::GetCharacterName() + " was created" << std::endl;
}

void BlackWitch::SetMagicProficiency(int magic) {
	magicProficiency_ = magic;
}

int BlackWitch::GetMagicProficiency() const {
	return magicProficiency_;
}

void BlackWitch::SetDarkPower(int power) {
	darkPower_ = power;
}

int BlackWitch::GetDarkPower() const {
	return darkPower_;
}

bool BlackWitch::Attack(GameCharacter& character) {
	GameCharacter::Attack(character);
	return true;
}

void BlackWitch::Bewitch(GameCharacter& character) {
	std::cout << "Black witch " + GameCharacter::GetCharacterName() + " is attempting to bewitch " + character.GetCharacterName();
}

void BlackWitch::Sleep() {
	GameCharacter::Sleep();
}
