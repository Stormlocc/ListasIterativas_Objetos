#pragma once
#include "Persona.h"
#include <iostream>
using namespace std;

class Alumno : public Persona
{
private:
    string escuela;

public:
    Alumno();
    Alumno(string, string, string);
    void Leer() override;
    void Mostrar() override;
};

Alumno::Alumno()
    : Persona()
{
    escuela = "no definido";
}

Alumno::Alumno(string _nombre, string _dni, string _escuela)
    : Persona(_nombre, _dni)
{
    escuela = _escuela;
}

void Alumno::Leer()
{
    cout << "========================================" << endl;
    cout << "======---LEER INFORM DE ALUMNO----======" << endl;
    cout << "========================================" << endl;
    Persona::LeerDatos();
    cout << "Escuela: ";
    cin >> escuela;
}

void Alumno::Mostrar()
{
    Persona::Mostrar();
    cout << "Escuela: " << escuela << endl;
}
