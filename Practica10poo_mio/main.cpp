/** @brief Programa de prueba
 * @file   main.cpp
 * @date Created on 11 de mayo de 2015
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
#include "itemCSV.h"    /** ¡¡IMPORTANTE EXAMEN!!*/
#include "Mayor.h"   /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 1 */
#include <vector>  /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 2 */
#include <exception>  /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */

using namespace std;
using namespace PersonaUtil;

//CTE. para simplificar la inicialización de los vectores. ;-)
const int TAMVECTORES=10;

const int MAXCLIENTES=TAMVECTORES;
const int MAXEMPLEADOS=TAMVECTORES;
const int MAXPRODUCTOS=TAMVECTORES;
const int MAXPEDIDOS=TAMVECTORES;
const int MAXTODOS=TAMVECTORES;

/*@brief Programa de prueba de módulos, espacios de nombres y memoria dinámica*/
int main(int argc, char** argv) {

try{
    itemCSV* vtodos[MAXTODOS];      /** ¡¡IMPORTANTE EXAMEN!!*/

    Cliente*  vclientes[MAXCLIENTES];
    Empleado* vempleados[MAXEMPLEADOS];
    Producto* vproductos[MAXPRODUCTOS];
    vector<Pedido*>  vpedidos(TAMVECTORES);  /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */

    //Contadores de elementos en los diferentes vectores
    int numClientes=0;
    int numEmpleados=0;
    int numProductos=0;
    int numPedidos=0;

    int numTodos=0;    /** ¡¡IMPORTANTE EXAMEN!!*/

    cout<<"FIN DECLARACION DE VARIABLES"<<endl;

    //Crear vector de punteros a pedidos (ejemplo de vector en heap))
    //vpedidos=new Pedido*[MAXPEDIDOS];

    //Inicializar vectores de punteros "a la vez"
    for (int i = 0; i < TAMVECTORES; i++) {
        vclientes[i] =0;
        vempleados[i] =0;
        vproductos[i] =0;
        vpedidos[i]=0;
        vtodos[i]=0;
    }

    //Creamos algunos objetos

    vclientes[numClientes++]=new Cliente("Maria","Gonzalez", "1111111A", "C/Bellavista 1");
    vempleados[numEmpleados++]=new Empleado("Juan","Sin Miedo", "3333333C", 1500);

     /** ¡¡IMPORTANTE EXAMEN!! */

     /** --> Creamos un vector de la clase Interface...a Clientes y empleados*/
    vtodos[numTodos++]=new Cliente("Mariaaaaa","Gonzalez", "1111111A", "C/Bellavista 1");
    vtodos[numTodos++]=new Empleado("Juannnnn","Sin Miedo", "3333333C", 1500);

    //NUEVOS PRODUCTOS POLIMORFICOS
    vproductos[numProductos++]=new Articulo(1,1.0,"Tuercas",1.0,75);
    vproductos[numProductos++]=new Servicio(2,2.0,"Poner Tuercas",2.0,"A domicilio");
    vproductos[numProductos++]=new ArticuloAlquilable(3,3,"Taladradora",3333,3,33,"Bosch");

    /** ¡¡IMPORTANTE EXAMEN!!*/

    /** Mostramos en pantalla que la herencia de la interface funciona correctamente.*/
    cout << "itemCSV: "<< vtodos[0]->toCSV();

    /** Utilizamos el nuevo guardaCSV, que ahora permite ver en el fichero de que tipo
    es cada elemento del vector de itemSCV */
    guardaCSV(vtodos,numTodos,"fich.txt");


 /**ESTA PARTE de aqui en adelante, NO SE VE AFECTADA POR LOS CAMBIOS DE ESTA PRACTICA 9 */
    /** SALVO QUE AL FINAL SE LIBERA LA MEMORIA DE vtodos, el nuevo vector de itemCSV */

    //MAS PRODUCTOS POLIMORFICOS
    /**AHORA ABSTRACTOS*/
    Articulo *pa=new Articulo(4,10.5,"Ordenador",2.7,3);
    vproductos[numProductos++]=pa;
    vproductos[numProductos++]=new Servicio(5,22,"Seguro evento", 24,"Concierto");
    vproductos[numProductos++]=new ArticuloAlquilable(6,17,"Coche alquilado",1100,1,48,"Clase A");

    vproductos[3]->SetPvp(100);  //Acceso de Base a Base CAMBIAMOS PRECIO TALADRADORA
    vproductos[5]->SetNombre("Moto Alquilada");  //Acceso de Base a Base CAMBIAMOS NOMBRE COCHE ALQULADO
    pa->SetPeso(100.7);  //Ok  de Derivada a Derivada CAMBIAMOS PESO A ORDENADOR
    pa->SetNombre("Impresora");  //Ok, de Derivada a Base  CAMBIAMOS NOMBRE A ORDENADOR
    /** vproductos[3]->SetPeso(100.7); //No es posible pq no se puede accder de Base a Derivada
    */

    vpedidos[numPedidos++]=new Pedido();
    vpedidos[0]->nuevoProducto(pa,2,10);
    cout << "Coste Heredado:" << vpedidos[0]->GetImporte() << endl;

    //Creamos Y modificamos algunos pedidos (relaciones entre objetos)...
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
        delete vempleados[i];
        delete vproductos[i];
        delete vpedidos[i];

    /** ¡¡IMPORTANTE EXAMEN!!*/

        delete vtodos[i];

    }

    //Borramos el único vector creado en memoria dinámica
    /** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 3 */
    //delete [] vpedidos;

}catch(exception &e){
    cout << e.what() << endl;
}
catch(string &msg){
    cout << msg << endl;
}


    cout << "SALIENDO DEL MAIN"<<endl;
    return 0;
}
