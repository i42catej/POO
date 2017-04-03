/** @brief Implementación de la clase Pedido
 */

#include "Pedido.h"
#include <iostream>

using namespace std;

Pedido::Pedido()
        :id(0),fPedido(),estado(recibido),importe(0)
        ,gastosEnvio(0),cliente(0)
{
    cout << "Creando Pedido "<< id <<endl;
}

Pedido::Pedido(int id, float imp, float gEnv)
        :id(id),fPedido(),estado(recibido),importe(imp)
        ,gastosEnvio(gEnv),cliente(0)
{
    cout << "Creando Pedido "<< id <<endl;
}

Pedido::Pedido(const Pedido& orig)
        :id(0),fPedido(orig.fPedido),estado(orig.estado)
        ,importe(orig.importe),gastosEnvio(orig.gastosEnvio)
        ,cliente(orig.cliente)
{
    cout << "Copiando Pedido "<< id <<endl;
}

Pedido::~Pedido() {
    cout << "Destruyendo Pedido "<< id <<endl;
}

void Pedido::SetCliente(Persona* cliente) {
    this->cliente = cliente;
}

Persona* Pedido::GetCliente() const {
    return cliente;
}

void Pedido::SetGastosEnvio(float gastosEnvio) {
    this->gastosEnvio = gastosEnvio;
}

float Pedido::GetGastosEnvio() const {
    return gastosEnvio;
}

void Pedido::SetImporte(float importe) {
    this->importe = importe;
}

float Pedido::GetImporte() const {
    return importe;
}

/**@brief Asigna el estado a un pedido
   @post Asigna el estado indicado al pedido
   @post si el pedido no tiene cliente solo se puede
         asignar estado recibido*/
void Pedido::SetEstado(Estado estado) {
    if (estado!=recibido && cliente==0)
        //No admitimos otro estado si no hay cliente
        return;
    this->estado = estado;
}

Estado Pedido::GetEstado() const {
    return estado;
}

void Pedido::SetFPedido(Fecha fPedido) {
    this->fPedido = fPedido;
}

Fecha Pedido::GetFPedido() const {
    return fPedido;
}

int Pedido::GetId() const {
    return id;
}
float Pedido::getTotal() const {
    return importe+gastosEnvio;
}

/**@brief Calcular el importe total de un vector de punteros a pedidos
   @note función de clase (no es un método que se envía a un objeto). Se llama de forma autónoma*/
float Pedido::totalImportePedidos(Pedido* v[], int tamv) {
    float total=0;
    for (int i = 0; i < tamv; i++) {
        //Solo calculamos el total de los pedidos existentes!
        if (v[i]!=0)
                total+=v[i]->getTotal();
    }
    return total;
}
