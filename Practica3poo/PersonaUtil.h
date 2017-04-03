/* 
 * File:   PersonaUtil.h
 * Author: Francisco
 *
 * Created on 3 de marzo de 2014, 17:53
 */

#ifndef PERSONAUTIL_H
#define	PERSONAUTIL_H
#include <iostream>
#include <string>
#include "Persona.h"

using namespace std;

namespace PersonaUtil{
    
  
    void leePersonaTeclado(Persona &p);
    void muestraPersonaPantalla(const Persona &p);

    int rellenaVector(Persona vp[], int max);
    void mostrarEnPantalla(const Persona vp[], int tama);

    int buscar(const string &ape, const Persona vp[], int tama);
   
    void ordenar(Persona *vp, int tama);
    
    void muestra(const Persona &p);
};



#endif	/* PERSONAUTIL_H */

