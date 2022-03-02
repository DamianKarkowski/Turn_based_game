#include "Functions.h"
#include <iostream>



GameLevel gameLevel(int id) {
	switch (id) {
	case(1):
		return GameLevel("Easy", 1, 4);
	case(2):
		return GameLevel("Medium", 2, 5);
	case(3):
		return GameLevel("Hard", 3, 6);
	default:
		return GameLevel("Easy", 1, 4);
	}
};

std::vector<SpecialSkill> specialSkills() {

	std::vector<SpecialSkill> vSpecialSkills;
	vSpecialSkills.push_back(SpecialSkill("Atak wodny", 30));
	vSpecialSkills.push_back(SpecialSkill("Atak pn¹czami", 35));
	vSpecialSkills.push_back(SpecialSkill("Atak ogniem", 40));
	vSpecialSkills.push_back(SpecialSkill("Atak powietrzny", 25));
	vSpecialSkills.push_back(SpecialSkill("Atak œnie¿ny", 30));
	vSpecialSkills.push_back(SpecialSkill("Atak stali", 20));


	return vSpecialSkills;
};


Pokemon	createPokemon(int id, std::vector<SpecialSkill> vSpecialSkills) {
	switch (id) {
	case 0:
		return Pokemon(0, "Squitrle", 24, 1, 44, vSpecialSkills[0], 0, "Woda", 1);
	case 1:
		return Pokemon(1, "Wartortle", 31, 2, 59, vSpecialSkills[0], 0, "Woda", 2);
	case 2:
		return Pokemon(2, "Bastoise", 41, 3, 79, vSpecialSkills[0], 0, "Woda", 99);
	case 3:
		return Pokemon(3, "Chikorita", 24, 1, 45, vSpecialSkills[1], 0, "Ziemia", 4);
	case 4:
		return Pokemon(4, "Bayleef", 31, 2, 60, vSpecialSkills[1], 0, "Ziemia", 5);
	case 5:
		return Pokemon(5, "Meganium", 41, 3, 80, vSpecialSkills[1], 0, "Ziemia", 99);
	case 6:
		return Pokemon(6, "Charmander", 26, 1, 39, vSpecialSkills[2], 0, "Ogien", 7);
	case 7:
		return Pokemon(7, "Charmeleon", 32, 2, 58, vSpecialSkills[2], 0, "Ogien", 8);
	case 8:
		return Pokemon(8, "Charizard", 42, 3, 78, vSpecialSkills[2], 0, "Ogien", 99);
	case 9:
		return Pokemon(9, "Rookidee", 23, 1, 38, vSpecialSkills[3], 0, "Powietrze", 10);
	case 10:
		return Pokemon(10, "Corvisquire", 34, 2, 68, vSpecialSkills[3], 0, "Powietrze", 11);
	case 11:
		return Pokemon(11, "Corviknight", 43, 3, 98, vSpecialSkills[3], 0, "Powietrze", 99);
	case 12:
		return Pokemon(12, "Anolan Vulpix", 21, 1, 38, vSpecialSkills[4], 0, "Lod", 13);
	case 13:
		return Pokemon(13, "Anolan Ninetales", 38, 2, 73, vSpecialSkills[4], 0, "Lod", 99);
	case 14:
		return Pokemon(14, "Aron", 32, 2, 50, vSpecialSkills[5], 0, "Stal", 15);
	case 15:
		return Pokemon(15, "Lairon", 45, 3, 60, vSpecialSkills[5], 0, "Stal", 16);
	case 16:
		return Pokemon(16, "Aggron", 55, 4, 70, vSpecialSkills[5], 0, "Stal", 99);
	default: return Pokemon();
	}

};


std::vector<Pokemon> pokemonDraw(GameLevel gameLevel, std::vector<SpecialSkill> vSpecialSkills) {
	std::vector<Pokemon> pokemony;


	for (int i = 0; i < gameLevel.getNumberOfPokemons(); i++) {
		int id = gameLevel.getIdpokemon();
		while (!checkSelection(pokemony, id)) {
			id = gameLevel.getIdpokemon();
		}
		pokemony.push_back(createPokemon(id, vSpecialSkills));
	}

	return pokemony;
};




int pokemonSelection(bool passedOut[6], std::vector<Pokemon> playerPokemons) {
	std::string znak;
	int wybor;
	std::cout << "Pokemony do wyboru : ";
	for (int i = 0; i < 6; i++) {
		if (!passedOut[i]) std::cout << i << "." << playerPokemons[i].getName() << " ";
	}
	std::cout << '\n';
	std::cout << "wybierz pokemona od 0 do 5 : ";
	std::cin >> znak;
	wybor = checkInt(znak, 0, 5);
	while (passedOut[wybor]) {
		std::cout << "Ten pokemon zemdlal wybierz innego pokemona od 0 do 5 : ";
		std::cin >> znak;
		wybor = checkInt(znak, 0, 5);
	}
	return wybor;
};

Pokemon evolvePokemon(Pokemon playerPokemons, std::vector<SpecialSkill> vSpecialSkills) {

	if (playerPokemons.getExperiencePoints() >= 10 && playerPokemons.getNextEvolution() != 99)
		return createPokemon(playerPokemons.getNextEvolution(), vSpecialSkills);

	return playerPokemons;

};

bool fight(std::vector<Pokemon>& playerPokemons, std::vector<Pokemon>& opponentPokemons, Element element, std::vector<SpecialSkill> vSpecialSkills) {
	std::string charr;
	bool passedOut[6] = { false,false,false,false,false,false };
	rsize_t wybranyPokemonPrzeciwnika = 0, wybranyPokemonGracza = pokemonSelection(passedOut, playerPokemons), zemdlaleGracza = 0;
	system("cls");
	while (true) {
		int szanseNaAtakSpecjalnyPrzeciwnika = rand() % 10 + 1, wybranaOpcja;
		std::cout << "Pokemon gracza : " << playerPokemons[wybranyPokemonGracza].getName() << "\nPokemon przeciwnika : " << opponentPokemons[wybranyPokemonPrzeciwnika].getName() << '\n';
		std::cout << "Wybierz:\n0 - Atak\n1 - AtakSpecjalny\n2 - ZmienaPokemona\n3 - Ewolicja \n4 - Powiekszenie statystyk\nPodaj liczbe: ";
		std::cin >> charr;
		wybranaOpcja = checkInt(charr, 0, 5);
		switch (wybranaOpcja) {
		case 0:
			playerPokemons[wybranyPokemonGracza].normalAttack(opponentPokemons[wybranyPokemonPrzeciwnika], element);
			break;
		case 1:
			playerPokemons[wybranyPokemonGracza].specialAttack(opponentPokemons[wybranyPokemonPrzeciwnika], element);
			break;
		case 2:
			wybranyPokemonGracza = pokemonSelection(passedOut, playerPokemons);
			break;
		case 3:
			playerPokemons[wybranyPokemonGracza] = evolvePokemon(playerPokemons[wybranyPokemonGracza], vSpecialSkills);
			break;
		case 4:
			if (playerPokemons[wybranyPokemonGracza].getExperiencePoints() >= 20) {
				for (int i = 0; i < 2; i++) {
					std::cout << "Jakie atrybuty chcesz powiekszyc?\n0.Sila\n1.Zycie\n2.Zrecznosc\nWpisz liczbe: ";
					std::cin >> charr;
					playerPokemons[wybranyPokemonGracza].increasingStatistics(checkInt(charr, 0, 2));
					system("cls");
				}
				playerPokemons[wybranyPokemonGracza].setExperiencePoints(playerPokemons[wybranyPokemonGracza].getExperiencePoints() - 20);
			}
			break;
		case 5:
			playerPokemons[wybranyPokemonGracza].regenerate();
			break;

		};
		if (opponentPokemons[wybranyPokemonPrzeciwnika].getHealthPoints() <= 0) {
			playerPokemons[wybranyPokemonGracza].setExperiencePoints(playerPokemons[wybranyPokemonGracza].getExperiencePoints() + 12);
			if (wybranyPokemonPrzeciwnika < opponentPokemons.size() - 1) {
				wybranyPokemonPrzeciwnika++;
				std::cout << "Przeciwnik zmienil pokemona na : " << opponentPokemons[wybranyPokemonPrzeciwnika].getName() << '\n';
			}
			else {
				return true;
			}

		}

		if (szanseNaAtakSpecjalnyPrzeciwnika < 8) opponentPokemons[wybranyPokemonPrzeciwnika].normalAttack(playerPokemons[wybranyPokemonGracza], element);
		else opponentPokemons[wybranyPokemonPrzeciwnika].specialAttack(playerPokemons[wybranyPokemonGracza], element);


		show(playerPokemons[wybranyPokemonGracza], opponentPokemons[wybranyPokemonPrzeciwnika]);

		if (playerPokemons[wybranyPokemonGracza].getHealthPoints() <= 0) {
			if (zemdlaleGracza < 5) {
				passedOut[wybranyPokemonGracza] = true;
				wybranyPokemonGracza = pokemonSelection(passedOut, playerPokemons);
				zemdlaleGracza++;
				system("cls");
			}
			else {
				return false;
			}
		}
	}

};

void pokemonRegeneration(std::vector<Pokemon>& pokemons) {
	for (rsize_t i = 0; i < pokemons.size(); i++) pokemons[i].regenerate();
};


void save(bool gameover, bool pokonaniPrzeciwnicy[4], std::vector<Pokemon> playerPokemons, int gameLevel) {
	std::fstream plik;
	plik.open("zapis.txt", std::ios::out | std::ios::trunc);
	if (plik.good() == true) {

		plik << gameLevel << std::endl;
		plik << gameover << std::endl;
		for (int i = 0; i < 4; i++) plik << pokonaniPrzeciwnicy[i] << std::endl;
		for (rsize_t i = 0; i < playerPokemons.size(); i++) {

			plik << playerPokemons[i].getId() << std::endl;
			plik << playerPokemons[i].getExperiencePoints() << std::endl;
			plik << playerPokemons[i].getSavedHealthPoints() << std::endl;
			plik << playerPokemons[i].getStrength() << std::endl;
			plik << playerPokemons[i].getAgility() << std::endl;
		}

		std::cout << "Zapisano plik\n";
	}
	else std::cout << "Blad w zapisie\n";
	plik.close();
	exit(0);
};

int	checkInt(std::string typedData, int lowRange, int highRange) {
	int i;
	std::string znak = typedData;
	while (true) {
		if (std::regex_match(znak, std::regex("([0-9]+)"))) {
			i = std::stoi(znak);
			if (i >= lowRange && i <= highRange) {
				return i;
			}
			else {

				std::cout << "Wpisz poprawna liczbe : ";
				std::cin >> znak;

			}
		}
		else {
			if (std::regex_match(znak, std::regex("-h")) || std::regex_match(znak, std::regex("--help"))) {
				helpShow();
				std::cout << "Wpisz liczbe : ";
				std::cin >> znak;
			}
			else {
				std::cout << "Wpisz poprawna liczbe : ";
				std::cin >> znak;
			}

		}
	}

};

void show(Pokemon playerPokemon, Pokemon opponentPokemon) {
	system("cls");
	std::cout << "Twoja tura\n";
	std::cout << "Przeciwnik: " << opponentPokemon.getName() << '\n';
	std::cout << "Pozostala ilosc zycia: " << opponentPokemon.getHealthPoints() << '\n';
	std::cout << "\n";
	std::cout << "Twoj wybrany pokemon: " << playerPokemon.getName() << '\n';
	std::cout << "Pozostala ilosc zycia: " << playerPokemon.getHealthPoints() << '\n';
	std::cout << "Ilosc EXP pokemona: " << playerPokemon.getExperiencePoints() << '\n';
	std::cout << "Pozostala ilosc uzyc ataku specjalnego: " << playerPokemon.getNumberOfSkills() << '\n';

};

void helpShow() {
	std::cout << "Pomoc:\nAplikacja sterujemy wpisujac odpowiednie liczby\nNa poczatku mozesz czy chcesz wczytac gre lub zaczac nowa gre\nMozesz wybrac 6 stworzen z 17\nPoziomy trudnosci\nLatwy: kazdy z przeciwnikow posiada 4 pokemony\nSredni: kazdy z przeciwnikow posiada 5 pokemonow\nTrudny: kazdy z przeciwnikow poiada 6 pokemonow\nPodczas gry sa 4 rundy po ktorych jesli wygrasz bedziesz mogl zapisac gre, a twoje pokemony zostana zregenerowane\nMusisz pokonac wszystkich przeciwnikow aby wygrac gre\n";
	std::cout << "Kazdy Pokemon posiada atrybuty takie jak sila, zrecznosc, punkty zycia czy moc specjalna\nTwoj pokemon zemdleje jesli nie bedzie mial juz punktow zycia. Bedziesz musial go zamienic\n";
	std::cout << "W ciagu jednego pojedynku kazdy z Twoich pokemonow bedzie mogl dwa razy uzyc mocy specjalnej\nJesli przez przypadek nacisniejsz atak moca specjalna, gdy Twoj pokemon nie posiada juz uzyc nic sie nie dzieje z automotu zostanie wywolany atak specjalny\n";
	std::cout << "Ewolucja pokemona: bedziesz mogl przeprowadzic ewolucje na pokemonie w momencie gdy on bedzie posiadal minimum 50 punktow EXP\nTwoj Pokemon dostanie 12 punktow EXP wzamian za pokonanie pokemonu przeciwnika\n";
};

bool checkSelection(std::vector<Pokemon> pokemons, int id) {
	bool sprawdz = true;
	for (rsize_t i = 0; i < pokemons.size(); i++) {
		if (pokemons[i].getId() == id) {
			sprawdz = false;
		}
	}
	return sprawdz;
};