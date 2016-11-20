//Pour l'instant ce fichier ne m'aide pas, g gere tt en python


/*
#include <qapplication.h>
#include <QFont>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");

    quit.resize(75, 30);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

    quit.show();

    return app.exec();
}
*/

//#include <QCoreApplication>
#include <iostream>
#include <string>
//Pour des operations de mathematik #include <cmath>
#define LOLI 23
#include "include.h"
#include <vector>
#include <fstream>
//#include <ctime>
//#include <cstdlib>
//srand(time(0));
// nbre= rand()%5// 5 etant un nombre ki devrai etre pris o hazard mais constant

using namespace std;

struct Lolo{
  float taille;
  string couleur;
  string type;
};

int main(){

    //QCoreApplication a();

    //Test de Flux
    cout<<"Creation de Flux...";
    //string const file("log.txt");
    ofstream flux_fichier("log.txt",ios::app);//pour ajouter apres
    if(flux_fichier){
        cout<<"Creation avec success du fichier test...."<<endl;
        string motSecret("");
        cout<<"Quel phrase secrete voullez vous enregistrer?\n Phrase:";
        //cin>>motSecret;
        //cin.ignore();
        getline(cin,motSecret);
        flux_fichier<<endl<<motSecret;
        cout<<"\nMessage ecrit avec success"<<endl;

        cout<<"Voullez vous lire le fichier?(o/n):";
        char r;
        cin>>r;
        if(r=='o' || r=='O'){
            ifstream flux_lire("log.txt");
            if(flux_lire){
                cout<<"\nFichier parfaitement ouvert en lecture:\n\n";
                string ligne;
                while(getline(flux_lire,ligne)){
                    cout<<ligne<<endl;
                }
                cout<<endl<<endl;
            }

        }else if(r=='n' || r=='N'){
            cout<<"Ok, pas grave de refuser,,,";
        }
        else{
            cout<<"Lecture du fichier impossible!!";
        }
    }else{
        cout<<"Erreur de la creation du fichier test...";
    }

    cout <<"Initialisation..."<<endl;
    vector<int> tab(4);
    tab[0]=1;
    cout<<"\n val0:"<<tab[0];
    cout<<"\n val1:"<<tab[1];
    cout<<"\n val2:"<<tab[2];
    cout<<"\n val3:"<<tab[3];
    tab.push_back(9);//On vien d faire un push en ajoutant une valeur a la fin du tablo
    cout<<"\n val4:"<<tab[4]<<endl;


    //nian way to use for
    cout <<"Combien de valeurs veux tu entrer!??:";
    int n(0);
    cin>>n;
    for(int i(0); i<n; i++){
        cout<<"Valeur"<<i<<endl;
    }
    cout<<"Et hop laaa!!";

    //Le terrible probleme des espaces dans le string
    string nom;char s;int ag;
    cout<<"ton sexe(M/F):";
    cin>>s;
    //tres tres utile
    cin.ignore();

    cout <<"Ton nom:";
   // au lieu de cin>> nom;
    getline(cin,nom);
    cout<<"\n Age:";
    cin>> ag;
    sex(s);
    cout<<nom<<" ;vous avez:"<<ag<<" ans"<<endl;
    */



    //Encore des references, mais en plus cool
    int lolos(0);// Tres tres important
    int& referenceLolos(lolos);

    cout<< "LOLO: "<<lolos<<"\nCreation de la reference oKK!!: "<< referenceLolos<<endl;


    //Petits details oublies dans le dev C++
    int lolo(5);
    cout<< " Valeur de lol: "<<lolo<<endl<<" Valeur de son adresse: "<<&lolo<<endl;
    int *poin=&lolo;
    cout<< "\n Pointeur: "<<poin<<"\n Valeur liant o pointeur:"<<*poin<<endl;

    //Acceleration de l'execution d'une fonction
    double dd;
    cout<<"Trouvez le double d'1 nombre:";
    cin>>dd;
    doubl(dd);

    //Principe de la surchage:
    lol();
    lol("S@n1X");

    //Utilisation des references
    int ag=5;
    int &R_ag=ag;
    cout <<"ag vaut:"<< ag<<" et R_ag vaut:" <<R_ag <<endl;
    cout<< "nouvelle valeur de ag:";
    cin>>ag;
    R_ag=15;
    cout <<"ag vaut:"<< ag<<" et R_ag vaut:" <<R_ag <<endl;
    //Etttt ouais, ag conserve le 15 de sa reference!!!

    //utilisation de l'allocation memoire
    int *alloc =NULL;
    alloc=new int[20];
    cout<<"Allocation memoire effectuee\n";
    system("PAUSE");
    delete alloc;
    cout<<"Desalocation memoire effectuee\n";
    */

    /*Gerence des fichiers, ou du moins en C
    FILE*init=NULL;
    init=fopen("C:\\Users\\admin\\Documents\\nica\\init.n","a");
    if(init!=NULL){
        //fichier existant on begin!
        cout<<"Creation du fichier init ok\n";
    }else{
        cout<<"Probleme de creation du fichier init\n";
    }
    fclose(init);
    */

    /*
    string l;char again;int age;

    struct Lolo L1;
    L1.taille=23;
    L1.couleur="Tres Jaune";
    L1.type="plutot long";

    cout<< "--NICA Chargement des elements..."<<endl;
    cout<<"N_:"; cin>> l;

    deb: system("cls");
    cout << "Bienvenue: "<< l<< endl;

    cout<<"Ton age stp:";
    cin>>age;
    verifAge(age);

    cout<<"Encore!? y/n:";

    cin>>again;
    if(again=='y'){
        goto deb;
    }
    */
    //return a.exec();
    return 0;
}

void verifAge(float age){
  if(age<12){
      cout<<"Trop mineur, go kass!!!\n";
  }
  else{
      if(age>13 && age<16){
          cout<< "Xa peut aller\n";
      }
      else{
          cout<<"C'est parfait, tu es tres agee!!!\n";
      }
  }
}
/*
void lol(){
    cout <<"lol\n";
}
void lol(string nom){
    cout<<"lol: "<<nom<<endl;
}
*/
void doubl(double nombre){
    cout<<"\n\t Le double de ce nombre est"<<(nombre*2)<<"\n";
}
void sex(char s){
    if(s=='M' || s=='m')
        cout<<"Monsieur: ";
    else if(s=='F' || s=='f')
        cout<<"Madame: ";
    else
        cout<<"t'es mm ki?:";
}
