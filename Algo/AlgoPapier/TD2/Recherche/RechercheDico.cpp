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

bool Recherche(int tab[], int inf, int sup, int val)
{
	bool trouve = false;

	if (inf <= sup){
		trouve=((tab[inf]==val)||(tab[sup]==val));
		if (trouve)
			return trouve;
		else
			return Recherche(tab,inf+1,sup-1,val);
	}
	else
		return false;
}

int SaisirValeur()
{	
	int nbr1;
	cout << "Entrez la valeur du nombre à trouver: ";
	cin >> nbr1;
	cout << endl;
	return nbr1;
}

int main()
{	
	int tab[taillemax];
	int nbE=0;
	int inf =0;
	int sup =0;
	int val =0;
	bool cherche;

	srand((unsigned)time(0));
	RempliTableau(tab,nbE);
	sup = nbE-1;
	Affiche(tab,nbE);
	val = SaisirValeur();
	cherche = Recherche(tab,inf,sup,val);
	if (cherche)
		cout << "Trouvé !" << endl;
	else
		cout << "Pas Trouvé !" << endl;
	return 0;
}