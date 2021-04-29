#pragma once
#include <iostream>
#include "Nodo.h"
#include "Persona.h"
using namespace std;

class Lista
{
private:
    Nodo *primerNodo;

public:
    Lista();
    int Index();
    bool EsVacio();
    Nodo *Iesimo(int);
    void Agregar(); //----------agregar alumno y  todos pues
    void Mostrar();
    void Eliminar(); //--- Falta implementar
    //Funciones de orfen superior
    //@@@Github
};

Lista::Lista()
{
    primerNodo = nullptr;
}
bool Lista::EsVacio()
{
    return primerNodo == nullptr;
}

int Lista::Index()
{
    if (EsVacio())
    {
        return -1;
    }
    else
    {
        Nodo *aux = primerNodo;
        int index = 0;
        while (aux->SiguienteNodo() != nullptr)
        { //Con esto llegamos hasta el ultimo nodo (antes del nullptr)
            index++;
            aux = aux->SiguienteNodo();
        }
        return index;
    }
}

Nodo *Lista::Iesimo(int index)
{
    if (EsVacio())
    {
        return nullptr;
    }
    else
    {
        Nodo *aux = primerNodo;
        for (int i = 0; i < index; i++)
        {
            aux = aux->SiguienteNodo();
        }
        return aux;
    }
}

void Lista::Agregar()
{
    Nodo *aux = primerNodo;
    //Input Persona
    Persona *dato = new Persona();
    dato->Leer();
    //Guarda Dato
    if (EsVacio())
    {
        primerNodo = new Nodo(dato);
    }
    else
    {
        aux = Iesimo(Index());
        Nodo *agregar = new Nodo(dato); //Nodo que se agregara
        aux->SiguienteNodo(agregar);
    }
    cout << "Persona registrada..." << endl;
}

void Lista::Mostrar()
{
    cout << "--- <<DATOS PERSONAS >> ---" << endl;
    if (EsVacio())
    {
        cout << "Ningun dato registrado hasta el momento." << endl;
    }
    else
    {
        Nodo *aux = primerNodo;
        Persona *auxPersona;
        while (aux != nullptr)
        {
            aux->GetPersona()->Mostrar();
            aux = aux->SiguienteNodo();
        }
    }
}

void Lista::Eliminar() //falta el caso donde no ubica a la persona
{
    if (EsVacio())
    {
        cout << "Lista vacia..." << endl;
    }
    else
    {
        Nodo *aux = primerNodo;
        string dni;
        cout << "Ingrese DNI a eliminar: ";
        cin >> dni;
        if (primerNodo->GetPersona()->GetDni() == dni)
        {
            primerNodo = primerNodo->SiguienteNodo();
        }
        else
        {
            while (aux->SiguienteNodo() != nullptr) //talvez  es mejor con dowhile
            {
                if (aux->SiguienteNodo()->GetPersona()->GetDni() == dni)
                {
                    aux->SiguienteNodo(aux->SiguienteNodo()->SiguienteNodo());
                    break;
                }
                aux = aux->SiguienteNodo();
            }
        }
        cout << "elimindado" << endl;
    }
}
