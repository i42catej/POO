/**
 * @file   Fecha.h
 * @author jrbalsas@ujaen.es
 * @date Created on 4 de marzo de 2013, 10:56
 */


#ifndef FECHA_H
#define	FECHA_H

#include <ctime>
#include <string>
#include <stdlib.h>
#include<sstream>

using namespace std;

/**@brief Clase Fecha*/
class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int ndia, int nmes=1, int nanio=1960) throw (string);
    Fecha();

    Fecha(const Fecha& orig);
    virtual ~Fecha();
    void SetAnio(int anio)throw (string);
    int GetAnio() const;
    void SetMes(int mes);
    int GetMes() const;
    void SetDia(int dia);
    int GetDia() const;

    int anioMesDia(){  //INLINE.........Complejo

        string cadena;
        stringstream ss;

        ss<<anio<<mes<<dia;

        //ss>>cadena; No lee espacios en blanco
        //cadena=ss.str();
        getline(ss,cadena);
     int valor = atoi(cadena.c_str());
    /*    string myString = "45";
        istringstream buffer(cadena);
        int value;
        buffer >> value;   // value = 45*/
        return valor;
    }

};

#endif	/* FECHA_H */
