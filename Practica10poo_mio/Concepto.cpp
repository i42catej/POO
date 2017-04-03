/** @brief Implementación de la clase Concepto
 * @file   Concepto.cpp
 * @author jrbalsas@ujaen.es
 */
#include "Concepto.h"
#include <iostream>
using namespace std;

Concepto::Concepto(Producto *pr, int unds, float dto):
producto(pr),unidades(unds),dto(dto)
{
    cout<<"Creando concepto "<<producto->GetNombre()<<endl;
}

Concepto::Concepto(const Concepto& orig):
        producto(orig.producto),unidades(orig.unidades),dto(orig.dto){
    cout<<"Copiando concepto "<<producto->GetNombre()<<endl;
}

Concepto::~Concepto() {
    cout<<"Destruyendo concepto "<<endl;
}

void Concepto::SetUnidades(int unidades) {
    this->unidades = unidades;
}

int Concepto::GetUnidades() const {
    return unidades;
}

void Concepto::SetDto(float dto) {
    this->dto = dto;
}

float Concepto::GetDto() const {
    return dto;
}

void Concepto::SetProducto(Producto* producto) {
    this->producto = producto;
}

Producto* Concepto::GetProducto() const {
    return producto;
}

/**@brief Devuelve el coste total del producto según el número de unidades y el descuento*/
float Concepto::getCoste() const {
    float subtotal=producto->GetPvp()*this->unidades;
    return subtotal*(100-this->dto);
}
