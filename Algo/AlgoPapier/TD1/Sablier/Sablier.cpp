#include <iostream>
using namespace std;
#define TailleMax 50

int ChoixN()
{
	int n;
	cout << "Entrez la taille du sablier" << endl;
	cout <<"n= ";
	cin >> n;

	return n;
}

void Affiche (int mat[][TailleMax], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mat[i][j]==1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void CreeSablier(int mat[][TailleMax], int taille)
{	
	for (int i = 0; i <= (taille/2); ++i)
	{
		for (int j = i; j < taille-i; ++j)
		{
			mat[i][j]=1;
			mat[taille-i-1][j]=1;
		}
	}
}

int main()
{
	int Sablier[TailleMax][TailleMax];
	int Choix = ChoixN();
	CreeSablier(Sablier,Choix);
	Affiche(Sablier,Choix);
	return 0;
}