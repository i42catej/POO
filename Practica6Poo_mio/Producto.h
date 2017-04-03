/** @brief Definición de la clase Producto
 * @file   Producto.h
 */

#include <string>

#ifndef PROPDUCTO_H
#define	PROPDUCTO_H

using namespace std;

class Producto {
private:
    static int ID;
    int id;
    string nombre;
    float pvp;
    
public:
    Producto();
    Producto(string nombre, float pvp);
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetPvp(float pvp);
    float GetPvp() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetId(int id);
    int GetId() const;

};

#endif	/* PROPDUCTO_H */



