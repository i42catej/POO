/** @brief Definición de la clase Cliente
 * @file   Cliente.h
 * @author jrbalsas@ujaen.es
 */

#include "Persona.h"
#include "itemCSV.h"   /** ¡¡IMPORTANTE EXAMEN!!*/

#ifndef CLIENTE_H
#define	CLIENTE_H

/**@brief Cliente*/
class Cliente: public Persona, public itemCSV{   /** ¡¡IMPORTANTE EXAMEN!!*/
    private:
        string direccion;
    public:
    Cliente(string nnombre="Desconocido", string napellidos="Sin Apellidos"
            ,string ndni="00000000A",string direccion="Desconocida");
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetDireccion(string direccion);
    string GetDireccion() const;

    virtual string toCSV() ;      /** ¡¡IMPORTANTE EXAMEN!!*/
    virtual void fromCSV(string cadena);    /** ¡¡IMPORTANTE EXAMEN!!*/
};

#endif	/* CLIENTE_H */
