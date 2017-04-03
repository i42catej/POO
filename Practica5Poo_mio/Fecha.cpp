/** 
 * @file   Fecha.cpp
 */

#include <time.h>

#include "Fecha.h"
#include <iostream>
using namespace std;

/**@brief Constructor
 @post Crea una fecha con el día mes y año indicados
 @post Si no se especifican nada se utiliza la fecha del sistema
*/
Fecha::Fecha(int ndia, int nmes, int nanio)
        :dia(ndia),mes(nmes),anio(nanio) {
    
    if (ndia==0) {
        time_t horaactual;
        //obtenemos la hora actual (segundos desde 1-1-1971)
        horaactual=time(0);
        struct tm *datoshora;
        //convertimos la fecha a hora, minutos, segundos,año, etc.
        datoshora=localtime(&horaactual);

        dia=datoshora->tm_mday;
        mes=datoshora->tm_mon+1;
        anio=datoshora->tm_year+1900;
        
    };
    cout << "Creando fecha "<<dia<<"-"<<mes<<"-"<<anio<<endl;
}

Fecha::Fecha(const Fecha& orig)
        :dia(orig.dia),mes(orig.mes),anio(orig.anio) {
    cout << "Copiando fecha "<<endl;
}

Fecha::~Fecha() {
    cout << "Destruyendo fecha"<<endl;
}

void Fecha::SetAnio(int anio) {
    this->anio = anio;
}

int Fecha::GetAnio() const {
    return anio;
}

void Fecha::SetMes(int mes) {
    this->mes = mes;
}

int Fecha::GetMes() const {
    return mes;
}

void Fecha::SetDia(int dia) {
    this->dia = dia;
}

int Fecha::GetDia() const {
    return dia;
}
