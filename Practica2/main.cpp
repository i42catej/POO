/**@fire
   @author
   @date
 */
#include <cstdlib>
#include <iostream>
#include "Persona.h"
using namespace std;
using namespace poo_pr2;
/**@brief Programa principal*/
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
    
    Persona *v;
    int n,i,t,pos;
    string ap,nom;
    do{
        cout<<"Introduzca tamano: ";
        cin>>n;
    } while (n<=0);
    v=new Persona [n];
    t= rellenaVector(v,n);
    muestraPersonaPantalla(v,t);
    cout<<"Media: "<<mediaEdad(v,t);
    cout<<"Introduce apellidos: ";
    getline(cin>>ws, ap);
    pos=buscar(ap,v,t);
    
    if (pos!=-1) {
        cout<<"Introduce nuevo nombre: ";
        getline(cin>>ws,nom);
        v[pos].nombre=nom;
        delete []v;
        return 0;
    }
    
}
