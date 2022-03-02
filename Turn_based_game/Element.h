#pragma once
#include <vector>
#include <string>

//! Klasa Element

class Element {
private:

    const double elements[6][6] =
    {
        {0.75,1.25,1,1.25,1,1},
        {1,1,0.75,1,1,1},
        {1,0.75,1,1,1.25,0.75},
        {0.75,0.75,1,1,1.25,1.25},
        {0.75,1.25,1,0.75,0.75,1},
        {1.25,1,1.25,0.75,1,0.75}
    };                                                                                  /*!< Tablica dwuwymiarowa typu double  */
    const std::string names[6] = { "Woda","Ziemia","Powietrze","Ogien","Lod","Stal" };  /*!< Tablica jednowymiarowa typu string  */

public:
    //! Konstruktor domyslny klasy element
    /*!
     Tworzy obiekt klasy Element
    */
    Element();
    //! Metoda elemntalEffect klasy element
    /*!
      Metoda wybiera jak element oddzialowuje na drugi element
      Zwraca pole typu double
    */
    double elementalEffect(std::string atakujacyZywiol, std::string broniacyZywiol) const;
    //! Metoda idElement klasy element
  /*!
    Zwraca pole typu integer
  */
    int idElement(std::string nazwaZywiolu) const;
};

