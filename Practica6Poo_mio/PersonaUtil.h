/**
 * @file   PersonaUtil.h
 */

#ifndef PERSONAUTIL_H
#define	PERSONAUTIL_H

#include <string>
#include "Persona.h"

using namespace std;

namespace PersonaUtil {

    void visualiza(const Persona &p);
    void visualiza(const Persona *p);
    void visualiza(const Persona v[], int tam);
    void lee(Persona &p);
    void lee(Persona *p);
    void lee(Persona v[], int tam);
    void guardaCSV(const Persona v[], int tam,string archivo);
    int recuperaCSV(Persona v[], int tam,string archivo);

};

#endif	/* PERSONA_H */

