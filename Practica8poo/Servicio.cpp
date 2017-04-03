/*
 * File:   Servicio.cpp
 * Author: admin
 *
 * Created on 25 de abril de 2014, 18:07
 */

#include "Servicio.h"
#include "Producto.h"

Servicio::Servicio() {
}

Servicio::Servicio(int id, float pvp, string nom, int horas, string desc):
        Producto(id,nom,pvp), horas(horas), descripcion(desc){

    cout<<"Creando servicio con nombre "<<nom<<endl;
}

Servicio::Servicio(const Servicio& orig) {
}

Servicio::~Servicio() {
}

void Servicio::SetDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Servicio::GetDescripcion() const {
    return descripcion;
}

void Servicio::SetHoras(int horas) {
    this->horas = horas;
}

int Servicio::GetHoras() const {
    return horas;
}

float Servicio::GetCoste() const{
    return horas * Producto::GetPvp();
}

