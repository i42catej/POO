/** @brief Implementación de la clase Pedido
 * @file   Pedido.cpp
 */

#include "Pedido.h"
#include <iostream>

using namespace std;

int Pedido::ID=0;
 /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
/** Imagibar que llamaramos a fPedido(1,1,2222), se generaría una exception tipo string
en fecha */
Pedido::Pedido(int maxProductos)
        :id(ID++),fPedido(),estado(recibido),importe(0)
        ,gastosEnvio(0),maxProductos(maxProductos)
        ,numProductos(0),cliente(0),atendidoPor(0),
        productos(maxProductos)   /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */

{
    cout << "Creando Pedido "<< id <<endl;
    /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
   // productos=new Concepto*[maxProductos];
    for (int i = 0; i < maxProductos; i++) {
         productos[i] = 0;
    }
}

Pedido::Pedido(const Pedido& orig)
        :id(ID++),fPedido(orig.fPedido),estado(orig.estado)
        ,importe(orig.importe),gastosEnvio(orig.gastosEnvio)
        ,cliente(orig.cliente),maxProductos(orig.maxProductos)
        ,numProductos(orig.numProductos),atendidoPor(orig.atendidoPor),
        productos(maxProductos)     /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */

{
    cout << "Copiando Pedido "<< id <<endl;
   /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
   // productos=new Concepto*[maxProductos];
    for (int i = 0; i < maxProductos; i++) {
         productos[i] = orig.productos[i];
    }
}

Pedido::~Pedido() {
    cout << "Destruyendo Pedido "<< id <<endl;

     for (int i = 0; i < numProductos; i++) {
           if (productos[i]){
                delete productos[i];
           }
    }
    /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
    //delete [] productos;
}

void Pedido::SetCliente(Persona* cliente) {
    this->cliente = cliente;
}

Persona* Pedido::GetCliente() const {
    return cliente;
}

void Pedido::SetNumProductos(int numProductos) {
    this->numProductos = numProductos;
}

int Pedido::GetNumProductos() const {
    return numProductos;
}

void Pedido::SetAtendidoPor(Persona* atendidoPor) {
    this->atendidoPor = atendidoPor;
}

Persona* Pedido::GetAtendidoPor() const {
    return atendidoPor;
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
    int s=0;
    for (int i=0; i<numProductos;i++){
        if (productos[i])
            s+=productos[i]->getCoste();
    }
    return s;
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

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
/** @brief Añade un Concepto con productos a un pedido
 *  @post Si existe espacio, lo añade al pedido
 *  @return verdadero si se añade al pedido. Falso en caso contrario
 */
bool Pedido::nuevoProducto(Producto *p, int unidades, float desc) {
    if (numProductos<maxProductos){

        //creamos un nuevo concepto con el puntero al producto que me mandan
        // junto a unidades y descuento
        Concepto *concep= new Concepto(p,unidades,desc);
        //Y lo asignamos al vector de productos
        productos.at(numProductos)=concep;
        numProductos++;
        return true;
    }
    return false;
}
/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
/** @brief Busca un producto en un pedido por su id
 *  @post Devuelve la dirección de memoria del producto encontrado
 *  @post Devuelve null si el Producto con id indicado no se encuentra en el pedido
 */
Producto* Pedido::buscaProducto(int id) {
    Producto *encontrado=0;
    for (int i = 0; i < numProductos && encontrado==0; i++) {
        if (productos.at(i)->GetProducto()->GetId()==id) {
            encontrado=productos.at(i)->GetProducto();
        }
    }
   return encontrado;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
/** @brief Devuelve un producto del pedido
 *  @post Devuelve el puntero al i-esimo producto del pedido
 *  @post Devuelve 0 si el pedido tiene menos de i productos
 */
Producto* Pedido::getProducto(int i) {
    Producto *encontrado=0;
    if (i<numProductos)
           //Devolvemos la dirección de memodia del pedido i-esimo
           encontrado=productos.at(i)->GetProducto();
    return encontrado;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
/**@brief Calcular el importe total de un vector de punteros a pedidos
   @note función de clase (no es un método que se envía a un objeto). Se llama de forma autónoma*/
float Pedido::totalImportePedidos(vector<Pedido*> v, int tamv) {
    float total=0;
    for (int i = 0; i < tamv; i++) {
        //Solo calculamos el total de los pedidos existentes!
        if (v.at(i)!=0)
                total+=v.at(i)->getTotal();
    }
    return total;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
void Pedido::borraProducto(Producto *p) {
    bool encontrado=false;
    int i;
    for (i = 0; i < numProductos && !encontrado; i++) {
        if (productos.at(i)->GetProducto()==p) {
            encontrado=true;
        }
    }
    if (encontrado){
        delete p;
        for (int j = i; j < numProductos-1; j++) {
                productos.at(i)=productos.at(i+1);
        }
        productos.at(numProductos--)=0;
    }
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
void Pedido::borraTodosProductos() {

    for (int i = 0; i < numProductos; i++) {
           if (productos.at(i))
               delete productos.at(i);
    }
   /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
    //delete [] productos;
}
