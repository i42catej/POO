/** 
 * @file   Fecha.h
 */


#ifndef FECHA_H
#define	FECHA_H

/**@brief Clase Fecha*/
class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int ndia=0, int nmes=0, int nanio=0);
    Fecha(const Fecha& orig);
    virtual ~Fecha();
    void SetAnio(int anio);
    int GetAnio() const;
    void SetMes(int mes);
    int GetMes() const;
    void SetDia(int dia);
    int GetDia() const;

};

#endif	/* FECHA_H */
