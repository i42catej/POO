/*
 * File:   Articulo.cpp
 * Author: admin
 *
 * Created on 25 de abril de 2014, 17:47
 */

#include "Articulo.h"
#include "Producto.h"

using namespace std;

Articulo::Articulo() {
}

Articulo::Articulo(int id, float pvp, string nom, float p, int uniEnv):
       Producto(id,nom, pvp), peso(p), unidadesEnvase(uniEnv){

    cout<<"Creando articulo con nombre "<<nom<<endl;;
}

Articulo::Articulo(const Articulo& orig) {
}

Articulo::~Articulo() {
}

void Articulo::SetUnidadesEnvase(int unidadesEnvase) {
    this->unidadesEnvase = unidadesEnvase;
}

int Articulo::GetUnidadesEnvase() const {
    return unidadesEnvase;
}

void Articulo::SetPeso(float peso) {
    this->peso = peso;
}

float Articulo::GetPeso() const {
    return peso;
}

float Articulo::GetCoste() const {
    if(peso==0){
        return (unidadesEnvase * Producto::GetPvp());
    }else{ return (peso * Producto::GetPvp());}
}
