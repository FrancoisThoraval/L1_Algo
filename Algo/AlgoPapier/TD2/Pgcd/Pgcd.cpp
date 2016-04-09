#include <iostream>
using namespace std;

void ChoixNombre(int &nbr1, int &nbr2)
{	
	cout << "Entrez la valeur du 1er nombre: ";
	cin >> nbr1;
	cout << "Entrez la valeur du 2eme nombre: ";
	cin >> nbr2;
	cout << endl;
}

int PGCD(int nbr1,int nbr2)
{	
	if (nbr2==0)
		return (nbr1);
	else
		PGCD(nbr2,(nbr1 % nbr2));
}

int main()
{
	int nbr1;
	int nbr2;
	int res;
	ChoixNombre(nbr1,nbr2);
	res = PGCD(nbr1,nbr2);

	cout << "Pgcd = " << res << endl;

	return 0;
}