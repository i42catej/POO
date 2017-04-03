#include <cstdlib>
#include <string>
#include <iostream>
#include "PersonaUtil.h"

using namespace std;
using namespace PersonaUtil;
/**
     * @brief lee por teclado una persona
     * @param p, el registro persona a leer
     * @pre no tiene
     * @post lee por teclado los datos de una persona validos
     */
    
void PersonaUtil::leePersonaTeclado(Persona &p){
        
         string cad;
         int n;
         char l;
        do{
            cout << "Introduce el nombre: ";
            getline(cin >> ws, cad);
            
        }while(cad.length() < 1 || cad.length() > 30);
        p.setNombre(cad);
        
        do{
            cout << "Introduce el primer apellido: ";
            getline(cin >> ws, cad);
            
        }while (cad.length()<1 || cad.length() >40);
        p.setPrimerApellido(cad);
        
       do{
            cout << "Introduce el segundo apellido: ";
            getline(cin >> ws, cad);
            
        }while (cad.length()<1 || cad.length() >40);
        p.setSegundoApellido(cad);
        
        cout << "DNI: ";  
        cin >> n;
        p.setDDNI(n);
        
        cout << "Letra DNI: ";
        cin >> l;
        p.setLetraDNI(l);    
            
        cout << "Telefono: ";
        cin >> n;
        p.setTelefono(n);

                   
        cout << "Correo: ";
        cin >> cad;
        p.setCorreo(cad);
            
            do{
                cout << "Dia de nacimiento: ";
                cin >> n;
                       
            }while(n < 1 || n > 31);
            p.setDiaNacim(n);
            
           do{
                cout << "Mes de nacimiento: ";
                cin >> n;
                       
            }while(n < 1 || n > 12);
            p.setMesNacim(n);
            
            do{
                cout << "Año de nacimiento: ";
                cin >> n;
                     
            }while(n< 999 || n > 9999);
            p.setAnioNacim(n);
                               
    }
     
void PersonaUtil::muestraPersonaPantalla(const Persona &p){
    
    cout << p.getDDNI() << "-" << p.getLetraDNI() << endl;
    cout << p.getPrimerApellido() << endl;
    cout << p.getSegundoApellido() << endl;
    cout << p.getNombre() << endl;
}

 /**
       * @brief rellena un vector de personas
       * @param vp vector de personas
       * @param max numero maximo de personas
       * @post lee personas por teclado, las mete en vp hasta que el usuario decida
       * @return devuelve el nº de personas leidas
       */
      
int PersonaUtil::rellenaVector(Persona vp[], int max){
          
          char seguir = 's';
          int i=0;
          
          while(i<max && seguir == 's'){
              
              leePersonaTeclado(vp[i]);
              
              cout << "Pulsa 's' para seguir, otra tecla para terminar: ";
              cin >> seguir;
              i++;
              
          };
          
          return i;      
      }
      
      /**
       * @brief Muestra en pantalla el contenido del vector de personas
       * @param vp vector de personas
       * @param tama numero de personas
       * @pre tama > 0
       * @post muestra personas de 5 en 5
       */
      
void PersonaUtil::mostrarEnPantalla(const Persona vp[], int tama){
          
          char x;
          
          for(int i=0; i<tama; i++){
              
              muestraPersonaPantalla(vp[i]);
              
              if((i+1)%5 == 0){
                  
                  cout << "Pulsa una tecla para los siguientes 5: ";
                  cin >> x;
              }
          }
      }
      
      
      
      /**
       * @brief Buscar personas por primer apellido
       * @param ape apellido a buscar inicializado
       * @param vp vector de personas inicializado
       * @param tama numero de personas
       * @pre tama > 0
       * @post posicion de la persona o -1
       * @return entero con la posicion de la persona o -1 si no esta
       */
      
int PersonaUtil::buscar(const string &ape, const Persona vp[], int tama){
          
          for(int i=0; i< tama; i++){
              
                if(ape == vp[i].getPrimerApellido()){
                    
                    return i;
                }
           }
             return -1;
      }
      
      
      /**
       * @brief Ordena alfabeticamente el vector de personas por apellidos
       * @param vp vector de personas
       * @param tama numero de personas
       * @pre tama > 0
       */
      
void PersonaUtil::ordenar(Persona *vp, int tama){
          
          Persona aux;
          
          for(int i=1; i<tama; i++){
              
              for (int j=0; j<tama-i; j++){
                  
                  if(vp[j].getPrimerApellido() > vp[j+1].getPrimerApellido()){
                      
                      aux = vp[j];
                      
                      vp[j] = vp[j+1];
                      vp[j+1] = aux;
                  }
              }
          }
      }
