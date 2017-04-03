/** @brief Programa de prueba
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 * @date Created on 11 de febrero de 2013, 11:44
 */

#include <cstdlib>
#include <iostream>
#include "Empleado.h"
#include "Cliente.h"
#include "PersonaUtil.h"
#include "Fecha.h"
#include "Pedido.h"
#include "Producto.h"
#include "Articulo.h"
#include "Servicio.h"
#include "ArticuloAlquilable.h"


using namespace std;
using namespace PersonaUtil;

//CTE. para simplificar la inicialización de los vectores. ;-)
const int TAMVECTORES=10;

const int MAXCLIENTES=TAMVECTORES;
const int MAXEMPLEADOS=TAMVECTORES;
const int MAXPRODUCTOS=TAMVECTORES;
const int MAXPEDIDOS=TAMVECTORES;

/*@brief Programa de prueba de módulos, espacios de nombres y memoria dinámica*/
int main(int argc, char** argv) {
    Cliente*  vclientes[MAXCLIENTES];
    Empleado* vempleados[MAXEMPLEADOS];
    Producto* vproductos[MAXPRODUCTOS];
    Pedido*  *vpedidos;

    //Contadores de elementos en los diferentes vectores
    int numClientes=0;
    int numEmpleados=0;
    int numProductos=0;
    int numPedidos=0;

    cout<<"FIN DECLARACION DE VARIABLES"<<endl;

    //Crear vector de punteros a pedidos (ejemplo de vector en heap))
    vpedidos=new Pedido*[MAXPEDIDOS];

    //Inicializar vectores de punteros "a la vez"
    for (int i = 0; i < TAMVECTORES; i++) {
        vclientes[i] =0;
        vempleados[i] =0;
        vproductos[i] =0;
        vpedidos[i]=0;
    }

    //Creamos algunos objetos
    vclientes[numClientes++]=new Cliente("Maria","Gonzalez", "1111111A", "C/Bellavista 1");
    vclientes[numClientes++]=new Cliente("Paco","Lorite", "22222222B", "C/Malavista 2");
    vempleados[numEmpleados++]=new Empleado("Juan","Sin Miedo", "3333333C", 1500);
    vempleados[numEmpleados++]=new Empleado("Sergio","Lechuga", "4444444D", 2600);
    vproductos[numProductos++]=new Producto(1,"Tuercas",75);
    vproductos[numProductos++]=new Producto(2,"Tornillos",100);
    vproductos[numProductos++]=new Producto(3,"Puntas",27);

    //NUEVOS PRODUCTOS POLIMORFICOS
    Articulo *pa=new Articulo(4,10.5,"Ordenador",2.7,3);
    vproductos[numProductos++]=pa;
    vproductos[numProductos++]=new Servicio(5,22,"Seguro evento", 24,"Concierto");
    vproductos[numProductos++]=new ArticuloAlquilable(6,17,"Coche alquilado",1100,1,48,"Clase A");

    vproductos[3]->SetPvp(100);  //Acceso de Base a Base
    vproductos[5]->SetNombre("Moto Alquilada");  //Acceso de Base a Base
    pa->SetPeso(100.7);  //Ok  de Derivada a Derivada
    pa->SetNombre("Impresora");  //Ok, de Derivada a Base
    /** vproductos[3]->SetPeso(100.7); //No es posible pq no se puede accder de Base a Derivada
    */
    vpedidos[numPedidos++]=new Pedido();
    vpedidos[0]->nuevoProducto(pa,2,10);
    cout << "Coste Heredado:" << vpedidos[0]->GetImporte() << endl;


    //Creamos algunos pedidos (relaciones entre objetos)...

    vpedidos[numPedidos++]=new Pedido();
    vpedidos[numPedidos++]=new Pedido();

    vpedidos[0]->SetGastosEnvio(20);
    vpedidos[0]->SetCliente(vclientes[0]);
    vpedidos[0]->SetAtendidoPor(vempleados[0]);

    vpedidos[1]->SetGastosEnvio(30);
    vpedidos[1]->SetCliente(vclientes[1]);
    vpedidos[1]->SetAtendidoPor(vempleados[0]);

    vpedidos[2]->SetGastosEnvio(10);
    vpedidos[2]->SetCliente(vclientes[1]);
    vpedidos[2]->SetAtendidoPor(vempleados[1]);

    //... y les añadimos productos (ojo, espera referencias, NO punteros)

    vpedidos[0]->nuevoProducto(vproductos[0],20,0);
    vpedidos[0]->nuevoProducto(vproductos[1],50,0.5);
    vpedidos[0]->nuevoProducto(vproductos[2],5,0.8);

    vpedidos[1]->nuevoProducto(vproductos[0],46,0);
    vpedidos[1]->nuevoProducto(vproductos[1],128,0.5);

    vpedidos[2]->nuevoProducto(vproductos[0],2,0);

    //Ahora vamos a hacer algunas consultas

    cout<<"Pedido: "<<vpedidos[0]->GetId()<<" precio:"<<vpedidos[0]->getTotal()<<" cliente:"
        <<vpedidos[0]->GetCliente()->getNombre()<<endl;


    cout <<"El total de facturacion en pedidos es de "
         <<Pedido::totalImportePedidos(vpedidos,numPedidos)<<" euros"<<endl;

    int posMaxTotal=0;
    for (int i=0; i<numPedidos;i++) {
        if (vpedidos[i]->getTotal()>vpedidos[posMaxTotal]->getTotal())
            posMaxTotal=i;
    };

    cout << "El pedido de mas cantidad asciende a "<<vpedidos[posMaxTotal]->getTotal()
         << " euros y ha sido tramitado por "<<vpedidos[posMaxTotal]->GetAtendidoPor()->getNombre()
         <<endl;

    //¿El artículo 0 existe en el pedido 0?
    Producto *prLocalizado;
    prLocalizado=vpedidos[0]->buscaProducto(0);
    if (prLocalizado!=0) {
        //OK, si devuelve un puntero diferente a 0 es que existe el producto en cuestión
        cout << "En el pedido de "<<vpedidos[0]->GetCliente()->getNombre()
             << " esta el articulo "<<prLocalizado->GetNombre()
             << endl;
    }

    cout << "LIBERANDO RECURSOS"<<endl;

    //Borrarmos todos los objetos creados a la vez (por comodidad en la implementación!)
    for (int i = 0; i < TAMVECTORES; i++) {
         delete vclientes[i];
         delete vpedidos[i];
         delete vproductos[i];
         delete vempleados[i];

    }

    //Borramos el único vector creado en memoria dinámica
    delete [] vpedidos;

    cout << "SALIENDO DEL MAIN"<<endl;
    return 0;
}
