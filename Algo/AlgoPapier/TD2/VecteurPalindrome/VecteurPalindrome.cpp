#include <iostream>

using namespace std;

string Saisie()
{
	string Mot= " ";
	cout << "Entrez un mot: ";
	cin >> Mot;

	return Mot;
}

bool Recherche(string Mot, int inf, int sup, bool valide)
{
	bool trouve = valide;

	if (inf <= sup){
		trouve=(Mot[inf]==Mot[sup]);
		if (trouve)
			return Recherche(Mot,inf+1,sup-1, trouve);
		else
			return trouve;
	}
	else
		return valide;
}

int main()
{	
	int taille;
	bool valide = false;
	bool test;
	int inf = 0;
	int sup;
	string Mot=Saisie();
	taille = Mot.size();
	sup = taille-1;
	cout << "Recherche si "<< Mot << " est un palindrome en cours ..." << endl;
	test = Recherche(Mot,inf,sup,valide);
	if (test)
		cout << "C'est un palindrome !" << endl;
	else
		cout << "Ce n'est pas un palindrome" << endl;
	return 0;
}