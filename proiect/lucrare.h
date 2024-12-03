#ifndef LUCRARE_H
#define LUCRARE_H
#include <vector>
#include <string>
#include "citate.h"
#include "bibliografii.h"
using namespace std;
class Lucrare
{
private:
	string nume_lucrare;
	vector<Citate> citate;
	vector<Bibliografii> bibliografii;
public:
	Lucrare(string nume, vector<Citate> citate, vector<Bibliografii> bibliografii) :nume_lucrare(nume), citate(citate), bibliografii(bibliografii) {};
	void adaugaCitat(Citate c)
	{
		citate.emplace_back(c);
	}
	void adaugaBibliografie(Bibliografii b)
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