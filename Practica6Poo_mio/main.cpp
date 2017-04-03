/** @brief Programa de prueba
 * @file   main.cpp
 */

#include <cstdlib>
#include <iostream>
#include "Persona.h"
#include "PersonaUtil.h"
#include "Fecha.h"
#include "Pedido.h"
#include "Producto.h"

using namespace std;
using namespace PersonaUtil;


/*@brief Programa de prueba de módulos, espacios de nombres y memoria dinámica*/
int main(int argc, char** argv) {

    Persona *vpersonas;
    int numPersonas;
    string nomArchivoPersonas="personas.csv";

    int maxProductos=100;
    Producto* vproductos[maxProductos];  //vector de punteros a productos  

    Pedido* *vpedidos;  //vector dinámico de punteros(puntero a vector de punteros a pedidos)
    int maxPedidos=100;

    Persona p1("Maria","Garcia","11111111");
    Fecha f(4,7,1980);
    cout<<"FIN DECLARACIÓN DE VARIABLES"<<endl;

    //Crear e inicializar vector de punteros a pedidos
    vpedidos=new Pedido*[maxPedidos];
    for (int i = 0; i < maxPedidos; i++) {
         vpedidos[i] =0;
    }

    //Inicializar vector de punteros a productos
    for (int i = 0; i < maxProductos; i++) {
         vproductos[i] =0;
    }
    //Añadimos algunos pedidos
    vpedidos[0]=new Pedido();
    
    vpedidos[0]->SetImporte(1200);
    vpedidos[0]->SetGastosEnvio(20);
    vpedidos[0]->SetCliente(&p1);
    //...
    cout<<"Pedido:"<<vpedidos[0]->GetId()<<" precio:"<<vpedidos[0]->getTotal()<<" cliente:"
        <<vpedidos[0]->GetCliente()->getNombre()<<endl;

    //Otro pedido para Maria
    vpedidos[1]=new Pedido();
    
    vpedidos[1]->SetImporte(350);
    vpedidos[1]->SetGastosEnvio(75);
    vpedidos[1]->SetCliente(&p1);
    
    cout <<"El total de facturación en pedidos es de "
         <<Pedido::totalImportePedidos(vpedidos,maxPedidos)<<" euros"<<endl;
    
    //Creamos algunos productos
    vproductos[0]=new Producto("Tuercas",75);
    vproductos[1]=new Producto("Tornillos",100);
    vproductos[2]=new Producto("Puntas",27);
    
    vpedidos[0]->nuevoProducto(*vproductos[0]);
    vpedidos[0]->nuevoProducto(*vproductos[1]);
    vpedidos[0]->nuevoProducto(*vproductos[2]);

    //Creamos e inicializamos el vector de Personas
    cout << "Introduce el número de personas: ";
    do {
        cin >> numPersonas;
    } while (numPersonas<=0);

    //Reservamos memoria para el vector de versonas
    //Se llama al constructor por defecto de cada Persona creada en el vector!
    vpersonas=new Persona[numPersonas];

    cout<<  "Leemos y visualizamos el vector de personas"<<endl;
    lee(vpersonas,numPersonas);
    visualiza(vpersonas,numPersonas);
        
    //Guardamos las personas en disco en formato csv
    guardaCSV(vpersonas,numPersonas,nomArchivoPersonas);

    //Creamos un nuevo vector para leer los datos del fichero CSV
    Persona *w=new Persona[numPersonas];
    recuperaCSV(w,numPersonas,nomArchivoPersonas);
    cout << "Personas leidas del fichero"<<endl;
    visualiza(w,numPersonas);
    delete [] w;
    
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
   
    cout << "LIBERANDO RECURSOS"<<endl;
    
    //Liberar la memoria del vector de personas.
    //Se llama a los destructores de todas las personas
    delete [] vpersonas;

    //Borrar pedidos y vector de pedidos
    for (int i = 0; i < maxPedidos; i++) {
         delete vpedidos[i];
    }
    delete [] vpedidos;
 
    //Eliminar objetos en vector de  productos
    for (int i = 0; i < maxProductos; i++) {
        delete vproductos[i];
    }
    cout << "SALIENDO DEL MAIN"<<endl;
    return 0;
}

