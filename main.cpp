#include <iostream>
#include "Lista.h"
using namespace std;

//Menu
static void Menu(){
    cout<<"1) Agregar Persona"<<endl;
    cout<<"2) Agregar Alumno"<<endl;
    cout<<"3) Agregar Docente"<<endl;
    cout<<"4) Longitud de Lista"<<endl;
    cout<<"5) Mostra Lista"<<endl;
    cout<<"6) Eliminar Dato"<<endl;
    cout<<"7) Salir"<<endl;
}

int main(){

    cout<<"<<<<<<<<<< PROGRAMA GESTION DE ALUMNOS EN C++ >>>>>>>>>>>"<<endl;

    //Intanciado Lista iterativa
    Lista *listaa = new Lista();
    int opcion;
    //Tener datos ya registrados

    //..........


    //Ejecucion de programa
    do
    {
        Menu();
        //input opcion
        cout<<"Elija su opcion: ";
        cin>>opcion;
        cin.ignore();
        //Switch cases
        switch (opcion)
        {
        case 1:
            listaa->Agregar();
            break;
        case 4:
            cout<< "Longitud de lista: "<< listaa->Index()+1 << endl;
            break;
        case 5:
            listaa->Mostrar();
            break;
        case 6:
            listaa->Eliminar();
            break;
        default:
            break;
        }
    } while (opcion < 7);
    
    cout<<"FIN DEPROGRAMA"<<endl;
    return 0;
}

