/**
 * @file   Fecha.cpp
 * @author jrbalsas@ujaen.es
 * @date Created on 4 de marzo de 2013, 10:56
 */

#include "Fecha.h"
#include <iostream>
#include <string>
using namespace std;

 /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */

Fecha::Fecha(int ndia, int nmes, int nanio) throw (string)
{
    if (ndia<1 || ndia>31 || nmes<1 || nmes>12 || nanio<0 || nanio>2014) throw (string)"Fecha no valida";
    dia=ndia;
    mes=nmes;
    anio=nanio;
    cout << "Creando fecha "<<endl;
}

Fecha::Fecha(){ //COMPLEJO

        time_t horaactual;
        //obtenemos la hora actual (segundos desde 1-1-1971)
        horaactual=time(0);
        struct tm *datoshora;
        //convertimos la fecha a hora, minutos, segundos,año, etc.
        datoshora=localtime(&horaactual);

        dia=datoshora->tm_mday;
        mes=datoshora->tm_mon+1;
        anio=datoshora->tm_year+1900;
        //Más info http://www.cplusplus.com/reference/clibrary/ctime/localtime/
    };


Fecha::Fecha(const Fecha& orig)
        :dia(orig.dia),mes(orig.mes),anio(orig.anio) {
    cout << "Copiando fecha "<<endl;
}

Fecha::~Fecha() {
    cout << "Destruyendo fecha"<<endl;
}

 /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
//Lanzando solo excepciones sting
void Fecha::SetAnio(int anio) throw (string) {
    if (anio<0 || anio>2014) throw (string)"Anio no valido";
    this->anio = anio;
}

int Fecha::GetAnio() const {
    return anio;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
//Lanzando cualquier excepcion
void Fecha::SetMes(int mes) {
    if (mes<0 || mes>12) throw (string)"Mes no valido";
    this->mes = mes;
}

int Fecha::GetMes() const {
    return mes;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
//Lanzando cualquier excepcion
void Fecha::SetDia(int dia) {
    if (dia<0 || dia>12) throw (string)"Dia no valido";
    this->dia = dia;
}

int Fecha::GetDia() const {
    return dia;
}
