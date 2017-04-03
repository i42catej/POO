/**@brief Funciones E/S para objetos Persona
 * @file   PersonaUtil.h
 * @author jrbalsas@ujaen.es
 * @date Created on 11 de febrero de 2013, 11:44
 */

#ifndef PERSONAUTIL_H
#define	PERSONAUTIL_H

#include <string>
#include "Persona.h"
#include "itemCSV.h"   /** ¡¡IMPORTANTE EXAMEN!!*/

using namespace std;

/**@brief Funciones E/S Personas*/
namespace PersonaUtil {

    void visualiza(const Persona &p);
    void visualiza(const Persona *p);
    void visualiza(const Persona v[], int tam);
    void visualiza(Persona* *v, int tam);
    void lee(Persona &p);
    void lee(Persona *p);
    void lee(Persona v[], int tam);
    void guardaCSV( itemCSV *v[], int tam,string archivo);   /** ¡¡IMPORTANTE EXAMEN!!*/
    int recuperaCSV(Persona v[], int tam,string archivo);

};

#endif	/* PERSONA_H */
