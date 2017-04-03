/** @brief Implementación de la clase Cliente
 * @file   Cliente.cpp
 * @author jrbalsas@ujaen.es
 */

#include "Cliente.h"

Cliente::Cliente(string nnombre, string napellidos ,string ndni,string direccion):
          Persona(nnombre,napellidos,ndni),direccion(direccion) {

}

Cliente::Cliente(const Cliente& orig):Persona(orig),direccion(orig.direccion) {
}

Cliente::~Cliente() {
}

void Cliente::SetDireccion(string direccion) {
    this->direccion = direccion;
}

string Cliente::GetDireccion() const {
    return direccion;
}

string Cliente::toCSV() {
    string cadena;
    stringstream ss;
                                                            /** ¡¡IMPORTANTE EXAMEN!!*/
    ss<< getNombre()<<";"<< getApellidos()<<";"<< getDni()<<";"<< direccion <<";"<<getEdad();

    //ss>>cadena; No lee espacios en blanco
    getline(ss,cadena);

    return cadena;
}

void Cliente::fromCSV(string cadena) {
    stringstream ss;
    string cad; int e;
    ss<<cadena;

    getline(ss,cad,';');
    setNombre(cad);
    getline(ss,cad,';');
    setApellidos(cad);
    getline(ss,cad,';');
    setDni(cad);
    getline(ss,cad,';');
    SetDireccion(cad);    /** ¡¡IMPORTANTE EXAMEN!!*/
    ss>>e;
    setEdad(e);
}
