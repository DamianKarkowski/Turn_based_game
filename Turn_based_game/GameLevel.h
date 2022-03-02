#pragma once
#include <iostream>

//! Klasa GameLevel

class GameLevel {
private:
	int easy[6] = { 0,3,6,9,12,14 };							 /*!< Tablica jednowymiarowa typu int  */
	int medium[12] = { 0,1,3,4,6,7,9,10,12,13,14,15 };			 /*!< Tablica jednowymiarowa typu int  */
	int hard[12] = { 1,2,4,5,7,8,10,11,12,13,15,16 };		 /*!< Tablica jednowymiarowa typu int  */

	std::string name;											 /*!< Wartosc pola name typu string */

	int gameLevel;									     /*!< Wartosc pola gameLevel typu integer */
	int numberOfPokemons;											 /*!< Wartosc pola numberOfPokemons typu integer */

public:
	//! Konstruktor klasy GameLevel
	/*!
	 Przyjmuje wartosci string name, int gameLevel, int numberOfPokemons
	*/
	GameLevel(std::string name, int gameLevel, int numberOfPokemons);
	//! Konstruktor domyslny klasy GameLevel
	/*!
	 Tworzy obiekt klasy GameLevel Easy
	*/
	GameLevel();
	//! Metoda setName klasy GameLevel
	/*!
		Przyjmuje wartosc string name
		Zmiena wartosc pola name
	*/
	void setName(std::string name);
	//! Metoda getName klasy GameLevel
	/*!
	  Zwraca wartosc pola name typu string
	*/
	std::string getName() const;
	//! Metoda getGameLevel klasy GameLevel
	/*!
	  Zwraca wartosc pola gameLevel typu integer
	*/
	int getGameLevel() const;
	//! Metoda getNumberOfPokemons klasy GameLevel
	/*!
	  Zwraca wartosc pola numberOfPokemons typu integer
	*/
	int getNumberOfPokemons() const;
	//! Metoda getIdpokemon klasy GameLevel
	/*!
	  Zwraca wartosc typu integer z wylosowanego elementu tablicy
	*/
	int getIdpokemon() const;

};