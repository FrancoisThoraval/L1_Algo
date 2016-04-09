#include <iostream>
using namespace std;

int Calcul(int Somme,int bmax ,int bmin ,int mod,int n)
{	
	if ((Somme%mod)==0)
	{	
		cout << "test" << endl;
		if (bmax<=bmin)
		{
			if ((Somme-bmin) ==0)
			{
				return Calcul(Somme,bmax,bmin*2,bmin*2,n+1);
			}
			else
			{	if ((Somme-bmin)>0)
				{
					return Calcul(Somme-bmin,bmax,bmin,bmin,n);
				}
			}
		}
		else
			return n;
	}
	else
		return n;
}

int main()
{
	int Somme;
	int NbrDecompo;
	int n =0;
	cout << "Entrez la somme d'argent: ";
	cin >> Somme;
	NbrDecompo= Calcul(Somme,20,5,5,n);
	cout << endl;
	cout << "Il y a " << NbrDecompo << " possibilitées !" << endl;
	return 0;
}