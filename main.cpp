#include <iostream>
#include "Lista.h"
using namespace std;

int main(){
    cout<<"<<<<<<<<<< PROGRAMA GESTION DE ALUMNOS EN C++ >>>>>>>>>>>"<<endl;

    
    Lista *listaa = new Lista();


    listaa->Agregar();
    cout<< "Index: " << listaa->Index()<<endl;
    listaa->Agregar();
    cout<< "Index: " << listaa->Index()<<endl;
    listaa->Agregar();
    cout<< "Index: " << listaa->Index()<<endl;


    listaa->Mostrar();

    cout<<"FIN DEPROGRAMA"<<endl;
    return 0;
}

