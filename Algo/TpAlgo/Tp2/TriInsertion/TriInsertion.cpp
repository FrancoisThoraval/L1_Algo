#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define taillemax 50

void RempliTableau (int tab[],int tabBis[] ,int &nbE)
{
	for (int i = 0; i < 10; ++i)
	{
		tab[i]=(rand()%10);
		tabBis[i]=tab[i];
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

void TriInsertion (int tab[],int nbE)
{	
	int j;
	int val;

	for (int i = 0; i < nbE; ++i)
	{
		val = tab[i];
		j=i;
		while((j>0)&&(tab[j-1] > val))
		{
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=val;
	}
}


void TriInsertionTest (int tab[],int nbE,int i)
{	
	int j=nbE-1;
	int val;
	int tabBis[taillemax];
	for(int k = 0; k<nbE;k++)
	{	
		val=tab[k];	
		j=k;
		while((j>0)&&(tab[j-1] > val))
		{	
			tab[j]=tab[j-1];
			j--;
		}
		tab[j]=val;
		Affiche(tab,nbE);
		cout << endl;

	}

}


int main()
{	
	int tab[taillemax];
	int tabBis[taillemax];
	int nbE=0;
	int inf=1;
	int sup;
	int val =SaisirValeur();

	srand((unsigned)time(0));
	RempliTableau(tab,tabBis,nbE);
	cout << "Tab:    ";
	Affiche(tab,nbE);
	cout<< "TabBis: ";
	Affiche(tabBis,nbE);
	cout << endl;
	TriInsertion(tab,nbE);
	TriInsertionTest(tabBis,nbE,inf);
	cout<< "TabBis: ";
	Affiche(tabBis,nbE);
	cout << "Tab:    ";
	Affiche(tab,nbE);
	//SaisirBornes(inf,sup);
	//Rec_Inser(tab,inf,sup,val,nbE);
	//Affiche(tab,nbE);
}