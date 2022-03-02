#include <iostream>
#include <vector> 
#include "Functions.h"



int main()
{
    srand(time(NULL));

    bool gameover = false;                                      /*!< Zmienna gameover typu logicznego zawiera informacje o przegranej grze  */
    bool fightsWon[4] = { false,false,false,false };     /*!< Tablica jednowymiarowa typu logiczne zawiera informacje o wygranych pojedynkach  */
    std::string charr;                                           /*!< Zmienna charr typu string  */

    int loadSelection = NULL;                                  /*!< Zmienna loadSelection typu int  */

    Element elements = Element();                                  /*!< Zmienna elements typu Element  */
    std::string namePokememons[17] = { "Squitrle","Wartortle","Bastoise","Chikorita","Bayleef","Meganium","Charmander","Charmeleon","Charizard","Rookidee","Corvisquire","Corviknight","Anolan Vulpix","Anolan Ninetales","Aron","Lairon","Aggron" };
    GameLevel gameLevelSelection;                            /*!< Zmienna gameLevelSelection typu GameLevel  */
    std::vector<SpecialSkill> vSpecialSkills = specialSkills();  /*!< vector<SpecialSkill> vSpecialSkills */
    std::vector<Pokemon> playerPokomons;                        /*!< vector<Pokemon> playerPokomons vector z pokemonami gracza*/
    std::vector<std::vector<Pokemon>> opponents;              /*!< vector<vector<Pokemon>> opponents vector z vectorami pokemonow przeciwnika*/


    std::cout << "Wybierz opcje: \n1.Nowa gra \n2.Wczytaj gre\nWpisz liczbe: ";
    std::cin >> charr;
    loadSelection = checkInt(charr, 1, 2);

    system("cls");

    switch (loadSelection) {
    case 1:
    nowaGra:
        std::cout << "wybierz poziom: 1.Latwy 2.Sredni 3.Trudny\nWpisz liczbe: ";
        std::cin >> charr;
        gameLevelSelection = gameLevel(checkInt(charr, 1, 3));
        system("cls");
        std::cout << "Dostepne pokemony:";
        for (int i = 0; i < 17; i++) std::cout << i << "." << namePokememons[i] << " ";
        std::cout << '\n';
        for (int i = 0; i < 6; i++) {
            std::cout << "Wybierz pokemona:";
            std::cin >> charr;
            while (!checkSelection(playerPokomons, checkInt(charr, 0, 16))) {
                std::cout << "Posiadasz tego pokemona wybierz innego: ";
                std::cin >> charr;
            }
            playerPokomons.push_back(createPokemon(checkInt(charr, 0, 16), vSpecialSkills));
        }
        system("cls");
        std::cout << '\n';
        for (int i = 0; i < 6; i++) {
            std::cout << playerPokomons[i].getName() << " ";
        }
        std::cout << '\n';
        break;
    case 2:
        int wczytanaWartosc;
        std::ifstream plik("zapis.txt");
        if (plik.good()) {
            plik >> wczytanaWartosc;
            gameLevelSelection = gameLevel(wczytanaWartosc);
            plik >> wczytanaWartosc;
            gameover = wczytanaWartosc;
            for (int i = 0; i < 4; i++) {
                plik >> wczytanaWartosc;
                std::cout << wczytanaWartosc;
                fightsWon[i] = wczytanaWartosc;
            }
            for (int i = 0; i < 6; i++) {

                plik >> wczytanaWartosc;
                playerPokomons.push_back(createPokemon(wczytanaWartosc, vSpecialSkills));
                plik >> wczytanaWartosc;
                playerPokomons[i].setHealthPoints(wczytanaWartosc);
                plik >> wczytanaWartosc;
                playerPokomons[i].setSavedHealthPoints(wczytanaWartosc);
                playerPokomons[i].setHealthPoints(wczytanaWartosc);
                plik >> wczytanaWartosc;
                playerPokomons[i].setStrength(wczytanaWartosc);
                plik >> wczytanaWartosc;
                playerPokomons[i].setAgility(wczytanaWartosc);
            }
        }
        else {
            std::cout << "Blad podczas wczytania gry\nTworzenie nowej gry\n";
            goto nowaGra;
        }
        plik.close();
        break;
    }

    for (int i = 0; i < 4; i++) {
        opponents.push_back(pokemonDraw(gameLevelSelection, vSpecialSkills));
    };

    system("cls");

    for (int i = 0; i < 4; i++) {
        if (!fightsWon[i] && !gameover) {
            std::cout << "Pojedynek nr : " << i + 1 << '\n';
            fightsWon[i] = fight(playerPokomons, opponents[i], elements, vSpecialSkills);
            if (fightsWon[i] == false) gameover = true;
            else {
                system("cls");
                std::cout << "Wygrales pojedynek nr: " << i + 1 << '\n';

                std::cout << "Czy chcesz zapisac gre i wyjsc z gry?\n1.TAK\n2.NIE\nWpisz liczbe: ";
                std::cin >> charr;
                loadSelection = checkInt(charr, 1, 2);
                if (loadSelection == 1) save(gameover, fightsWon, playerPokomons, gameLevelSelection.getGameLevel());
            }

        }
        pokemonRegeneration(playerPokomons);
        system("cls");
    }

    if (gameover) {
        std::cout << "Przegrales\nCzy chcesz zaczac nowa gre?\n1.Tak\n2.Nie\nWpisz liczbe: ";
        std::cin >> charr;
        loadSelection = checkInt(charr, 1, 2);
        if (loadSelection == 1) goto nowaGra;

    }
    else std::cout << "Wygrales\n";

}
