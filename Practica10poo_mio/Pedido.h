/** @brief Implementación de la clase Pedido
 * @file   Pedido.h
 */

#include "Fecha.h"
#include "Persona.h"
#include "Producto.h"
#include "Concepto.h"
#include <vector>


#ifndef PEDIDO_H
#define	PEDIDO_H

enum Estado {recibido,preparacion,enviado,cerrado};

class Pedido {
    static int ID;
    int id;
    Fecha fPedido;
    Estado estado;
    float importe;
    float gastosEnvio;
    int maxProductos;
    int numProductos;
    Persona *cliente;
    Persona *atendidoPor;

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
    vector<Concepto*> productos;

public:
    Pedido(int maxProductos=10);
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetCliente(Persona* cliente);
    Persona* GetCliente() const;
    void SetNumProductos(int numProductos);

    int GetNumProductos() const;
    void SetAtendidoPor(Persona* atendidoPor);
    Persona* GetAtendidoPor() const;
    void SetGastosEnvio(float gastosEnvio);
    float GetGastosEnvio() const;
    void SetImporte(float importe);
    float GetImporte() const;
    void SetEstado(Estado estado);
    Estado GetEstado() const;
    void SetFPedido(Fecha fPedido);
    Fecha GetFPedido() const;
    int GetId() const;
    float getTotal() const;

    bool nuevoProducto(Producto *p, int unidades, float desc);
    Producto* buscaProducto(int id);
    Producto* getProducto(int i);
    void borraProducto(Producto *p);
    void borraTodosProductos();

    //función de clase (no es un método)
    /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
    static float totalImportePedidos(vector<Pedido*> v, int tamv);

};

#endif	/* PEDIDO_H */

