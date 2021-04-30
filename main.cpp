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
            cout<< "Longitud de lista: "<< listaa->Index()+1<< endl;
            break;
        case 3:
            listaa->Mostrar();
            break;
        case 4:
            listaa->Eliminar();
            break;
        case 5:
            Nodo *aux1 = listaa->Ubicar();
            if(aux1 == nullptr)
                cout<<"no ubicado"<<endl;
            else
                aux1->GetPersona()->Mostrar();
            delete(aux1);
            break;
        }
    } while (opcion < 6);
    
    cout<<"FIN DEPROGRAMA /t /t version 1.0"<<endl;
    return 0;

    /*
    @Stormlocc date: 4/30/21
    *mejorar sacando los input de "Lista.h" y mandando desde el main salu2
    */
}

