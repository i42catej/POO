/** @brief Implementación de la clase Pedido
 */

#include "Fecha.h"
#include "Persona.h"

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
public:
    Pedido();
    Pedido(int id, float imp=0.0, float gEnv=0.0);
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetCliente(Persona* cliente);
    Persona* GetCliente() const;
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
    //función de clase (no es un método)
    static float totalImportePedidos(Pedido* v[], int tamv);

};

#endif	/* PEDIDO_H */
