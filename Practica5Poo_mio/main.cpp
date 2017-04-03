/** @brief Programa de prueba
 * @file   main.cpp
 */

#include <cstdlib>
#include <iostream>
#include "Persona.h"
#include "PersonaUtil.h"
#include "Fecha.h"
#include "Pedido.h"

using namespace std;
using namespace PersonaUtil;


/*@brief Programa de prueba de módulos, espacios de nombres y memoria dinámica*/
int main(int argc, char** argv) {

    Persona *vpersonas;
    int numPersonas;
    int maxPedidos, numPedidos=0;
    
    Persona p1("Maria","Martinez","11111111");
    Fecha f(4,7,1998);
    Pedido* *vpedidos;

    cout<<"FIN DECLARACIÓN DE VARIABLES"<<endl;

    cout << "Ejemplo de CSV de cliente: "<<p1.toCSV()<<endl;
    
    do{
        cout << "Introduce cantidad de Pedidos" << endl;
        cin >> maxPedidos;
    } while (maxPedidos<=0);
    vpedidos=new Pedido*[maxPedidos];
 
    for (int i = 0; i < maxPedidos; i++) {
         vpedidos[i] =0;
    }
    
    vpedidos[0]=new Pedido(1111);
    numPedidos++;
    
    vpedidos[0]->SetImporte(1200);
    vpedidos[0]->SetGastosEnvio(20);
    vpedidos[0]->SetCliente(&p1);
    //...
    cout<<"Pedido:"<<vpedidos[0]->GetId()<<" precio:"<<vpedidos[0]->getTotal()<<" cliente:"
        <<vpedidos[0]->GetCliente()->getNombre()<<endl;

    //Otro pedido para Maria de ejemplo
    vpedidos[1]=new Pedido(2222);
    numPedidos++;
    
    vpedidos[1]->SetImporte(350);
    vpedidos[1]->SetGastosEnvio(75);
    vpedidos[1]->SetCliente(&p1);
    
    int idPed;
    cout << "Introduce Numero de pedido a eliminar"<< endl;
    cin >> idPed;
    for (int i = 0; i < numPedidos; i++) {
         if (vpedidos[i]->GetId()==idPed){
             vpedidos[i]=vpedidos[numPedidos];
             numPedidos--;
             cout << "Persona Eliminada !!"<< endl;
         }
    }
    
    cout <<"El total de facturación en pedidos es de "
         <<Pedido::totalImportePedidos(vpedidos,maxPedidos)<<" euros"<<endl;
    
    //Creamos e inicializamos el vector de Personas
    cout << "Introduce el número de personas: ";
    do {
        cin >> numPersonas;
    } while (numPersonas<=0);

    //Reservamos memoria para el vector de versonas
    //Se llama al constructor por defecto de cada Persona creada en el vector!
    vpersonas=new Persona[numPersonas];

    cout<<  "Leemos y visualizamos el vector"<<endl;
    lee(vpersonas,numPersonas);
    visualiza(vpersonas,numPersonas);
    
    //Guardamos las personas en disco en formato csv
    almacenaEnCSV(vpersonas,numPersonas,"personas.csv");

    //Modificamos algunas fechas de nacimiento
    p1.setFNacimiento(f);
    vpersonas[0].setFNacimiento(Fecha(5,10,1985));

    //Asignamos algunas fechas de alta
    p1.setFAlta(new Fecha());
    vpersonas[0].setFAlta(new Fecha(7,7,1990));

    //Visualizamos algunas fechas de alta si están asignadas a la persona
    if (p1.getFAlta()!=0)
        cout << p1.getNombre() << " se dió de alta en "<< p1.getFAlta()->GetAnio()<<endl;
    if (vpersonas[0].getFAlta()!=0) {
        cout << vpersonas[0].getNombre() << " se dió de alta en "
                << vpersonas[0].getFAlta()->GetAnio()<<endl;
    } else {
        cout << vpersonas[0].getNombre() << " No está dado de alta " <<endl;
    }
    
    //Liberar la memoria del vector de personas.
    //Se llama a los destructores de todas las personas
    delete [] vpersonas;

    //Borrar pedidos y vector de pedidos
    for (int i = 0; i < maxPedidos; i++) {
         delete vpedidos[i];
    }
    delete [] vpedidos;
    
    cout << "SALIENDO DEL MAIN"<<endl;
    return 0;
}
