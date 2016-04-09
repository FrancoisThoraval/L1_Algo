#include <iostream>
using namespace std;

#define TailleMax 50

int ChoixN()
{
	int n;
	cout << "Entrez la taille de la matrice" << endl;
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
			cout<<"["<<mat[i][j]<<"]";
		}
		cout << endl;
	}
}

void RempliMat(int mat[][TailleMax], int n)
{
	int NbrExt = (n+1)/2;

	for(int i=0;i<=(n/2);i++)
	{		
		for(int j=i;j<(n-i);j++)
		{	
			mat[i][j]=NbrExt;
			mat[j][i]=NbrExt;
			mat[n-i-1][j]=NbrExt;
			mat[j][n-i-1]=NbrExt;
		}
		NbrExt--;
	}

}

int main()
{	
	int TailleMat = ChoixN();
	int mat[TailleMax][TailleMax];
	
	RempliMat(mat, TailleMat);
	Affiche(mat,TailleMat);
	return 0;
}