/** @brief Implementación de la clase persona
 * @file   Persona.cpp
 */

#include "Persona.h"
#include <iostream>
#include <sstream>

using namespace std;

//Inicializamos contador de personas
int Persona::ID=0;

/**@brief Constructor por defecto*/
Persona::Persona(string nnombre, string napellidos,string ndni)
        :id(ID),nombre(nnombre),apellidos(napellidos),dni(ndni),edad(0)
        //constructor por defecto de fNacimiento
        //Inicializamos a 0 punteros a fechas de Alta y Baja
         ,fNacimiento(),fAlta(0),fBaja(0)
{
    ID++; //Incrementamos el contador global de personas
    cout << "Se esta creando la persona "<<id<<" "+nombre<<endl;
}

/**@brief Constructor de copia*/
Persona::Persona(const Persona &orig)
        :id(ID),nombre(orig.nombre),apellidos(orig.apellidos),dni(orig.dni)
        ,edad(orig.edad), fNacimiento(orig.fNacimiento)
{
    ID++;//Una copia
    cout << "Se esta copiando a "+orig.nombre+" con nuevo id "<< id <<endl;
    //Debemos copiar las fechas de alta y baja si existen en orig
    //Si las asignamos. p.e. fAlta(orig.fAlta) ambos objetos apuntarían a la misma fecha de alta!
    if (orig.fAlta!=0)
        //Constructor de copia de fecha para el objeto fecha apuntado por orig.fAlta
        fAlta=new Fecha(*orig.fAlta);
    if (orig.fBaja!=0)
        //Constructor de copia de fecha para el objeto fecha apuntado por orig.fAlta
        fBaja=new Fecha(*orig.fBaja);
}
Persona::~Persona() {
    cout << "Se esta destruyendo a "+nombre+" con id "<<id<<endl;
    //Liberamos la memoria de los objetos apuntados por fAlta y fBaja si están asignados
    //Si fAlta o fBaja apuntan a 0, delete no hace nada
    delete fAlta;
    delete fBaja;
}

void Persona::setNombre(string nnombre) {
    nombre=nnombre;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setDni(string dni) {
    this->dni = dni;
}

string Persona::getDni() const {
    return dni;
}

void Persona::setApellidos(string apellidos) {
    this->apellidos = apellidos;
}

string Persona::getApellidos() const {
    return apellidos;
}

string Persona::getNombre() const {
    return nombre;
}

void Persona::setFNacimiento(const Fecha& fNacimiento) {
    this->fNacimiento = fNacimiento;
}

Fecha Persona::getFNacimiento() const {
    return fNacimiento;
}

void Persona::setFAlta(Fecha* fAlta) {
    this->fAlta = fAlta;
}

Fecha* Persona::getFAlta() const {
    return fAlta;
}

int Persona::getId() const {
    return id;
}

string Persona::toCSV() const {
    string cadena;
    stringstream ss;
    
    ss<<nombre<<";"<<apellidos<<";"<<dni<<";"<<edad;

    //ss>>cadena; No lee espacios en blanco
    getline(ss,cadena);
    
    return cadena;
}

void Persona::fromCSV(string cadena) {
    stringstream ss;
    
    ss<<cadena;

    getline(ss,nombre,';');
    getline(ss,apellidos,';');
    getline(ss,dni,';');
    ss>>edad;
}
