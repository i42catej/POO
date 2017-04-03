/* 
 * File:   main.cpp
 * Author: Francisco
 *
 * Created on 3 de marzo de 2014, 17:37
 */

#include <cstdlib>
#include <iostream>
#include "Persona.h"
#include "PersonaUtil.h"

using namespace std;
using namespace PersonaUtil;


/*@brief Programa de prueba de módulos, espacios de nombres y memoria dinámica*/
int main(int argc, char** argv) {
    Persona pers("Maria","Garcia",11111,'A'), pers2;
    //Ejemplos de copia y asignación..... implementarlos  !!
    //Persona pers2(pers), pers3=pers;
    Persona pers1;
    Persona *v;
    int tam;
    
    
    pers.setNombre("Pepe");
    muestraPersonaPantalla(pers);
    muestraPersonaPantalla(pers2);

    leePersonaTeclado(pers);

    cout << "Introduce el número de personas: ";
    do {
        cin >> tam;
    } while (tam<=0);

    v=new Persona[tam];

    cout<<  "Leemos y visualizamos el vectorn";
    rellenaVector(v,tam);
    mostrarEnPantalla(v,tam);

    //Limpiar la casa!
    delete [] v;
    
    return 0;
}
