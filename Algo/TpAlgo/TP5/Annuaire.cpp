#include <iostream>
#include <fstream>


using namespace std;

struct Contact
{
	string Nom;
	string Prenom;
	string NumeroTel;
};

int main()
{
	struct Contact Individu;
	ofstream Annuaire("Annuaire.txt",ios::out | ios::trunc);
	if (Annuaire)
	{
		cout << "Entrez un Nom: ";
		cin >> Individu.Nom;
		Annuaire << "Nom: " << Individu.Nom << endl;
		cout << "Entrez un Prénom: ";
		cin >> Individu.Prenom;
		Annuaire << "Prénom: " << Individu.Prenom << endl;
		cout << "N° de telephone: ";
		cin >> Individu.NumeroTel;
		Annuaire << "N° de telephone: " << Individu.NumeroTel << endl;
		Annuaire.close();
	}
	else
	{
		cout << "[!] Impossible d'ouvrir le fichier [!]" << endl;
	}
	return 0;
}
