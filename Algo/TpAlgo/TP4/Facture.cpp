#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int Quitter ();

typedef struct S_Article {
    int NumArticle;
    string NomArticle;
    float Prix;
    int QuantiteDispo;
}S_Article;

typedef struct S_ArticleChoisi{
    int NumArticle;
    string NomArticle;
    float PrixU;
    float PrixTotal;
    int QuantiteVoulue;
}S_ArticleChoisi;

void CreationArticle(int Num, string Nom, float Px, int Qte,S_Article tabArticle[]){ // (int NumArticle, string NomArticle, float Prix, int QuantiteDispo)

    S_Article Objet;

    Objet.NumArticle = Num;
    Objet.NomArticle = Nom;
    Objet.Prix = Px;
    Objet.QuantiteDispo = Qte;

    tabArticle[Num]=Objet;
}

void Article (S_Article tabArticle[]){

    CreationArticle(0,"Table",200,5,tabArticle); //(Code, Nom, Prix, Quantitée)
    CreationArticle(1,"Chaise",70,15,tabArticle);
    CreationArticle(2,"Nappe",20,60,tabArticle);
    CreationArticle(3,"Paniere",15,80,tabArticle);
    CreationArticle(4,"Aspirateur",50,15,tabArticle);
    CreationArticle(5,"Parasol",40,10,tabArticle);
}

void Menu(int &Code, int &Quantite){
    cout << endl;
    cout << "Quel Article souhaitez-vous (entrez le code d'article): ";
    cin >> Code;
    cout << "Quelle quantitée ?: ";
    cin >> Quantite;
}

int RechercheArticle (int Num, int Qte, S_Article tabArticle[])
{
    int Res =1;
    int i =0;

    if ((Num<0)||(Num>6)) {
        Res=1;
    }
    else{
        while (Res==1){
            if(Num==tabArticle[i].NumArticle){
                Res=0;
                if ((tabArticle[i].QuantiteDispo - Qte) <0) {
                    Res =2;
                }
            }
            i++;
        }
    }
    return Res;
}

void AfficheFacture(int max, S_ArticleChoisi Facture[])
{
    float Total = 0;
    cout << "=======================  FACTURE  =======================" << endl << endl;
    cout << "ARTICLE..........NBRE..........P-UNIT..........MONTANT..." << endl << endl;

    for ( int i=0; i < max ; i++) {
        cout << Facture[i].NomArticle << "............." << Facture[i].QuantiteVoulue << "............" << Facture[i].PrixU << "€.............." << Facture[i].PrixTotal << "€" << endl;
        Total = Total + Facture[i].PrixTotal;
    }
    cout << endl;
    cout << "             TOTAL                               " << Total << "€" << endl;
    cout << "=========================================================" << endl;
}

void Programme(int i, S_ArticleChoisi Save[], S_Article tabArticle[]){
    int Code;
    int Quantite;
    int ResultatRecherche;
    char Reponse;

    Menu(Code,Quantite);

    ResultatRecherche = RechercheArticle(Code,Quantite,tabArticle);

    //Gestion des erreurs

    if (ResultatRecherche==2) {
        //Pas de stock
        cout << "==============================" << endl;
        cerr <<'|' <<"[!] Pas assez de stock ! [!]" <<'|' << endl;
        cerr << "| Quantitée Disponible:     " << tabArticle[Code].QuantiteDispo << '|' <<endl;
        cout << "==============================" << endl << endl;
        cout << "Resaisir ? (O/N) (N affichera la facture): ";
        cin >> Reponse;
        if((Reponse == 'n') || (Reponse == 'N')){
            AfficheFacture(i,Save);
        }
        else
            Programme(i,Save,tabArticle);
    }
    if(ResultatRecherche==1){
        //Num article erroné
        cout << "================================" << endl;
        cerr << '|' <<"[!] Article inexistant ='( [!]" << '|' << endl;
        cout << "================================" << endl << endl;
        cout << "Resaisir ? (O/N): (N affichera la facture) ";
        cin >> Reponse;
        if((Reponse == 'n') || (Reponse == 'N')){
            AfficheFacture(i,Save);
        }
        else
            Programme(i,Save,tabArticle);
    }

    //Cas normal
    if (ResultatRecherche==0){
        Save[i].NumArticle = Code; // NumArticle
        Save[i].NomArticle = tabArticle[i].NomArticle; //NomArticle
        Save[i].PrixU = tabArticle[i].Prix; //PrixU
        Save[i].PrixTotal = Quantite*tabArticle[i].Prix; //PrixTotal
        Save[i].QuantiteVoulue = Quantite; //QuantiteVoulue
        i++;
        cout << "Continuer ?(O/N)" << endl;
        cin >> Reponse;

        if((Reponse == 'n') || (Reponse == 'N')){
            cout << "Valeur de i: " << i << endl;
            AfficheFacture(i,Save);
            //exit(0);
        }
        else
            Programme(i,Save,tabArticle);
    }

}

int main() {
    S_Article tabArticle[6];
    S_ArticleChoisi Save[6];

    Article(tabArticle);
    Programme(0, Save, tabArticle);
    return 0;
}
