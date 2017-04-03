/*
 * File:   Servicio.h
 * Author: admin
 *
 * Created on 25 de abril de 2014, 18:07
 */

#ifndef SERVICIO_H
#define	SERVICIO_H
#include <iostream>
#include "Producto.h"

using namespace std;

class Servicio: virtual public Producto{

    private:

        int horas;
        string descripcion;
public:
    Servicio();
    Servicio(int id, float pvpUnitario, string nombre, int horas=0, string descripcion="");
    Servicio(const Servicio& orig);
    virtual ~Servicio();
    void SetDescripcion(string descripcion);
    string GetDescripcion() const;
    void SetHoras(int horas);
    int GetHoras() const;
    virtual float GetCoste() const;


};

#endif	/* SERVICIO_H */

