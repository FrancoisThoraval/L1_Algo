#include <iostream>
#include <fstream>
#include <string.h>
#include <malloc.h>

using namespace std;


typedef struct Contact
{
	string Nom;
	string Prenom;
	string NumeroTel;
}Contact;

void Menu(Contact Individu[], int i);

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

void CreationFichier(Contact Individu[],int NbrAbo){
	FILE *Annuaire;

	Annuaire = fopen ("Annuaire.txt","w");
	if (Annuaire!=NULL)
	{
		for (int i = 0; i < NbrAbo; i++) {
			fwrite(&Individu[i],sizeof(Contact),1,Annuaire);
		}
		fclose (Annuaire);
	}
	else
	{
		cerr << "[!] Impossible d'ouvrir le fichier [!]" << endl;
	}
}

void AfficherFichier(Contact Individu[],int NbrAbo){
	FILE *Annuaire;
	int i=0;
	Annuaire = fopen ("Annuaire.txt","r");
	if (Annuaire!=NULL)
	{
		while (!feof(Annuaire)||(i<NbrAbo)) {
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
	Menu(Individu,NbrAbo);
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

void TriAbo(Contact Individu[], int NbrAbo)
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
	CreationFichier(Individu,NbrAbo);
	Menu(Individu,NbrAbo);
}

void Recherche(Contact Individu[], int NbrAbo){
	string Numero;
	FILE *Annuaire;
	int i=0;
	cout << endl << endl;
	do{
		cout << "Numéro recherché: ";
		cin >> Numero;
	}while(Numero.size()!=10);
	Annuaire = fopen ("Annuaire.txt","r");
	if (Annuaire!=NULL)
	{
		cout << "---------" << endl;
		while (!feof(Annuaire)&&(i<4)&&(Individu[i].NumeroTel!=Numero)) {
			fread(&Individu[i], sizeof(Contact),1, Annuaire);
			i++;
		}
		if (Individu[i].NumeroTel==Numero) {
			cout << Individu[i].Nom << endl;
			cout << Individu[i].Prenom << endl;
			cout << Individu[i].NumeroTel << endl;
		}
		if (i>=4) {
			cout << "Aucun contact avec ce numéro !" << endl;
			Recherche(Individu,i);
		}
		cout << "---------" << endl;
		fclose (Annuaire);
	}
	Menu(Individu,NbrAbo);
}

void ModifNum(Contact Individu[], int NbrAbo){
	string Numero;
	FILE *Annuaire;
	int i=0;
	cout << endl << endl;
	do{
		cout << "Ancien Numéro: ";
		cin >> Numero;
	}while(Numero.size()!=10);
	Annuaire = fopen ("Annuaire.txt","r");
	if (Annuaire!=NULL)
	{
		cout << "---------" << endl;
		while (!feof(Annuaire)&&(i<4)&&(Individu[i].NumeroTel!=Numero)) {
			fread(&Individu[i], sizeof(Contact),1, Annuaire);
			i++;
		}
		if (Individu[i].NumeroTel==Numero) {
			cout << "Entrez le nouveau numéro: ";
			cin >> Individu[i].NumeroTel;
		}
		if (i>=4) {
			cout << "Aucun contact avec ce numéro !" << endl;
			ModifNum(Individu,NbrAbo);
		}
		cout << "---------" << endl;
		fclose (Annuaire);
	}
	CreationFichier(Individu,NbrAbo);
	Menu(Individu,NbrAbo);
}

void AjoutAbo(Contact Individu[], int &NbrAbo) {
	Contact TestAjout[NbrAbo+1];
	for (int i = 0; i < NbrAbo; i++) {
		TestAjout[i].Nom=Individu[i].Nom;
		TestAjout[i].Prenom=Individu[i].Prenom;
		TestAjout[i].NumeroTel=Individu[i].NumeroTel;
	}
	cout << "Nom: ";
	cin >> TestAjout[NbrAbo].Nom;
	cout << "Prenom: ";
	cin >> TestAjout[NbrAbo].Prenom;
	do {
		cout << "Numéro de téléphone: ";
		cin >> TestAjout[NbrAbo].NumeroTel;
	} while(TestAjout[NbrAbo].NumeroTel.size() != 10);
	CreationFichier(TestAjout,NbrAbo+1);
	Menu(TestAjout,NbrAbo+1);
}


void Menu(Contact Individu[], int i){
	int Choix;

	cout << "================ MENU ================" << endl;
	cout << "1. Afficher" << endl;
	cout << "2. Trier" << endl;
	cout << "3. Rechercher" << endl;
	cout << "4. Changer Numero" << endl;
	cout << "5. Ajouter un abonné" << endl;
	cout << "." << endl;
	cout << "." << endl;  blablabla
	cout << "." << endl;
	cout << "9. Quitter" << endl;
	cout << "======================================" << endl << endl;
	cout << "Choix: ";
	cin >> Choix;
	switch (Choix) {
		case 1: AfficherFichier(Individu,i);
			break;
		case 2: TriAbo(Individu,i);
			break;
		case 3: Recherche(Individu,i);
			break;
		case 4: ModifNum(Individu,i);
			break;
		case 5: AjoutAbo(Individu,i);
			break;
		case 9: ;
			break;
	}
}

int main()
{
	int i=4; //Nombre de Contacts au départ
	Contact Individu[i];
	cout << "** Création des Contacts **" << endl;
	CreationIndividu(Individu);
	cout << "** Création du fichier Annuaire.txt **" << endl<< endl;
	CreationFichier(Individu, i);
	Menu(Individu,i);
	return 0;
}
