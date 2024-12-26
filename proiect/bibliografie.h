#ifndef BIBLIOGRAFII_H
#define BIBLIOGRAFII_H
#include <string>
using namespace std;
class Bibliografie
{
public:
	std::string continut, autor;
public:
	Bibliografie(std::string continut, std::string autor) :continut(continut), autor(autor) {};
	string getBibliografie() { return continut; }
	string getAutor() { return autor; }
	bool operator==(Bibliografie b)
	{
		return continut == b.continut && autor == b.autor;
	}
};


#endif // !BIBLIOGRAFII_H
