#ifndef BIBLIOGRAFII_H
#define BIBLIOGRAFII_H
#include <string>
class Bibliografii
{
public:
	std::string bibliografie, autor;
public:
	Bibliografii(std::string bibliografie, std::string autor) :bibliografie(bibliografie), autor(autor) {};
	string getBibliografie() { return bibliografie; }
	string getAutor() { return autor; }
	bool operator==(Bibliografii b)
	{
		return bibliografie == b.bibliografie && autor == b.autor;
	}
};


#endif // !BIBLIOGRAFII_H
