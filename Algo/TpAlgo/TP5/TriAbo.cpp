#include <iostream>
#include <fstream>
#include <stdio.h>
#include <limits> 
#include <string>

using namespace std;

struct Contact
{
	string Nom;
	string Prenom;
	string NumeroTel;
};

void Erreur()
{
	cout << "[!] Impossible d'ouvrir le fichier [!]" << endl;
}

void TriPrenom()
{
	struct Contact tab[5];
	struct Contact Individu;
	int taille = 5;
	int i,min,j,aux;
	string tab;
	string tabBis;

	ifstream fichier("Annuaire.txt",ios::in);
	getline(Annuaire,tab);
	for (int i = 1; i < taille-1; ++i)
	{
		Annuaire.seekg(0, ios::beg);
		for (int i = 0; i < (4*i-4); ++i){
			Annuaire.ignore(numeric_limits<int>::max(), '\n');
		}
		getline(Annuaire,tabBis);
		min = i;

		for (int j = i+1; j <= taille; ++j)
		{
			if (tab[j]<tab[min])
			{
				min=j;
			}
		}
		if (min!=i)
		{
			aux=tab[i];
			tab[i]=tab[min];
			tab[min]=aux;
		}
	}


	fclose(Annuaire);

}

void Saisie()
{
	struct Contact Individu;
	ofstream Annuaire("Annuaire.txt",ios::out | ios::trunc);
	if (Annuaire)
	{	
		for (int i = 0; i < 5; ++i)
		{	
			cout << "Contact n°" << i+1 << endl;
			cout << "Entrez un Nom: ";
			cin >> Individu.Nom;
			Annuaire << "Nom: " << Individu.Nom << endl;
			cout << "Entrez un Prénom: ";
			cin >> Individu.Prenom;
			Annuaire << "Prénom: " << Individu.Prenom << endl;
			cout << "N° de telephone: ";
			cin >> Individu.NumeroTel;
			Annuaire << "N° de telephone: " << Individu.NumeroTel << endl << endl;
		}
		Annuaire.close();
	}
	else
	{
		Erreur();
	}
}

int main()
{	
	int Choix;

	ofstream Annuaire("Annuaire.txt",ios::out |ios::trunc);
	if(Annuaire)
	{
		Saisie();
	}
	else
	{
		Erreur();
	}

	cout << "Tri de l'Annuaire en cours ..." << endl;
	TriPrenom();
	
	return 0;
}