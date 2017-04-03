#include "Persona.h"
#include <iostream>
using namespace poo_pr2;
 /**
     * @brief lee por teclado una persona
     * @param p, el registro persona a leer
     * @pre no tiene
     * @post lee por teclado los datos de una persona validos
     */
    
     void leePersonaTeclado(Persona &p){
        
        do{
            cout << "Introduce el nombre: ";
            getline(cin >> ws, p.nombre);
            
        }while(p.nombre.length() < 3 || p.nombre.length() > 50);
        
        do{
            cout << "Introduce los apellidos: ";
            getline(cin >> ws, p.apellidos);
            
        }while (p.apellidos.length()<3 || p.apellidos.length() >70);
        
        do{
            cout << "DNI: ";
            cin >> p.dni;
            
        }while(p.dni.length() != 9);
        
        do{
            cout << "Edad: ";
            cin >> p.edad;
            
        }while(p.edad < 1 || p.edad > 150);
            
           
    }
     
     /**
      * @brief lee por teclado una persona
      * @param p puntero a un registro persona a leer
      * @pre p debe de apuntar a un registro persona inicializado
      * @post lee por teclado los datos de una persona validos
      */
     
      void leePersonaTeclado(Persona *p){
        
        do{
            cout << "Introduce el nombre: ";
            getline(cin >> ws, p->nombre);
            
        }while(p->nombre.length() < 3 || p->nombre.length() > 50);
        
        do{
            cout << "Introduce los apellidos: ";
            getline(cin >> ws, p->apellidos);
            
        }while (p->apellidos.length()<3 || p->apellidos.length() >70);
        
        do{
            cout << "DNI: ";
            cin >> p->dni;
            
        }while(p->dni.length() != 9);
        
        do{
            cout << "Edad: ";
            cin >> p->edad;
            
        }while(p->edad < 1 || p->edad > 150);
                   
    }
      
      /**
       * @brief Muestra los datos de una persona
       * @param p el registro persona a mostrar
       * @pre que p este inicializado
       * @post Muestra por pantalla los datos de una persona p
       */
      
      void muestraPersonaPantalla(const Persona &p){
          
          cout << p.nombre << " " << p.apellidos << " " << p.dni << " " << p.edad;
      }
      
      /**
       * @brief Muestra los datos de una persona
       * @param p puntero a un registro persona
       * @pre que p puntero a persona este inicializado
       * @post Muestra por pantalla los datos de una persona p
       */

      void muestraPersonaPantalla(const Persona *p){
          
          cout << p->nombre << " " << p->apellidos << " " << p->dni << " " << p->edad;
      }

      /**@brief rellenavector
         @param v vector de persona
         @param max nº maximo de personas
         @post lee personas por teclado, las mete en vp hasta que el usuario pare
         @return devuelve nº de personas leidas
       */
      int rellenaVector(Persona vp[],int max){
          char seguir= 's';
          int i=0;
          while(i<max && seguir=='s'){
              leePersonaTeclado(vp[i]);
              cout<<"Pulsa 's' para seguir,sino otra tecla";
              cin>>seguir;
              i++;
          }
          return i;
      }
      
      /**@brief mostrar en pantalla
         @param vp vector de personas
         @param max numero de personas
         @post muestra personas de 5 en 5
       */
      void mostrarEnPantalla (const Persona vp[],int max){
          char x;
          for(int i=0;i<max;i++){
              muestraPersonaPantalla(vp[i]);
              if((i+1)%5==0){
                  cout<<"Pulsa tecla siguientes 5";
                  cin>>x;
              }
          }
       }
      /**@brief calcular la media
         @param vp vector de personas
         @param max numero de personas
         @post calcula la media de edad
         @return la media de la edad
        */
      float mediaEdad (const Persona vp[],int tam) {
          int s=0,n;
          for (int i=0;i<tam;i++){
              s+=vp[i].edad;
              n=s/tam;
          }
          return n;
       }
      
      /**@brief buscapersona por apellidos
       @param tam nº de personas
       @param apellidos
       @param vp[] vector de personas
       @post devuelve la posicion o -1
       @pre tam>0
       @return entero con la posicion o -1 si no esta
       */
      int buscar(const string &apellidos,const Persona vp[],int tam) {
          for(int i=0;i<tam;i++){
              if(vp[i].apellidos==apellidos){
                  return i;
              }
          }
          return -1;
      }
      
      void masmenos(const Persona vp[],int tama,int &pmayor,int &pmenor) {
          int mayor,menor;
          menor=mayor=v[0].edad;
          pmayor=pmenor=0;
          for(int i=1;i<tama;i++){
              if(vp[i].edad>mayor){
                  mayor=vp[i].edad;
                  pmayor=i;
              }else{
                  if(vp[i].edad<menor){
                      menor=vp[i].edad;
                      pmenor=i;
                  }
              }
          }
      }
      
      void ordenar(const Persona vp[],int tama) {
          Persona aux;
          for (int i=1;i<tama;i++){
              for(int j=0;j<tama-i;j++){
                  if (vp[j].apellidos> vp[j+1].apellidos){
                      aux=vp[j];
                      vp[j]=vp[j+1];
                      vp[j+1]=aux;
                  }
              }
          }
      }