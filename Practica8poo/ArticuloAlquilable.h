/*
 * File:   ArticuloAlquilable.h
 * Author: admin
 *
 * Created on 25 de abril de 2014, 18:18
 */

#ifndef ARTICULOALQUILABLE_H
#define	ARTICULOALQUILABLE_H
#include <iostream>
#include "Articulo.h"
#include "Servicio.h"

using namespace std;

class ArticuloAlquilable: public Articulo, public Servicio{

    private:



    public:
    ArticuloAlquilable();
    ArticuloAlquilable(int id, float pvpUnitario, string nombre,float peso, int unidadesEnvase, int horas, string descripcion);
    ArticuloAlquilable(const ArticuloAlquilable& orig);
    virtual ~ArticuloAlquilable();
    virtual float GetCoste() const;


};

#endif	/* ARTICULOALQUILABLE_H */

