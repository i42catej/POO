/** @brief Definición de la clase Concepto
 * @file   Concepto.h
 * @author jrbalsas@ujaen.es
 */
#include "Producto.h"

#ifndef CONCEPTO_H
#define	CONCEPTO_H

/**@brief Concepto*/
class Concepto {
private:
    Producto *producto;
    float dto;
    int unidades;
public:
    Concepto(Producto *pr, int unds=1, float dto=0);
    Concepto(const Concepto& orig);
    virtual ~Concepto();
    void SetUnidades(int unidades);
    int GetUnidades() const;
    void SetDto(float dto);
    float GetDto() const;
    void SetProducto(Producto* producto);
    Producto* GetProducto() const;
    float getCoste() const;



};

#endif	/* CONCEPTO_H */
