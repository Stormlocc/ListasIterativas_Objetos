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
    bool EsVacio();
    int Index();
    Nodo *Iesimo(int); //agregar parametros
    void Procesar(void (*function)(Nodo *));
    void AgregarPersona(Persona *);
    void AgregarAlumno(Alumno *);
    void AgregarDocente(Docente *);
    Nodo *Ubicar(string *);
    void Mostrar();
    void Eliminar(string *);

    //Funciones de orfen superior
    //@@@Github
};

Lista::Lista()
{
    primerNodo = nullptr;
    /*
    */
    //Apartir de aqui elimnar n filas (datos para probar)
    Persona *p1 = new Persona("juanito", "111");
    Persona *p2 = new Persona("pepito", "222");
    Alumno *a1 = new Alumno("anthony", "333", "info");
    Alumno *a2 = new Alumno("diana", "444", "info");
    Docente *d1 = new Docente("armando", "555", "matematica");
    Docente *d2 = new Docente("angelica", "666", "religion");
    //Crear nodo donde agregaremos
    Nodo *n6 = new Nodo(d2);
    Nodo *n5 = new Nodo(d1, n6);
    Nodo *n4 = new Nodo(a2, n5);
    Nodo *n3 = new Nodo(a1, n4);
    Nodo *n2 = new Nodo(p2, n3);
    Nodo *n1 = new Nodo(p1, n2);

    primerNodo = n1;
}

bool Lista::EsVacio()
{
    return primerNodo == nullptr;
}

void Lista::AgregarPersona(Persona *dato)
{
    Nodo *aux = primerNodo;
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

void Lista::AgregarAlumno(Alumno *dato)
{
    Nodo *aux = primerNodo;
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

void Lista::AgregarDocente(Docente *dato)
{
    Nodo *aux = primerNodo;
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

void Lista::Procesar(void (*function)(Nodo *per) = nullptr)
{
    Nodo *aux = primerNodo;
    while (aux != nullptr)
    {
        if (function != nullptr)
            function(aux);
        else
            aux->GetPersona()->Mostrar();
        aux = aux->SiguienteNodo();
    }
}
//Al ejecutar el programa y ubicar un dni no agregado ocurre un bug
Nodo *Lista::Ubicar(string *pDni)
{
    static Nodo *encontrado;
    static string *auxDni = pDni;
    cout<<"buscanod el dni ::::: " << *auxDni<<endl;
    Procesar([](Nodo *p) {
        if (p->GetPersona()->GetDni() == *auxDni){
            encontrado = p;
        }
    });
    //Las sgtes lineas de verificar (no deberia ser necesario) lo pregunte aqui
    //https://es.stackoverflow.com/questions/448672/static-no-se-actualiza
    if(encontrado->GetPersona()->GetDni() == *pDni)
        return encontrado ;//verificar que en realidad se encontro y no es el guarado
    else
        return nullptr;
}

int Lista::Index()
{
    if (EsVacio())
        return -1;
    else
    {
        static int index = -1;
        Procesar([](Nodo *p) { index++; });
        int iindex = index;
        index = -1; //reiniciar index--->>
        return iindex;
    }
}

Nodo *Lista::Iesimo(int index)
{
    if (EsVacio() || index < 0 || index > Index())
        return nullptr;
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
        cout << "Ningun dato registrado hasta el momento." << endl;
    else
    {
        Procesar();
    }
}

void Lista::Eliminar(string *dni) //falta mostrar no ubica a la persona
{
    if (EsVacio())
    {
        cout << "Lista vacia..." << endl;
    }
    else
    {
        Nodo *aux = primerNodo;
        
        //Caso ah eliminar ??
        if (primerNodo->GetPersona()->GetDni() == *dni)
        {
            primerNodo = primerNodo->SiguienteNodo();
            cout << "eliminado exitosamente...." << endl;
        }
        else
        {
            while (aux->SiguienteNodo() != nullptr)
            {
                if (aux->SiguienteNodo()->GetPersona()->GetDni() == *dni)
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

//@@github 4/30/2021 00:55
