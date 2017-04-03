/** @brief Definición de la clase Empleado
 * @file   Empleado.h
 *  */
#include "Persona.h"
#include "itemCSV.h"   /** ¡¡IMPORTANTE EXAMEN!!*/

#ifndef EMPLEADO_H
#define	EMPLEADO_H

/**@brief Empleado*/
class Empleado: public Persona, public itemCSV{   /** ¡¡IMPORTANTE EXAMEN!!*/
private:
    float salario;
public:
    Empleado(string nnombre="Desconocido", string napellidos="Sin Apellidos"
            ,string ndni="00000000A",float salario=600);
    Empleado(const Empleado& orig);
    virtual ~Empleado();
    void setSalario(float salario);
    float getSalario() const;

    virtual string toCSV();  /** ¡¡IMPORTANTE EXAMEN!!*/
    virtual void fromCSV(string cadena);   /** ¡¡IMPORTANTE EXAMEN!!*/

};

#endif	/* EMPLEADO_H */
