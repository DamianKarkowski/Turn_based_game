#include "Pokemon.h"

Pokemon::Pokemon(int id, std::string name, double strength, int agility, double healthPoints, SpecialSkill skill, double experiencePoints, std::string element, int nextEvolution) {
    this->id = id;
    this->name = name;
    this->strength = strength;
    this->agility = agility;
    this->healthPoints = healthPoints;
    this->skill = skill;
    this->experiencePoints = experiencePoints;
    this->element = element;
    this->savedHealthPoints = healthPoints;
    this->nextEvolution = nextEvolution;

};
Pokemon::Pokemon() {
    this->id = 99;
    this->name = "brak";
    this->strength = 0;
    this->agility = 0;
    this->healthPoints = 0;
    this->skill = SpecialSkill();
    this->experiencePoints = 0;
    this->element = "Woda";
};
void Pokemon::setName(std::string name) {
    this->name = name;
};

void Pokemon::setStrength(double strength) {
    this->strength = strength;
};

void Pokemon::setAgility(double agility) {
    this->agility = agility;
};

void Pokemon::setHealthPoints(double healthPoints) {
    this->healthPoints = healthPoints;
};

void Pokemon::setExperiencePoints(double experiencePoints) {
    this->experiencePoints = experiencePoints;
};
void Pokemon::setNumberOfSkills(int ilosc) {
    this->numberOfSkills = ilosc;
};
void Pokemon::setSavedHealthPoints(double savedHealthPoints) {
    this->savedHealthPoints = savedHealthPoints;
};

void Pokemon::regenerate() {
    setHealthPoints(getSavedHealthPoints());
    setNumberOfSkills(2);
};
double Pokemon::getStrength() const {
    return strength;
};
int Pokemon::getAgility() const {
    return agility;
};
double Pokemon::getHealthPoints() const {
    return healthPoints;
};
double Pokemon::getExperiencePoints() const {
    return experiencePoints;
};
std::string Pokemon::getName() const {
    return name;
};


int Pokemon::getId() const {
    return id;
};
int Pokemon::getNumberOfSkills() const {
    return numberOfSkills;
}
SpecialSkill Pokemon::getSkill() const {
    return skill;
};
std::string Pokemon::getElement() const {
    return element;
};
double Pokemon::getSavedHealthPoints() const {
    return savedHealthPoints;
};
void Pokemon::increasingStatistics(int i) {
    switch (id) {
    case(0):
        setStrength(getStrength() + 5);
        break;
    case(1):
        setSavedHealthPoints(getSavedHealthPoints() + 5);
        break;
    case(2):
        setAgility(getAgility() + 1);
        break;
    }

};
bool Pokemon::dodge() {

    if (rand() % 100 <= agility) {
        return true;
    }
    else return false;

};
void Pokemon::normalAttack(Pokemon& pokemon, Element elements) {
    if (!pokemon.dodge()) pokemon.setHealthPoints(pokemon.getHealthPoints() - strength * elements.elementalEffect(element, pokemon.getElement()));
};
void Pokemon::specialAttack(Pokemon& pokemon, Element elements) {
    if (numberOfSkills > 0) {
        this->numberOfSkills -= 1;
        if (!pokemon.dodge()) pokemon.setHealthPoints(pokemon.getHealthPoints() - ((strength + skill.getAttack()) * elements.elementalEffect(element, pokemon.getElement())));
    }
    else {
        normalAttack(pokemon, elements);
    }
}
int Pokemon::getNextEvolution() const {
    return nextEvolution;
};