#include <iostream>
using namespace std;

typedef struct Individu{
  int Jour;
  string Mois;
  string Nom;
}Individu;

bool TestDate(string Mois, int Jour)
{
  bool test;

  if (Mois == "Fevrier") {
    if ((Jour > 30)&&(Jour <= 0))
      test=false;
    else
      test = true;
  }
  else
  {
    if ((Mois =="Avril")||(Mois =="Juin")||(Mois =="Septembre")||(Mois =="Novembre")){
      if ((Jour <= 0) && (Jour > 30))
        test=false;
      else
        test = true;
    }
    else
      if((Mois == "Janvier") || (Mois == "Mars") || (Mois == "Mai") || (Mois =="Juillet") || (Mois == "Aout") || (Mois == "Octobre") || (Mois == "Decembre"))
      {
        if ((Jour <=0)&& (Jour > 31))
          test=false;
        else
         test = true;
       }
       else
        test = false;
  }
  return test;
}

int main(int argc, char const *argv[]) {
  Individu Personne;
  bool test = false;
  do{
    cout << "Votre Nom: ";
    cin >> Personne.Nom;
    cout << "Entrez un Jour: ";
    cin >> Personne.Jour;
    cout << "Entrez un Mois: ";
    cin >> Personne.Mois;
    test = TestDate(Personne.Mois,Personne.Jour);
  }while(!test);


    if (Personne.Mois == "Janvier")
    {
      if (Personne.Jour <=19) {
        cout << Personne.Nom << " est Capricorne !" << endl;
      }
      else
        cout << Personne.Nom << " est Verseau !" << endl;
    }

    if (Personne.Mois == "Fevrier")
    {
      if (Personne.Jour <=19) {
        cout << Personne.Nom << " est Verseau !" << endl;
      }
      else
        cout << Personne.Nom << " est Poisson !" << endl;
    }

    if (Personne.Mois == "Mars")
    {
      if (Personne.Jour <=20) {
        cout << Personne.Nom << " est Poisson !" << endl;
      }
      else
        cout << Personne.Nom << " est Belier !" << endl;
    }

    if (Personne.Mois == "Avril")
    {
      if (Personne.Jour <=19) {
        cout << Personne.Nom << " est Belier !" << endl;
      }
      else
        cout << Personne.Nom << " est Taureau !" << endl;
    }

    if (Personne.Mois == "Mai")
    {
      if (Personne.Jour <=20) {
        cout << Personne.Nom << " est Taureau !" << endl;
      }
      else
        cout << Personne.Nom << " est un sublime Gemeaux !" << endl;
    }

    if (Personne.Mois == "Juin")
    {
      if (Personne.Jour <=20) {
        cout << Personne.Nom << " est un sublime Gemeaux !" << endl;
      }
      else
        cout << Personne.Nom << " est Cancer !" << endl;
    }

    if (Personne.Mois == "Juillet")
    {
      if (Personne.Jour <=21) {
        cout << Personne.Nom << " est Cancer !" << endl;
      }
      else
        cout << Personne.Nom << " est Lion !" << endl;
    }

    if (Personne.Mois == "Aout")
    {
      if (Personne.Jour <=22) {
        cout << Personne.Nom << " est Lion !" << endl;
      }
      else
        cout << Personne.Nom << " est Vierge !" << endl;
    }

    if (Personne.Mois == "Septembre")
    {
      if (Personne.Jour <=22) {
        cout << Personne.Nom << " est Vierge !" << endl;
      }
      else
        cout << Personne.Nom << " est Balance !" << endl;
    }

    if (Personne.Mois == "Octobre")
    {
      if (Personne.Jour <=22) {
        cout << Personne.Nom << " est Balance !" << endl;
      }
      else
        cout << Personne.Nom << " est Scorpion !" << endl;
    }

    if (Personne.Mois == "Novembre")
    {
      if (Personne.Jour <=21) {
        cout << Personne.Nom << " est Scorpion !" << endl;
      }
      else
        cout << Personne.Nom << " est Sagittaire !" << endl;
    }

    if (Personne.Mois == "Decembre")
    {
      if (Personne.Jour <=22) {
        cout << Personne.Nom << " est Sagittaire !" << endl;
      }
      else
        cout << Personne.Nom << " est Capricorne !" << endl;
    }
  return 0;
}
