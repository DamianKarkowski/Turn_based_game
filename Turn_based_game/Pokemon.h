#pragma once
#include "SpecialSkill.h"
#include "Element.h"
#include <ctime>
#include <iostream>

//! Klasa Pokemon

class Pokemon {
private:
    int id;                             /*!< Wartosc pola id typu integer */
    std::string name;                  /*!< Wartosc pola name typu string */
    double strength;                        /*!< Wartosc pola strength typu double */
    int agility;                      /*!< Wartosc pola agility typu integer */
    double healthPoints;                 /*!< Wartosc pola healthPoints typu double */
    SpecialSkill skill;                   /*!< Wartosc pola skill typu SpecialSkill */
    double experiencePoints;                   /*!< Wartosc pola experiencePoints typu double */
    std::string element;                 /*!< Wartosc pola element typu string */

    int savedHealthPoints;                 /*!< Wartosc pola savedHealthPoints typu integer */
    int numberOfSkills = 2;        /*!< Wartosc pola numberOfSkills typu integer */
    int nextEvolution;               /*!< Wartosc pola nextEvolution typu integer */

public:
    //! Konstruktor klasy Pokemon
    /*!
     Przyjmuje wartosci integer id, string name, double strength, int agility, double healthPoints, SpecialSkill skill, double experiencePoints, string element, integer nextEvolution
    */
    Pokemon(int id, std::string name, double strength, int agility, double healthPoints, SpecialSkill skill, double experiencePoints, std::string element, int nextEvolution);
    //! Konstruktor domyslny klasy Pokemon
    /*!
        Ustawia wartosci takie aby nie mialy wplywu na rozgrywke, jesli bylby blad w czasie rozgrywki
    */
    Pokemon();
    //! Metoda setName klasy Pokemon
    /*!
        Przyjmuje wartosc string name
        Zmiena wartosc pola name
    */
    void setName(std::string name);
    //! Metoda setStrength klasy Pokemon
    /*!
        Przyjmuje wartosc double strength
        Zmiena wartosc pola strength
    */
    void setStrength(double strength);
    //! Metoda setAgility klasy Pokemon
   /*!
     Przyjmuje wartosc double agility
     Zmiena wartosc pola agility
   */
    void setAgility(double agility);
    //! Metoda setHealthPoints klasy Pokemon
    /*!
      Przyjmuje wartosc double healthPoints
      Zmiena wartosc pola healthPoints
    */
    void setHealthPoints(double healthPoints);
    //! Metoda setExperiencePoints klasy Pokemon
    /*!
      Przyjmuje wartosc double experiencePoints
      Zmiena wartosc pola experiencePoints
     */
    void setExperiencePoints(double experiencePoints);
    //! Metoda setNumberOfSkills klasy Pokemon
     /*!
       Przyjmuje wartosc int number
       Zmiena wartosc pola number
     */
    void setNumberOfSkills(int number);
    //! Metoda regenerate klasy Pokemon
     /*!
        Zmiena wartosci pol numberOfSkills, healthPoints
     */
    void regenerate();
    //! Metoda setSavedHealthPoints klasy Pokemon
    /*!
       Przyjmuje wartosc double savedHealthPoints
       Zmiena wartosc pola savedHealthPoints
    */
    void setSavedHealthPoints(double savedHealthPoints);
    //! Metoda increasingStatistics klasy Pokemon
    /*!
      Przyjmuje wartosc integer i
      Zmiena wartosc wybranego pola (savedHealthPoints, strength, agility)
    */
    void increasingStatistics(int i);
    //! Metoda normalAttack klasy Pokemon
    /*!
      Przyjmuje wartosc Pokemon pokemon oraz Element elements
      Zmiena wartosc pola healthPoints pokemona, ktory jest atakowany
    */
    void normalAttack(Pokemon& pokemon, Element elements);
    //! Metoda specialAttack klasy Pokemon
    /*!
      Przyjmuje wartosc Pokemon pokemon oraz Element elements
      Zmiena wartosc pola healthPoints pokemona, ktory jest atakowany
    */
    void specialAttack(Pokemon& pokemon, Element elements);
    //! Metoda getName klasy Pokemon
    /*!
      Zwraca wartosc pola nazwa typu string
    */
    std::string getName() const;
    //! Metoda getStrength klasy Pokemon
    /*!
      Zwraca wartosc pola sila typu double
    */
    double getStrength() const;
    //! Metoda getAgility klasy Pokemon
    /*!
      Zwraca wartosc pola zrecznosc typu int
    */
    int getAgility() const;
    //! Metoda getHealthPoints klasy Pokemon
    /*!
      Zwraca wartosc pola healthPoints typu double
    */
    double getHealthPoints() const;
    //! Metoda getExperiencePoints klasy Pokemon
    /*!
      Zwraca wartosc pola experiencePoints typu double
    */
    double getExperiencePoints() const;
    //! Metoda getId klasy Pokemon
    /*!
      Zwraca wartosc pola id typu int
    */
    int getId() const;
    //! Metoda getNumberOfSkills klasy Pokemon
    /*!
      Zwraca wartosc pola numberOfSkills typu int
    */
    int getNumberOfSkills() const;
    //! Metoda getNextEvolution klasy Pokemon
    /*!
      Zwraca wartosc pola nextEvolution typu int
    */
    int getNextEvolution() const;
    //! Metoda getSkill klasy Pokemon
    /*!
      Zwraca wartosc pola skill typu SpecialSkill
    */
    SpecialSkill getSkill() const;
    //! Metoda getElement klasy Pokemon
    /*!
      Zwraca wartosc pola element typu string
    */
    std::string getElement() const;
    //! Metoda getSavedHealthPoints klasy Pokemon
    /*!
      Zwraca wartosc pola savedHealthPoints typu double
    */
    double getSavedHealthPoints() const;
    //! Metoda dodge klasy Pokemon
    /*!
      Zwraca wartosc true lub false w zaleznosci czy pokemon wykona unik
    */
    bool  dodge();

};

