#include "GameCharacter.h"
#include <string>

GameCharacter::GameCharacter() {
	std::cout << "A game character called " + characterName_ + " has been born" << std::endl;
}

GameCharacter::GameCharacter(std::string name, float health, float weight, Weapon weapon, Armour armour, int food, CharacterState state) 
	: characterName_{ name }, health_{ health }, weightLimit_{ weight }, weapon_{ weapon }, armour_{ armour }, food_{ food }, state_{ state } {
	std::cout << "A game character called " + characterName_ + " has been born" << std::endl;
}

void GameCharacter::SetCharacterName(std::string name) {
	characterName_ = name;
}

std::string GameCharacter::GetCharacterName() const {
	return characterName_;
}

void GameCharacter::SetCharacterHealth(float health) {
	health_ = health;
}

float GameCharacter::GetCharacterHealth() const {
	return health_;
}

void GameCharacter::SetCharacterWeightLimit(float weightLimit) {
	weightLimit_ = weightLimit;
}

float GameCharacter::GetCharacterWeightLimit() const {
	return weightLimit_;
}

void GameCharacter::SetCharacterWeapon(Weapon weapon) {
	weapon_ = weapon;
}

Weapon GameCharacter::GetCharacterWeapon() const {
	return weapon_;
}

void GameCharacter::SetCharacterArmour(Armour armour) {
	armour_ = armour;
}

Armour GameCharacter::GetCharacterArmour() const {
	return armour_;
}

void GameCharacter::SetCharacterFood(int food) {
	food_ = food;
}

int GameCharacter::GetCharacterFood() const {
	return food_;
}

void GameCharacter::SetCharacterState(CharacterState state) {
	state_ = state;
}

CharacterState GameCharacter::GetCharacterState() const {
	return state_;
}

void GameCharacter::AddFood(int amount) {
	food_ += amount;
}

void GameCharacter::Eat() {
	if (food_ > 0) {
		while (health_ < 1 && food_ > 0) {
			food_--;
			health_ += 0.25;
		}
	}
}

bool GameCharacter::Attack(GameCharacter& character) {
	std::cout << characterName_ + " is attacking " + character.GetCharacterName() + " with " + weapon_.GetItemName() << std::endl;
	if (&weapon_ == NULL) {
		return false;
	} else if (health_ <= 20) {
		return false;
	} else if (character.isDead()) {
		return false;
	} else {
		state_ = CharacterState::Attacking;
		return true;
	}
}

void GameCharacter::Defend() {
	std::string aType{ "" };
	switch (armour_.GetArmourType()) {
	case ArmourType::Cardboard: 
		aType = "Cardboard";
		break;
	case ArmourType::Leather: 
		aType = "Leather";
		break;
	case ArmourType::Wood: 
		aType = "Wood";
		break;
	case ArmourType::Iron: 
		aType = "Iron";
		break;
	case ArmourType::Steel: 
		aType = "Steel";
		break;
	}
	std::cout << characterName_ + " is defending themselves with a " + armour_.GetItemName() + " made from " + aType;
}

void GameCharacter::Walk() {
	std::cout << characterName_ + " is walking" << std::endl;
	state_ = CharacterState::Walking;
}

void GameCharacter::Run() {
	std::cout << characterName_ + " is running" << std::endl;
	state_ = CharacterState::Running;
}

void GameCharacter::Sleep() {
	std::cout << characterName_ + " is sleeping" << std::endl;
	state_ = CharacterState::Sleeping;
}

bool GameCharacter::isDead() {
	if (health_ == 0) {
		return true;
	} else {
		return false;
	}
}

