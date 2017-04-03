/** @brief Utilidades para trabajar con objetos de la clase Persona
 * @file   PersonaUtil.cpp
 * @author jrbalsas@ujaen.es
 * @date Created on 11 de febrero de 2013, 11:44
 */

#include <typeinfo>    /** ¡¡IMPORTANTE EXAMEN!!*/
#include "PersonaUtil.h"
#include "Cliente.h"    /** ¡¡IMPORTANTE EXAMEN!!*/

#include <iostream>
#include <fstream>

using namespace PersonaUtil;

/** @brief Lee por teclado una persona
 * @param p el registro persona a modificar (modifica)
 * @pre   no tiene
 * @post  Lee por teclado los datos de una persona. Si algún dato no es correcto
 *        vuelve a pedirlo:
 *        - nombre: longitud entre 3 y 50
 *        - apellidos: ...
 */
void PersonaUtil::lee(Persona &p) {
    string cadena;
    int valor;
    do {
        cout << "Dime el nombre ";
        cin >> cadena;
    } while (cadena.length()<3 || cadena.length()>50);
    p.setNombre(cadena);
    cout << "Dime los apellidos ";
    cin >> cadena;
    p.setApellidos(cadena);
    cout << "Dime el dni ";
    cin >> cadena;
    p.setDni(cadena);
    cout << "Dime la  edad ";
    cin >> valor;
    p.setEdad(valor);
}
/** @brief Lee por teclado una persona
 * @param p puntero a un registro persona a modificar (modifica)
 * @pre   p debe apuntar a un registro Persona inicializado
 * @post  Lee por teclado los datos de una persona. Si algún dato no es correcto
 *        vuelve a pedirlo:
 *        - nombre: longitud entre 3 y 50
 *        - apellidos: ...
 */
void PersonaUtil::lee(Persona *p) {
    lee(*p);
    //También accediendo a métodos de p usando: p->setNombre(cadena)...
}
/**@post lee por teclado los datos de tam personas y las coloca en las primeras posiciones de v
 */
void PersonaUtil::lee(Persona v[], int tam) {
    //El identificador no tiene conflicto con las anteriores funciones visualiza
    //por estar sobrecargado
    for (int i = 0; i < tam; i++) {
        cout << "Persona "<<i<<endl;
        lee(v[i]); //leemos una persona por teclado
    }
}

/**@post Visualiza en la consola de texto y en una línea los datos de una Persona
 */
void PersonaUtil::visualiza(const Persona &p) {
     cout << p.getNombre()+" "+p.getApellidos() << " ("+p.getDni()+") "<<p.getEdad()<<" años"<<endl;
}
/**@post Visualiza en la consola de texto y en una línea los datos de una Persona
 */
void PersonaUtil::visualiza(const Persona *p) {
     //cout << p->nombre+" "+p->apellidos << "("+p->dni+") "<<p->edad<<" años";
    visualiza(*p);
}
/**@post Visualiza, el líneas diferentes, las tam primeras personas del vector v.
 * @param Vector de personas
 */
void PersonaUtil::visualiza(const Persona v[], int tam) {
    //El identificador no tiene conflicto con las anteriores funciones visualiza
    //por estar sobrecargado
    for (int i = 0; i < tam; i++) {
        visualiza(v[i]);
        cout << endl;
    }
}
/**@post Visualiza, el líneas diferentes, las tam primeras personas del vector v.
 * @param v, vector de punteros a Personas
 */
void PersonaUtil::visualiza(Persona* *v, int tam) {
    //El identificador no tiene conflicto con las anteriores funciones visualiza
    //por estar sobrecargado
    for (int i = 0; i < tam; i++) {
        visualiza(v[i]);
        cout << endl;
    }
}


/**@post almacena en un archivo las personas del vector en formato CSV.
 */
 /** ¡¡IMPORTANTE EXAMEN!!*/
void PersonaUtil::guardaCSV( itemCSV *v[], int tam,string archivo) {
    //IMPORTANTE:Eliminar const EN PASO DE VECTORES al usar clases abstractas

    ofstream f;

    f.open(archivo.c_str());
    if (f.good()) {
        for (int i = 0; i < tam; i++) {
                /** ¡¡IMPORTANTE EXAMEN!!*/
                if (typeid(*v[i])==typeid(Cliente))
                    f << "Cliente:";
                else
                    f << "Empleado:";
                f << v[i]->toCSV()<<endl;
        };
        f.close();
    } else {
        cerr << "Error de apertura de archivo";
    }

}

/**@brief Lectura de personas de un fichero en formato csv
   @post Modifica las personas en v con los datos leidos del fichero
   @return el número de personas leidas del fichero*/
int PersonaUtil::recuperaCSV(Persona v[], int tam,string archivo) {
    //El identificador no tiene conflicto con las anteriores funciones visualiza
    //por estar sobrecargado
    ifstream f;
    string linea;
    int i=0;

    f.open(archivo.c_str());
    if (f.good()) {
        //Leemos hasta que se acabe el archivo o hasta que no haya más espacio
        //En el vector de personas
        while(f.eof()!=true && i<tam) {
           getline(f,linea);
           v[i].fromCSV(linea);
           i++;
        };
        f.close();
    } else {
        cerr << "Error de apertura de archivo";
    }
    return i;
}
