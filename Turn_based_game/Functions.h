#pragma once
#include <functional>
#include "Element.h"
#include "GameLevel.h"
#include "Pokemon.h"
#include "SpecialSkill.h"
#include <cstdlib>
#include <fstream>
#include <regex>

//! Funckja specialSkills
/*!
	Zwraca vector typu SpecialSkill z utworzonymi obiektami klasy SpecialSkill
*/
std::vector<SpecialSkill> specialSkills();
//! Funckja pokemonDraw
/*!
	Przyjmuje GameLevel gameLevel oraz vector<SpecialSkill> vSpecialSkills
	Zwraca vector typu Pokemon z wylosowanymi pokemona dla przeciwnikow
*/
std::vector<Pokemon> pokemonDraw(GameLevel gameLevel, std::vector<SpecialSkill> vSpecialSkills);
//! Funckja gameLevel
/*!
	Tworzy i zwraca obiekt klasy GameLevel
*/
GameLevel gameLevel(int id);
//! Funckja createPokemon
/*!
	Przyjmuje wartosc id typu integer
	Tworzy i zwraca obiekt klasy Pokemon
*/
Pokemon	createPokemon(int id, std::vector<SpecialSkill> vSpecialSkills);
//! Funckja evolvePokemon
/*!
	Przyjmuje wartosci Pokemon playerPokemons oraz vector<SpecialSkill> SpecialSkill
	Tworzy i zwraca obiekt klasy Pokemon
*/
Pokemon evolvePokemon(Pokemon playerPokemons, std::vector<SpecialSkill> SpecialSkill);
//! Funckja fight
/*!
	Przyjmuje wartosci vector<Pokemon> &playerPokemons, vector<Pokemon>& opponentPokemons, Element element oraz vector<SpecialSkill> vSpecialSkills
	Zwraca wartosci true lub false w zaleznosci od wyniku pojedynku
*/
bool fight(std::vector<Pokemon>& playerPokemons, std::vector<Pokemon>& opponentPokemons, Element element, std::vector<SpecialSkill> vSpecialSkills);
//! Funckja checkSelection
/*!
	Przyjmuje wartosci vector<Pokemon> pokemons oraz integer id
	Zwraca wartosci true lub false w zaleznosci czy dany pokemon jest juz w druzynie
*/
bool checkSelection(std::vector<Pokemon> pokemons, int id);
//! Funckja checkInt
/*!
	Przyjmuje wartosci string typedData, integer lowRange oraz integer highRange
	Zwraca wartosc integer gdy gracz wpisal poprawna dana
*/
int	checkInt(std::string typedData, int lowRange, int highRange);
//! Funckja pokemonSelection
/*!
	Przyjmuje wartosci boll passedOut[6] oraz vector<Pokemon> playerPokemons
	Zwraca wartosc integer, ktora wybral gracz
*/
int pokemonSelection(bool passedOut[6], std::vector<Pokemon> playerPokemons);
//! Funckja pokemonRegeneration
/*!
	Przyjmuje vector<Pokemon> pokemons
	Uzywa metody regeneruj() z klasy Pokemon dla wszystkich pokemonow bedacych w vectorze
*/
void pokemonRegeneration(std::vector<Pokemon>& pokemons);
//! Funckja save
/*!
	Przyjmuje wartosci bool gameover, bool fightsWon[4], vector<Pokemon> playerPokemons, integer gameLevel
	Zapisuje do pliku aktualny stan gry
*/
void save(bool gameover, bool fightsWon[4], std::vector<Pokemon> playerPokemons, int gameLevel);
//! Funckja show
/*!
	Przyjmuje wartosci Pokemon playerPokemon oraz Pokemon opponentPokemon
	Wyswietla informacje o wybranym pokemonie gracza oraz przeciwnika
*/
void show(Pokemon playerPokemon, Pokemon opponentPokemon);
//! Funckja helpShow
/*!
	Wyswietla pomocne informacje
*/
void helpShow();
