#include "menu.h"
#include "platforma.h"
bool existaFisier(string numeFisier)
{
	ifstream f(numeFisier);
	return f.good();
}
void Menu::Start()
{
	system("cls");
	Platforma platformaMea;
	string numePlatforma;
	cout << "\t\t\t\t\t/// Start Menu /// \n";
	cout << "\t1.Incarca platforma\n\t2.Creeaza o noua platforma\n\t3.Exit\n\t";
	int t;
	cin >> t;
	cin.ignore();
	system("cls");
	if (t == 1)
	{
		cout << "\t\t\t\t\t/// Incarcare platforma /// \n";
		cout << "\tIntroduceti numele platformei : ";
		getline(cin, numePlatforma);
		if (existaFisier(numePlatforma+".txt"))
		{
			platformaMea.initializarePlatforma(numePlatforma + ".txt");
		}
		else
		{
			cout << "\tNume invalid , reincercati \n\t";
			cin.get();
			Start();
			return;


		}
	}
	else if(t==2)
	{
		cout << "\t\t\t\t\t/// Creeare noua platforma /// \n";
		cout << "\tIntroduceti numele platformei : ";
		getline(cin, numePlatforma);
		if (existaFisier(numePlatforma + ".txt"))
		{
			cout << "\tPlatforma cu acest nume deja exista , reincercati\n\t";
			cin.get();
			Start();
			return;
		}
		
	}
	else if (t == 3)
	{
		return;
	}
	else
	{
		system("cls");
		cout << "\n\tError.Press enter to retry";
		cin.get();
		Start();
		return;
	}
	do {
		system("cls");
		cout << "\t\t\t\t\t/// Platforma "<<numePlatforma<<" ///\n";
		cout << "\t1.Introducere lucrare\n\t2.Cautare citat\n\t3.Cautare bibliografie\n\t4.Cautare lucrare\n\t5.Afisare citate & bibliografii\n\t6.Afisare lucrari\n\t7.Salveaza\n\t8.Exit to menu\n\t";
		int c;
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Introducere lucrare ///\n";
			cout << "\t1.De la tastatura \n\t2.Din fisier\n\t";
			cin >> c;
			cin.ignore();
			if (c == 1)
			{
				system("cls");
				cout << "\t\t\t\t\t/// Introducere lucrare de la tastatura ///\n";
				cout << "\tNume lucrare:";
				string numeLucrare;
				getline(cin, numeLucrare);
				if (platformaMea.cautareLucrare(numeLucrare))
				{
					cout << "\tLucrarea se afla deja in platforma\n\t";
					cin.get();
					continue;
				}
				Lucrare l(numeLucrare);
				cout << "\tNumar citate:";
				int n;
				cin >> n;
				cin.ignore();
				for (int i = 1;i <= n;i++)
				{
					string continut;
					cout << "\tContinutul citatului " << i << ":";
					getline(cin, continut);
					cout << "\tAutorul citatului " << i << ":";
					string autor;
					getline(cin, autor);
					Citat citat(continut,autor);
					l.adaugaCitat(citat);
				}
				cout << "\tNumar bibligrafii:";
				cin >> n;
				cin.ignore();
				for (int i = 1;i <= n;i++)
				{
					cout << "\tContinutul bibligrafiei " << i << ":";
					string continut;
					getline(cin, continut);
					cout << "\tAutorul bibliografiei " << i << ":";
					string autor;
					getline(cin, autor);
					Bibliografie b(continut, autor);
					l.adaugaBibliografie(b);
				}
				platformaMea.adaugaLucrare(l);
				cout << "\tLucrarea " << numeLucrare << " a fost adaugata cu succes";
				cin.get();


			}
			else if (c == 2)
			{
				system("cls");
				cout << "\t\t\t\t\t/// Introducere lucrare din fisier ///\n";
				cout << "\tNume lucrare:";
				string numeFisierLucrare;
				getline(cin, numeFisierLucrare);
				if (!existaFisier(numeFisierLucrare+".txt"))
				{
					cout << "\tNu exista fisierul pentru aceasta lucrare , reincercati\n\t";
					cin.get();
					continue;
				}
				if (platformaMea.cautareLucrare(numeFisierLucrare))
				{
					cout << "\tLucrarea se afla deja in platforma\n\t";
					cin.get();
					continue;
				}
				if(platformaMea.citesteLucrareFisier(numeFisierLucrare + ".txt"))
				{
					cout << "\tLucrarea " << numeFisierLucrare << " a fost adaugata cu succes\n\t";
				}
				else
				{
					cout << "\tNu s-au gasit citate sau bibliografii in lucrarea " << numeFisierLucrare << "\n\t";
				}
				cin.get();
			}
			else
			{
				system("cls");
				cout << "\n\tError.Press enter to retry";
				cin.get();
			}

			break;
		}
		case 2:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Cautare citat ///\n";
			cout << "\tContinutul citatului :";
			string continut;
			getline(cin, continut);
			cout << "\tAutorul citatului :";
			string autor;
			getline(cin, autor);
			Citat citat(continut, autor);
			platformaMea.raportCitate(citat);
			cout << "\t";
			cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Cautare bibliografie ///\n";
			cout << "\tContinutul bibliografiei :";
			string continut;
			getline(cin, continut);
			cout << "\tAutorul bibliografiei :";
			string autor;
			getline(cin, autor);
			Bibliografie b(continut, autor);
			platformaMea.raportBibliografii(b);
			cout << "\t";
			cin.get();
			break;
		}
		case 4:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Cautare lucrare ///\n";
			cout << "\tNumele lucrarii cautate: ";
			string numeLucrare;
			getline(cin, numeLucrare);
			if (platformaMea.cautareLucrare(numeLucrare))
			{
				platformaMea.afisareLucrare(numeLucrare);
				cin.get();
			}
			else
			{
				cout << "\tLucrarea nu se afla in platforma\n\t";
				cin.get();
			}
			break;
		}
		case 5:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Afisare citate & bibliografii ///\n";
			platformaMea.afisareCitateSiBibliografii();
			cout << "\t";
			cin.get();
			break;
		}
		case 6:
		{
			system("cls");
			cout << "\t\t\t\t\t/// Afisare lucrari ///\n";
			platformaMea.afisareLucrari();
			cout << "\t";
			cin.get();
			break;
		}
		case 7:
		{
			platformaMea.salvarePlatforma(numePlatforma + ".txt");
			cout << "\tPlatforma a fost salvata cu succes\n\t";
			cin.get();
			break;
		}
		case 8:
		{
			Start();
			return;
			break;
		}
		default:
		{
			system("cls");
			cout << "\n\tError.Press enter to retry";
			cin.get();
			break;
		}
		
		}
	} while (1);
}