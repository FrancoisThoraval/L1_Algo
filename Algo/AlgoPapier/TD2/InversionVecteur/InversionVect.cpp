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

void SaisirValeur(int &inf, int &sup)
{	
	cout << "Entrez la borne inferieure: ";
	cin >> inf;
	cout << endl;
	cout << "Entrez la borne superieure: ";
	cin >> sup;
}

void Inverse(int tab[], int inf, int sup)
{	
	int save;
	if (inf < sup)
	{
		save = tab[sup];
		tab[sup] = tab[inf];
		tab[inf] = save;
		Inverse(tab,inf+1,sup-1);
	}

}

int main()
{	
	int tab[taillemax];
	int nbE= 0;
	int inf;
	int sup;
	srand((unsigned)time(0));
	RempliTableau(tab,nbE);
	Affiche(tab,nbE);
	SaisirValeur(inf,sup);
	Inverse(tab,inf,sup);
	Affiche(tab,nbE);
	return 0;
}