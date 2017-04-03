#include <iostream>
#include <string>

using namespace std;

    struct Persona{
        
        string nombre, apellidos, DNI;
        int edad;
        
    };
    
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
            cin >> p.DNI;
            
        }while(p.DNI.length() != 9);
        
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
            cin >> p->DNI;
            
        }while(p->DNI.length() != 9);
        
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
          
          cout << p.nombre << " " << p.apellidos << " " << p.DNI << " " << p.edad;
      }
      
      /**
       * @brief Muestra los datos de una persona
       * @param p puntero a un registro persona
       * @pre que p puntero a persona este inicializado
       * @post Muestra por pantalla los datos de una persona p
       */

      void muestraPersonaPantalla(const Persona *p){
          
          cout << p->nombre << " " << p->apellidos << " " << p->DNI << " " << p->edad;
      }

int main() {

    const int MAX_PERSONAS = 100;
    int n, suma=0;
    
    Persona v[MAX_PERSONAS];
    
    do{
        cout << "Introduce el numero de personas, maximo 100: ";
        cin >> n;
        
    }while(n<=0 || n > MAX_PERSONAS);
    
    for(int i=0; i<n; i++){
        
        leePersonaTeclado(v[i]);
        
        suma += v[i].edad;
    }
    
    for(int i=0; i<n; i++){
        
        muestraPersonaPantalla(v[i]);
        
    }

    cout << "Media: " << suma/n;
    
    return 0;
}

