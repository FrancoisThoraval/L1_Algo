#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


typedef struct Contact
{
	string Nom;
	string Prenom;
	string NumeroTel;
}Contact;

void Menu(Contact Individu[]);

void CreationIndividu(Contact Individu[]){
	Individu[0].Nom = "Thoraval";
	Individu[0].Prenom = "Pierre";
	Individu[0].NumeroTel = "0123456789";

	Individu[1].Nom = "Thoraval";
	Individu[1].Prenom = "Olivier";
	Individu[1].NumeroTel = "9876543210";

	Individu[2].Nom = "Thoraval";
	Individu[2].Prenom = "François";
	Individu[2].NumeroTel = "0258741369";

	Individu[3].Nom = "Thoraval";
	Individu[3].Prenom = "Tom";
	Individu[3].NumeroTel = "0258963147";
}

void CreationFichier(Contact Individu[]){
	FILE *Annuaire;

	Annuaire = fopen ("Annuaire.txt","w");
	if (Annuaire!=NULL)
	{
		for (int i = 0; i < 4; i++) {
			fwrite(&Individu[i],sizeof(Contact),1,Annuaire);
		}
		fclose (Annuaire);
	}
	else
	{
		cerr << "[!] Impossible d'ouvrir le fichier [!]" << endl;
	}
}

void AfficherFichier(Contact Individu[]){
	FILE *Annuaire;
	int i=0;
	Annuaire = fopen ("Annuaire.txt","r");
	if (Annuaire!=NULL)
	{
		while (!feof(Annuaire)||(i<4)) {
			fread(&Individu[i], sizeof(Contact),1, Annuaire);
				if (!feof(Annuaire)) {
					cout << "---------" << endl;
					cout << Individu[i].Nom << endl;
					cout << Individu[i].Prenom << endl;
					cout << Individu[i].NumeroTel << endl;
				}
			i++;
		}
		cout << "---------" << endl;
		fclose (Annuaire);
	}
	Menu(Individu);
}

void Tri(Contact Individu[]) {
	int min;
	Contact aux;

	for (int i = 0; i < 4; i++) {
		min = i;
		for (int j = i+1; j < 4; j++) {
			if (Individu[j].Prenom < Individu[min].Prenom) {
				min = j;
			}
		}
		if (min != i) {
			aux = Individu[min];
			Individu[min] = Individu[i];
			Individu[i] = aux;
		}
	}

}

void TriAbo(Contact Individu[])
{
	Contact Save;
	FILE *Annuaire;
	int i=0;
	int min;

	Annuaire = fopen ("Annuaire.txt","r");
	if (Annuaire!=NULL)
	{
		while (!feof(Annuaire)||(i<4)) {
			fread(&Individu[i], sizeof(Contact),1, Annuaire);
			i++;
		}
		fclose (Annuaire);
	}
	Tri(Individu);
	CreationFichier(Individu);
	Menu(Individu);
}

void Menu(Contact Individu[]){
	int Choix;

	cout << "================ MENU ================" << endl;
	cout << "1. Afficher" << endl;
	cout << "2. Trier" << endl;
	cout << "3. Rechercher (en developpement)" << endl;
	cout << "4. Changer Numero (en developpement)" << endl;
	cout << "5. Ajouter un abonné (en developpement)" << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "." << endl;
	cout << "9. Quitter" << endl;
	cout << "======================================" << endl << endl;
	cout << "Choix: ";
	cin >> Choix;
	switch (Choix) {
		case 1: AfficherFichier(Individu);
			break;
		case 2: TriAbo(Individu);
			break;
		case 3: Menu(Individu);
			break;
		case 4: Menu(Individu);
			break;
		case 5: Menu(Individu);
			break;
		case 9: ;
			break;
	}
}

int main()
{
	Contact Individu[4];
	cout << "Création des Contacts" << endl<< endl;
	CreationIndividu(Individu);
	cout << "Création du fichier Annuaire.txt" << endl<< endl;
	CreationFichier(Individu);
	Menu(Individu);
	return 0;
}
