#ifndef CITAT_H
#define CITAT_H
#include <string>
using namespace std;

class Citat
{
private:
	string citat,autor;
public:
	Citat(string citat, string autor) :citat(citat), autor(autor) {};
	string getCitat() { return citat; }
	string getAutor() { return autor; }
	bool operator==(Citat c)
	{
		return citat == c.citat && autor == c.autor;
	}
};

#endif // !1
