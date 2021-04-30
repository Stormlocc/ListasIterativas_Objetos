#pragma once
#include <iostream>
#include "Nodo.h"
#include "Persona.h"
#include "Alumno.h"
#include "Docente.h"
using namespace std;

class Lista
{
private:
    Nodo *primerNodo;

public:
    Lista();
    int Index();
    bool EsVacio();
    Nodo *Iesimo(int);//agregar parametros
    void Recorrer(void *function(Nodo *));
    void AgregarPersona();
    void AgregarAlumno();
    void AgregarDocente();
    void Mostrar();
    void Eliminar();

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

void Lista::AgregarPersona()
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

void Lista::AgregarAlumno()
{
    Nodo *aux = primerNodo;
    //Input Persona
    Alumno *dato = new Alumno();
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
    cout << "Alumno registrado..." << endl;
}

void Lista::AgregarDocente()
{
    Nodo *aux = primerNodo;
    //Input Persona
    Docente *dato = new Docente();
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
    cout << "Docente registrado..." << endl;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void Lista::Recorrer(void * function(Nodo *a) = nullptr){
    Nodo *aux= primerNodo;
    while(aux->SiguienteNodo() != nullptr){
        if(function != nullptr)
            function(aux);
        aux = aux->SiguienteNodo();
    }
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
    if (EsVacio() || index < 0 || index > Index())
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
        while (aux != nullptr)
        {
            aux->GetPersona()->Mostrar();//no es necesario mutar xq entra directamente a la memoria guarada? creo
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
        //input dato
        string dni;
        cout << "Ingrese DNI a eliminar: ";
        cin >> dni;
        //Caso ah eliminar á
        if (primerNodo->GetPersona()->GetDni() == dni)
        {
            primerNodo = primerNodo->SiguienteNodo();
        }
        else
        {
            while (aux->SiguienteNodo() != nullptr)
            {
                if (aux->SiguienteNodo()->GetPersona()->GetDni() == dni)
                {
                    aux->SiguienteNodo(aux->SiguienteNodo()->SiguienteNodo());
                    cout << "eliminado exitosamente...." << endl;
                    break;
                }
                aux = aux->SiguienteNodo();
            }
        }
    }
}
