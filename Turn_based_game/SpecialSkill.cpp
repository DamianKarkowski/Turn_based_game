#include "SpecialSkill.h"

SpecialSkill::SpecialSkill(std::string name, int attack) {

	this->name = name;
	this->attack = attack;
};
SpecialSkill::SpecialSkill() {
	this->name = "brak";
	this->attack = 0;
};
int SpecialSkill::getAttack() const {
	return attack;
};
std::string SpecialSkill::getName() const {
	return name;
}