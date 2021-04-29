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
    void Agregar();
    void Mostrar();
    void Eliminar(int);//--- Falta implementar
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
        {//Con esto llegamos hasta el ultimo nodo (antes del nullptr)
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
    Nodo *aux = primerNodo;
    Persona *auxPersona;
    while (aux != nullptr)
    {
        //auxPersona = aux->GetPersona();
        //auxPersona->Mostrar();
        aux->GetPersona()->Mostrar();
        aux = aux->SiguienteNodo();
    }
}
