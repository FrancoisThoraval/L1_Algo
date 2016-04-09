#include <iostream>
#include <ctime>
using namespace std;

void FibonacciIte(int n,bool TimeAttack)
{	
	int val1 =1;
	int val2=1;
	int val3;
	if (!TimeAttack)
	{	
		cout << "["<< val1 << "] ";
		cout << "["<< val2 << "] ";
		for (int i = 0; i < n; ++i)
		{
			val3=val1+val2;
			cout << "[" << val3 << "] ";
			if (i==0)
				val2=val3;
			else
			{
				val1=val2;
				val2=val3;
			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			val3=val1+val2;
			if (i==0)
				val2=val3;
			else
			{
				val1=val2;
				val2=val3;
			}
		}
	}
}

void Rec(int val1, int val2, int n,bool test,bool TimeAttack)
{
	int val3 = val1 + val2;
	if (!TimeAttack)
	{
		if (n > 0)
		{
			cout << "[" << val3 << "] ";
			if (test)
			{
				Rec(val1,val3,n-1,false,TimeAttack);
			}
			else
			{
				Rec(val2,val3,n-1,false,TimeAttack);
			}
		}
	}
	else
	{
		if (n > 0)
		{
			if (test)
			{
				Rec(val1,val3,n-1,false,TimeAttack);
			}
			else
			{
				Rec(val2,val3,n-1,false,TimeAttack);
			}
		}
	}
}

void FibonacciRec(int n,bool TimeAttack)
{
	int val1=1;
	int val2=1;
	int val3;
	bool test = true;
	if (!TimeAttack)
	{
		cout << "["<< val1 << "] ";
		cout << "["<< val2 << "] ";
		Rec(val1,val2, n,test,TimeAttack);
	}
	else
	{
		Rec(val1,val2,n,test,TimeAttack);
	}
}

void TimeAttack(int n,bool TimeAttack)
{
	clock_t startIte;
	clock_t startRec;
	startIte=clock();
	FibonacciIte(n, TimeAttack);
	cout << "Temps Itératif: " << (clock() - startIte) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
	startRec=clock();
	FibonacciRec(n, TimeAttack);
	cout << "Temps Récursif: " << (clock() - startRec) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
}

int main()
{
	int i;
	long int n=0;
	if (n <= 0);
	{
		cout << "Entrez le n pour tout les tests: "; //Max ~130000 pour la récursivité
		cin >> n;
		for (int j = 0; j < 50; ++j)
		{
			cout << endl << endl;
		}
	}

	cout << "------------|| Menu ||------------" << endl << endl;
	cout << "1) Fibonacci Itératif" << endl;
	cout << "2) Fibonacci Récursif" << endl;
	cout << "3) Comparaison des temps" << endl;
	cout << "9) Quitter" << endl;
	cout << "Choix: ";
	cin >> i;
	cout << endl; 
	switch (i)
	{
		case 1: FibonacciIte(n,false);
		break;
		case 2: FibonacciRec(n,false);
		break;
		case 3: TimeAttack(n,true);
		break;
		case 9: return 0;
		default: main();
	}
	return 0;
}