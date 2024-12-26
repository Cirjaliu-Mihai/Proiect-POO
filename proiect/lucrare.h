#ifndef LUCRARE_H
#define LUCRARE_H
#include <vector>
#include <string>
#include "citat.h"
#include "bibliografie.h"
using namespace std;
class Lucrare
{
private:
	string nume_lucrare;
	vector<Citat> citate;
	vector<Bibliografie> bibliografii;
public:
	Lucrare(string nume, vector<Citat> citate, vector<Bibliografie> bibliografii) :nume_lucrare(nume), citate(citate), bibliografii(bibliografii) {};
	void adaugaCitat(Citat c)
	{
		citate.emplace_back(c);
	}
	void adaugaBibliografie(Bibliografie b)
	{
		bibliografii.emplace_back(b);
	}
	Lucrare(string nume) :nume_lucrare(nume) {};
	friend class Platforma;
	bool operator<(Lucrare l)
	{
		return nume_lucrare < l.nume_lucrare;
	}
};

#endif // LUCRARE_H