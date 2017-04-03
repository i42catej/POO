#ifndef PERSONA_H
#define	PERSONA_H
#include <string>
using namespace std;
namespace poo_pr2{
    struct Persona{
        string nombre;
        string apellidos;
        string dni;
        int edad;
    };
    void muestraPersonaPantalla(const Persona *p);
    void leePersonaTeclado(Persona &p);
    void leePersonaTeclado(Persona *p);
    void vizualiza(const Persona v[],int tam);
    int rellenaVector(Persona vp[],int max);
    float mediaEdad(const Persona vp[],int tam);
    int buscar(const string apellidos, const Persona vp[], int tam);
    void masmenos(const Persona vp[],int tama,int &pmayor,int &pmenor);
    void ordenar(const Persona vp[],int tama);
   };


#endif	/* PERSONA_H */

