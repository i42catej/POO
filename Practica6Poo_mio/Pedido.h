/** @brief Implementación de la clase Pedido
 * @file   Pedido.h
 */

#include "Fecha.h"
#include "Persona.h"
#include "Producto.h"

#ifndef PEDIDO_H
#define	PEDIDO_H

enum Estado {recibido,preparacion,enviado,cerrado};

class Pedido {
    int id;
    Fecha fPedido;
    Estado estado;
    float importe;
    float gastosEnvio;
    Persona *cliente;
    Persona *atendidoPor;
    int maxProductos;
    int numProductos;
    Producto* *productos;
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
    
    bool nuevoProducto(Producto &p);
    Producto* buscaProducto(int id);
    Producto* getProducto(int i);
    void borraProducto(Producto *p);
    void borraTodosProductos();
    
    //función de clase (no es un método)
    static float totalImportePedidos(Pedido* v[], int tamv);

};

#endif	/* PEDIDO_H */

