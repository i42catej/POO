/* 
 * File:   Persona.h
 * Author: Francisco
 *
 * Created on 3 de marzo de 2014, 17:37
 */

#ifndef PERSONA_H
#define	PERSONA_H

#include <iostream>
#include <string>

using namespace std;
    
    class Persona{
    
    private:
        static int ID;
        int id;
        
        string primerApellido;
        string nombre;
        string segundoApellido;
        int telefono;
        string correo;
        int diaNacim;
        int mesNacim;
        int anioNacim;
        int DNI;
        char letraDNI;
     
        
   public:
       Persona() {
                ID++;
                id=ID;
                cout << "Construyendo Persona: " << id << endl;
       };
       Persona(string nnombre, string pprimerAp, int ddni, char lletradni):
       nombre(nnombre), primerApellido(pprimerAp), DNI(ddni), letraDNI(lletradni) {
                ID++;
                id=ID;
                cout << "Construyendo Persona: " << id << endl;
       };
       string getPrimerApellido()const { return primerApellido;};
       string getNombre()const{ return nombre;};
       string getSegundoApellido() const{ return segundoApellido;};
       int getTelefono()const{ return telefono;};
       string getCorreo()const{ return correo;};
       int getDiaNacim()const{ return diaNacim;};
       int getMesNacim()const{ return mesNacim;};
       int getAnioNacim()const{ return anioNacim;};
       int getDDNI()const{ return DNI;};
       char getLetraDNI()const{ return letraDNI;};
       int getiid()const{ return id;};
       
       void setPrimerApellido(string pprimerApellido){ primerApellido=pprimerApellido;};
       void setNombre(string nnombre){ nombre=nnombre; };
       void setSegundoApellido(string ssegundoApellido){ segundoApellido=ssegundoApellido;};
       void setTelefono(int ttelefono){ telefono=ttelefono; };
       void setCorreo(string ccorreo){ correo=ccorreo; };
       void setDiaNacim(int ddiaNacim){ diaNacim=ddiaNacim; };
       void setMesNacim(int mmesNacim){ mesNacim=mmesNacim; };
       void setAnioNacim(int aanioNacim){ anioNacim=aanioNacim; };
       void setDDNI(int DDNI){ DNI=DDNI; };
       void setLetraDNI(char lletraDNI){ letraDNI=lletraDNI; };
       void setIID(int IID){ id=IID; };
     
    
};



#endif	/* PERSONA_H */

