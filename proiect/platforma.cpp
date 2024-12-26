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
	fin.ignore();
	while (numar_lucrari--)
	{
		string nume;
		getline(fin, nume);
		fin >> numar_citate >> numar_bibliografii;
		fin.ignore();
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
	bool ok = 0;
	for (auto& itr : lucrari)
	{

		for (auto& citat : itr.citate)
		{
			if (c == citat && ok==0)
			{
				cout << "\tCitatul a fost mentionat in lucrarea/lucrariile: " << itr.nume_lucrare << " ";
				ok = 1;
			}
			else if (c == citat)
			{
				cout << itr.nume_lucrare << " ";
			}
			break;
		}
	}
	if (ok == 0)
	{
		cout << "\tCitatul nu a fost gasit";
	}
	cout << "\n";
}
void Platforma::raportBibliografii(Bibliografie b)
{
	sortareLucrari();
	bool ok = 0;
	for (auto& itr : lucrari)
	{

		for (auto& continut : itr.bibliografii)
		{
			if (b == continut && ok==0)
			{
				cout << "\tBibliografia a fost mentionat in lucrarea/lucrariile: " << itr.nume_lucrare << " ";
				ok = 1;
			}
			else if(b==continut)
			{
				cout << itr.nume_lucrare << " ";
			}
			break;
		}
	}
	if (ok == 0)
	{
		cout << "\tBibliografia nu a fost gasita";
	}
	cout << "\n";
}
bool Platforma::citesteLucrareFisier(string numeFisier)
{
	ifstream fin(numeFisier);
	Lucrare l(numeFisier.substr(0, numeFisier.size() - 4));
	string s;
	getline(fin, s);
	while (s != "Bibliografie:" && getline(fin, s))
	{

	}
	
	while (getline(fin, s))
	{
		if (s[0] == '"')
		{
			char c;
			int i = 0;
			stringstream sin(s);
			sin.ignore();
			sin >> c;
			while (c != '"')
			{
				i++;
				c = sin.get();
			}
			sin.ignore(3);
			string continut = s.substr(1,i);
			string autor;
			getline(sin, autor);
			Citat citat(continut, autor);
			l.adaugaCitat(citat);


		}
		else
		{
			char c;
			int i = 0;
			stringstream sin(s);
			sin >> c;
			while (c != '-')
			{
				i++;
				c = sin.get();
			}
			sin.ignore();
			string continut = s.substr(0, i-1);
			string autor;
			getline(sin, autor);
			Bibliografie b(continut, autor);
			l.adaugaBibliografie(b);
		}
	}
	fin.close();
	if (!l.citate.empty() || !l.bibliografii.empty()) 
	{
		adaugaLucrare(l);
		return 1;
	}
	return 0;
	
}
void Platforma::sortareLucrari()
{
	sort(lucrari.begin(), lucrari.end());
}
void Platforma::afisareCitateSiBibliografii()
{
	sortareAlfabeticaNume();
	cout << "\tCitate:\n";
	for (auto& itr : citate)
	{
		cout << "\t\"" <<itr.getCitat() << "\" - " << itr.getAutor()<<"\n";
	}
	cout << "\tBibliografii:\n";
	for (auto& itr : bibliografii)
	{
		cout << "\t " << itr.getBibliografie() << " - " << itr.getAutor() << "\n";
	}
}
void Platforma::afisareLucrari()
{
	for (auto& l : lucrari)
	{
		cout << "\t\tLucrarea " << l.nume_lucrare << "\n";
		cout << "\tCitate:\n";
		for (auto& itr : l.citate)
		{
			cout << "\t\"" << itr.getCitat() << "\" - " << itr.getAutor() << "\n";
		}
		cout << "\tBibliografii:\n";
		for (auto& itr : l.bibliografii)
		{
			cout << "\t " << itr.getBibliografie() << " - " << itr.getAutor() << "\n";
		}
	}
}
bool Platforma::cautareLucrare(string numeLucrare)
{
	for (auto& l : lucrari)
	{
		if (l.nume_lucrare == numeLucrare)
		{
			return 1;
		}
	}
	return 0;
}
void Platforma::afisareLucrare(string numeLucrare)
{
	for (auto& l : lucrari)
	{
		if (l.nume_lucrare == numeLucrare)
		{
			cout << "\tCitate:\n";
			for (auto& itr : l.citate)
			{
				cout << "\t\"" << itr.getCitat() << "\" - " << itr.getAutor() << "\n";
			}
			cout << "\tBibliografii:\n";
			for (auto& itr : l.bibliografii)
			{
				cout << "\t " << itr.getBibliografie() << " - " << itr.getAutor() << "\n";
			}
			break;
		}
	}
}
