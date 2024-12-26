#ifndef PLATFORMA_H
#define PLATFORMA_H
#include "lucrare.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
class Platforma
{
private:
	vector<Citat> citate;
	vector<Bibliografie> bibliografii;
	vector<Lucrare> lucrari;
public:
	void adaugaLucrare(Lucrare l);
	void initializarePlatforma(string numeFisier);
	void salvarePlatforma(string numeFisier);
	void sortareAlfabeticaNume();
	void sortareAlfabeticaAutor();
	void raportCitate(Citat c);
	void raportBibliografii(Bibliografie b);
	bool citesteLucrareFisier(string numeFisier);
	void sortareLucrari();
	void afisareCitateSiBibliografii();
	void afisareLucrari();
	bool cautareLucrare(string numeLucrare);
	void afisareLucrare(string numeLucrare);
};


#endif
