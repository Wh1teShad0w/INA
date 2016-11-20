#include "new_class.h"
#include <string>

using namespace std;

new_class::new_class(): m_lol(12)
{
    string m_nom;
    int m_age;
}

new_class::new_class(string m_habit): m_nature("")
{
    string m_nom;
    int m_age;
}

new_class::~new_class()
{

}
//Methodes de la classe, a Implementer:

void new_class::manger(string nouriture){
    cout<<this->nom<<" vient de manger: "<<nouriture<<endl;
}
