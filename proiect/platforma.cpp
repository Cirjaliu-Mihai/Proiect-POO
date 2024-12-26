#include "platforma.h"

void Platforma::adaugaLucrare(Lucrare l)
{
	lucrari.emplace_back(l);
	for (auto& itr : l.citate)
	{
		citate.emplace_back(itr);
	}
	for (auto& itr : l.bibliografii)
	{
		bibliografii.emplace_back(itr);
	}
}
void Platforma::initializarePlatforma(string numeFisier)
{
	ifstream fin(numeFisier);
	int numar_lucrari, numar_citate, numar_bibliografii;
	fin >> numar_lucrari;
	while (numar_lucrari--)
	{
		string nume;
		getline(fin, nume);
		fin >> numar_citate >> numar_bibliografii;
		Lucrare l(nume);
		while (numar_citate--)
		{
			string citat, autor;
			getline(fin, citat);
			getline(fin, autor);
			Citat c(citat, autor);
			l.citate.emplace_back(c);
		}
		while (numar_bibliografii--)
		{
			string continut, autor;
			getline(fin, continut);
			getline(fin, autor);
			Bibliografie b(continut, autor);
			l.bibliografii.emplace_back(b);
		}
		adaugaLucrare(l);
	}
	fin.close();
}
void Platforma::salvarePlatforma(string numeFisier)
{
	ofstream fout(numeFisier);
	fout << lucrari.size() << "\n";
	for (auto& itr : lucrari)
	{
		fout << itr.nume_lucrare << "\n" << itr.citate.size() << " " << itr.bibliografii.size() << "\n";
		for (auto& c : itr.citate)
		{
			fout << c.getCitat() << "\n" << c.getAutor() << "\n";
		}
		for (auto& b : itr.bibliografii)
		{
			fout << b.getBibliografie() << "\n" << b.getAutor() << "\n";
		}

	}
	fout.close();

}
void Platforma::sortareAlfabeticaNume()
{
	sort(citate.begin(), citate.end(), [](Citat c1, Citat c2) {
		return c1.getCitat() < c2.getCitat();
		});
	sort(bibliografii.begin(), bibliografii.end(), [](Bibliografie b1, Bibliografie b2) {
		return b1.getBibliografie() < b2.getBibliografie();
		});

}
void Platforma::sortareAlfabeticaAutor()
{
	sort(citate.begin(), citate.end(), [](Citat c1, Citat c2) {
		return c1.getAutor() < c2.getAutor();
		});
	sort(bibliografii.begin(), bibliografii.end(), [](Bibliografie b1, Bibliografie b2) {
		return b1.getAutor() < b2.getAutor();
		});

}
void Platforma::raportCitate(Citat c)
{
	sortareLucrari();
	for (auto& itr : lucrari)
	{

		for (auto& citat : itr.citate)
		{
			if (c == citat)
			{
				cout << "Citatul a fost mentionat in lucrarea/lucrariile: " << itr.nume_lucrare << " ";
			}
			break;
		}
	}
	cout << "\n";
}
void Platforma::raportBibliografii(Bibliografie b)
{
	sortareLucrari();
	for (auto& itr : lucrari)
	{

		for (auto& continut : itr.bibliografii)
		{
			if (b == continut)
			{
				cout << "Bibliografia a fost mentionat in lucrarea/lucrariile: " << itr.nume_lucrare << " ";
			}
			break;
		}
	}
	cout << "\n";
}
void Platforma::citesteLucrareFisier(string numeFisier)
{
	ifstream fin(numeFisier);
	Lucrare l(numeFisier.substr(0, numeFisier.size() - 4));
	string s;
	getline(fin, s);
	while (s != "Bibliografie:")
	{
		getline(fin, s);
	}
	while (getline(fin, s))
	{
		if (s[0] == '"')
		{
			string continut = "";
			stringstream sin(s);
			char c;
			sin >> c;
			continut += c;
			sin >> c;
			continut += c;
			while (c != '"')
			{

				sin >> c;
				continut += c;
			}
			sin >> c;//caracterul -
			string autor;
			getline(sin, autor);
			Citat citat(continut, autor);
			l.adaugaCitat(citat);

		}
		else
		{
			string continut = "";
			stringstream sin(s);
			char c;
			sin >> c;
			continut += c;
			sin >> c;
			while (c != '-')
			{

				continut += c;
				sin >> c;
			}
			string autor;
			getline(sin, autor);
			Bibliografie b(continut, autor);
			l.adaugaBibliografie(b);
		}
	}
}
void Platforma::sortareLucrari()
{
	sort(lucrari.begin(), lucrari.end());
}