/*
 * File:   Articulo.h
 * Author: admin
 *
 * Created on 25 de abril de 2014, 17:47
 */

#ifndef ARTICULO_H
#define	ARTICULO_H
#include <iostream>
#include "Producto.h"

using namespace std;

class Articulo: virtual public Producto {
    private:
        float peso;
        int unidadesEnvase;
    public:
    Articulo();
    Articulo(int id, float pvpUnitario, string nombre, float peso=0, int unidadesEnvase=0);
    Articulo(const Articulo& orig);
    virtual ~Articulo();
    void SetUnidadesEnvase(int unidadesEnvase);
    int GetUnidadesEnvase() const;
    void SetPeso(float peso);
    float GetPeso() const;

    virtual float GetCoste() const;    /** ¡¡IMPORTANTE EXAMEN!!*/

};

#endif	/* ARTICULO_H */

