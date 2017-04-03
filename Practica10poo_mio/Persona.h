/** @brief Cabecera de la clase Persona
 * @file   Persona.h
 * @author jrbalsas@ujaen.es
 * @date Created on 11 de febrero de 2013, 11:44
 */

#ifndef PERSONA_H
#define	PERSONA_H

#include <string>
#include "Fecha.h"

using namespace std;

/**@brief Clase Persona*/
class Persona {

private:
    /**@brief atributo de clase con total de Personas creadas*/
    static int ID;
    int id; /**< identificador único de persona*/
    string nombre;
    string apellidos;
    string dni;
    int edad;
    Fecha fNacimiento;
    Fecha *fAlta;
    Fecha *fBaja;
public:
    //Persona();
    Persona(string nnombre="Desconocido", string napellidos="Sin Apellidos"
            ,string ndni="00000000A");
    Persona(const Persona &orig);
    ~Persona();
    void setNombre(string nnombre);
    void setEdad(int edad);
    int getEdad() const;
    void setDni(string dni);
    string getDni() const;
    void setApellidos(string apellidos);
    string getApellidos() const;
    string getNombre() const;
    string toCSV() const;
    void fromCSV(string cadena);

    
    bool compara (const Persona& orig);
    void setFNacimiento(const Fecha& fNacimiento);
    Fecha getFNacimiento() const;
    void setFAlta(Fecha* fAlta);
    Fecha* getFAlta() const;
    int getId() const;

};

#endif	/* PERSONA_H */