#include <iostream>
using namespace std;

int Partitioner(int t[], int premier, int dernier)
{
	int gauche;
	int droit;
	int elt;
	int aux;

	elt=t[premier];
	gauche=premier+1;
	droit=dernier;

	while(gauche <= droit){
		while(t[gauche]<=elt){
			gauche++;
		}
		while(t[droit]>elt){
			droit--;
		}
		if (gauche<=droit)
		{
			aux=t[droit];
			t[droit]=t[gauche];
			t[gauche]=aux;
			gauche++;
			droit--;
		}
	}
	aux=t[premier];
	t[premier]=t[droit];
	t[droit]=aux;

	return droit;
}

void QuickSort(int t[], int premier, int dernier)
{
	int pivot;

	if (premier<dernier)
	{
		pivot=Partitioner(t,premier,dernier);
		QuickSort(t,premier,pivot-1);
		QuickSort(t,pivot+1,dernier);
	}
}

void Affiche(int tab[],int nbE)
{
	for (int i = 0; i < nbE; ++i)
	{
		cout << "[" << tab[i] << "]";
	}
	cout << endl;
	cout << endl;
}

int main()
{	
	int tab[]={12,56,45,89,87,56,54,23,1,2};
	int nbE=10;

	Affiche(tab,nbE);
	QuickSort(tab,0,9);
	Affiche(tab,nbE);
	return 0;
}