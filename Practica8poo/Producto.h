/** @brief Definición de la clase Producto
 * @file   Producto.h
 * @author jrbalsas@ujaen.es
 */

#include <string>

#ifndef PROPDUCTO_H
#define	PROPDUCTO_H

using namespace std;

/**@brief Producto*/
class Producto {
private:
    static int ID;
    int id;
    string nombre;
    float pvp;

public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetPvp(float pvp);
    float GetPvp() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetId(int id);
    int GetId() const;
    virtual float getCoste()=0;
};

#endif	/* PROPDUCTO_H */
