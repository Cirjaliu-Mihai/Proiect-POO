#ifndef CITATE_H
#define CITATE_H
#include <string>
using namespace std;

class Citate
{
private:
	string citat,autor;
public:
	Citate(string citat, string autor) :citat(citat), autor(autor) {};
	string getCitat() { return citat; }
	string getAutor() { return autor; }
	bool operator==(Citate c)
	{
		return citat == c.citat && autor == c.autor;
	}
};

#endif // !1
