#pragma once
#include "Persona.h"

class Nodo
{
private:                

    Persona *person;
    Nodo *siguiente;

public:
    Nodo();
    Nodo(Persona*);
    Nodo(Persona*,Nodo*);
    ~Nodo();
    //Propiedades de Persona
    void SetPersona(Persona*);
    Persona *GetPersona();   
    void SiguienteNodo(Nodo*);
    Nodo *SiguienteNodo();
};

Nodo::Nodo(/* args */)
{
    person = nullptr;
    siguiente = nullptr;
}
Nodo::Nodo(Persona *nuevo)
{
    person = nuevo;
    siguiente = nullptr;
}
Nodo::Nodo(Persona *nuevo,Nodo *sgteNodo)
{
    person = nuevo;
    siguiente = sgteNodo;
}

void Nodo:: SetPersona(Persona *nuevo){
    person = nuevo;
}

Persona *Nodo::GetPersona(){
    return person;
}

void Nodo::SiguienteNodo(Nodo *nuevo){
    siguiente = nuevo;
}

Nodo *Nodo::SiguienteNodo(){
    return siguiente;
}

Nodo::~Nodo()
{
}


