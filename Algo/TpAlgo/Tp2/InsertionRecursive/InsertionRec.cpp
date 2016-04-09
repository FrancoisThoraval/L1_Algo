#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define taillemax 50

void RempliTableau (int tab[], int &nbE)
{
	for (int i = 0; i < 10; ++i)
	{
		tab[i]=(rand()%10);
		nbE++;
	}
}

void Affiche(int tab[], int nbE)
{
	for (int j = 0; j < nbE; ++j)
	{
		cout<<"["<<tab[j]<<"]";
	}
	cout << endl;
}

void Rec_Inser (int tab[], int inf, int sup, int val,int &nbE)
{	
	if (inf <= sup)
	{	

		tab[inf]=val;
		inf++;
		Rec_Inser(tab,inf,sup,val,nbE);
	}
}

void SaisirBornes(int &inf, int &sup)
{	
	cout << "Entrez la borne inferieure: ";
	cin >> inf;
	cout << endl;
	cout << "Entrez la borne superieure: ";
	cin >> sup;
}

int SaisirValeur()
{	
	int nbr1;
	cout << "Entrez la valeur du nombre à insérer: ";
	cin >> nbr1;
	cout << endl;
	return nbr1;
}

int main()
{	
	int tab[taillemax];
	int nbE=0;
	int inf;
	int sup;
	int val =SaisirValeur();

	srand((unsigned)time(0));
	RempliTableau(tab,nbE);
	Affiche(tab,nbE);
	SaisirBornes(inf,sup);
	Rec_Inser(tab,inf,sup,val,nbE);
	Affiche(tab,nbE);
}