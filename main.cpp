#include <iostream>
#include "Lista.h"
using namespace std;

//Menu
static void Menu(){
    cout<<"1) Agregar"<<endl;
    cout<<"2) Longitud de Lista"<<endl;
    cout<<"3) Mostra Lista"<<endl;
    cout<<"4) Eliminar Dato"<<endl;
    cout<<"5) Ubicar persona"<<endl;
    cout<<"6) Salir"<<endl;
}

static void MenuPersonas(){
    cout << "++++++++++++++++ TIPO DE PERSONA ++++++++++++++++++++" << endl;
    cout << "1) Persona" << endl;
    cout << "2) Alumno" << endl;
    cout << "3) Docente" << endl;
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
            MenuPersonas();
            cout<<"Ingrese su opcion: ";
            cin>> opcion;
            cin.ignore();
            if(opcion == 1)
                listaa->AgregarPersona();
            else if (opcion == 2)
            {
                listaa->AgregarAlumno();
            }
            else if (opcion == 3 )
            {
                listaa->AgregarDocente();
            }
            else
                cout<<"Eleccion incorrecta"<<endl;
            opcion = 0;
            break;
        case 2:
            cout<< "Longitud de lista: "<< listaa->Index()+1 << endl;
            break;
        case 3:
            listaa->Mostrar();
            break;
        case 4:
            listaa->Eliminar();
            break;
        case 5:
            listaa->Iesimo(1)->GetPersona()->Mostrar();
            break;
        default:
            break;
        }
    } while (opcion < 6);
    
    cout<<"FIN DEPROGRAMA"<<endl;
    return 0;
}

