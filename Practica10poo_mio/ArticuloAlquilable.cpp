/*
 * File:   ArticuloAlquilable.cpp
 * Author: admin
 *
 * Created on 25 de abril de 2014, 18:18
 */

#include "ArticuloAlquilable.h"
#include "Articulo.h"
#include "Servicio.h"

ArticuloAlquilable::ArticuloAlquilable() {
}

ArticuloAlquilable::ArticuloAlquilable(int id, float pvp, string nom,float p, int uni, int hor, string desc):
    Producto(id,nom, pvp),Articulo(id, pvp,nom, p,uni),Servicio(id, pvp,nom, hor, desc)
    //OJO HAY QUE LLAMAR tb al Constructor de la clase Ancestro Comun
    {
    cout<<"Creando articulo alquilable"<<endl;
}

ArticuloAlquilable::ArticuloAlquilable(const ArticuloAlquilable& orig) {
}

ArticuloAlquilable::~ArticuloAlquilable() {
}

float ArticuloAlquilable:: GetCoste() const{

    return  Articulo::GetCoste() * Servicio::GetHoras();
}
