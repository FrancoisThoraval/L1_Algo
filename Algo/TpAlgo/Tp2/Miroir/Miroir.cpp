#include <iostream>

using namespace std;

string Saisie()
{
	string Mot;

	cout << "Entrez le mot: ";
	cin >> Mot;
	cout << endl;
	return Mot;
}

void Miroir (string Mot, bool endroit)
{
	int taille = Mot.size();
	if (endroit)
	{
		endroit = false;
		cout << Mot;
		Miroir(Mot,endroit);
	}
	else
	{
		for (int i = taille; i >= 0; --i)
		{
			cout << Mot[i];
		}
		cout << endl;
	}

}

int main()
{
	string Mot = Saisie();
	bool endroit= true;
	Miroir(Mot,endroit);
	return 0;
}