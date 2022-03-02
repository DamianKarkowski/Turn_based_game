#include "GameLevel.h"

GameLevel::GameLevel(std::string name, int gameLevel, int numberOfPokemons) {
	this->name = name;
	this->gameLevel = gameLevel;
	this->numberOfPokemons = numberOfPokemons;
};

GameLevel::GameLevel() {
	this->name = "Easy";
	gameLevel = 1;
	numberOfPokemons = 4;
};

void GameLevel::setName(std::string name) {
	this->name = name;
};
std::string GameLevel::getName() const {
	return name;
};
int GameLevel::getGameLevel() const {
	return gameLevel;
};

int GameLevel::getNumberOfPokemons() const {
	return numberOfPokemons;
};
int GameLevel::getIdpokemon() const {

	switch (getGameLevel()) {
	case(1):
		return easy[rand() % 6];
	case(2):
		return medium[rand() % 12];
	case(3):
		return hard[rand() % 12];
	default:
		return rand() % 17;
	}
}