#pragma once
#include <string>

//! Klasa SpecialSkill

class SpecialSkill {

private:
	std::string name;  /*!< Wartosc pola name typu string */
	int attack;  /*!< Wartosc pola attack typu integer */

public:
	//! Konstruktor klasy SpecialSkill
	/*!
	 Przyjmuje wartosci string name oraz int attack
	*/
	SpecialSkill(std::string name, int attack);
	//! Konstruktor domyslny klasy SpecialSkill
	/*!
		Ustawia wartosci takie aby nie mialy wplywu na rozgrywke, jesli bylby blad w czasie rozgrywki
	*/
	SpecialSkill();
	//! Metoda getNazwa klasy SpecialSkill
	/*!
	  Zwraca pole nazwa typu string
	*/
	std::string getName() const;
	//! Metoda getAtak klasy SpecialSkill
	/*!
	  Zwraca pole attack typu integer
	*/
	int getAttack() const;
};
