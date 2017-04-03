/** @brief Implementación de la clase Producto
 * @file   Producto.cpp
 * @author jrbalsas@ujaen.es
 */

#include "Producto.h"

#include <iostream>
using namespace std;

int Producto::ID=0;

Producto::Producto()
                :id(ID),nombre("Producto desconocido"),pvp(0)
{
    ID++;
    cout << "Creando producto "<<id<<endl;
}


Producto::Producto(const Producto& orig)
                :id(ID),nombre(orig.nombre),pvp(orig.pvp)
{
    ID++;
    cout << "Copiando nuevo producto "<<id<<endl;
}

Producto::~Producto() {
    cout << "Se esta destruyendo el producto: "<<id<<endl;
}

void Producto::SetPvp(float pvp) {
    this->pvp = pvp;
}

float Producto::GetPvp() const {
    return pvp;
}

void Producto::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Producto::GetNombre() const {
    return nombre;
}

void Producto::SetId(int id) {
    this->id = id;
}

int Producto::GetId() const {
    return id;
}
