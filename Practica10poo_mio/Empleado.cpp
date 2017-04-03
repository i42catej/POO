/** @brief Implementación de la clase Empleado
 * @file   Empleado.cpp
 * @author jrbalsas@ujaen.es
 */
#include "Empleado.h"

Empleado::Empleado(string nnombre, string napellidos ,string ndni,float salario):
          Persona(nnombre,napellidos,ndni),salario(salario) {

}

Empleado::Empleado(const Empleado& orig):Persona(orig),salario(orig.salario) {
}


Empleado::~Empleado() {
}

void Empleado::setSalario(float salario) {
    if (salario<600)
        salario=600;
    this->salario = salario;
}

float Empleado::getSalario() const {
      return salario;
}

string Empleado::toCSV() {
    string cadena;
    stringstream ss;
                                                        /** ¡¡IMPORTANTE EXAMEN!!*/
    ss<< getNombre()<<";"<< getApellidos()<<";"<< getDni()<<";"<< salario <<";"<<getEdad();

    //ss>>cadena; No lee espacios en blanco
    getline(ss,cadena);

    return cadena;
}

void Empleado::fromCSV(string cadena) {
    stringstream ss;
    string cad; int e;
    float s;
    ss<<cadena;

    getline(ss,cad,';');
    setNombre(cad);
    getline(ss,cad,';');
    setApellidos(cad);
    getline(ss,cad,';');
    setDni(cad);
    ss>>s;
    salario=s;   /** ¡¡IMPORTANTE EXAMEN!!*/
    ss>>e;
    setEdad(e);
}
