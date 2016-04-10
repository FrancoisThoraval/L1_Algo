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
				if (!feof(Annuaire)) {
					for (int k = 0; k <4; k++) {
						min = k;
						for (int j = k+1; j < 3 ; j++) { //j< 4-1
							if (strcmp(Individu[j].Prenom,Individu[min].Prenom) < 0) {
								min = j;
							}
						}
						if (min != k) {
							Save = Individu[min];
							Individu[min] = Individu[i];
							Individu[k] = Save;
						}
					}
				}
			i++;
		}
		fclose (Annuaire);
	}
}

int main()
{
	Contact Individu[4];
	cout << "Création des Contacts" << endl<< endl;
	CreationIndividu(Individu);
	cout << "Création du fichier Annuaire.txt" << endl<< endl;
	CreationFichier(Individu);
	AfficherFichier(Individu);
	cout << "Tri des contacts" << endl<< endl;
	TriAbo(Individu);
	CreationFichier(Individu);
	AfficherFichier(Individu);
	return 0;
}
