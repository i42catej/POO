#ifndef ITEMCSV_H
#define ITEMCSV_H

#include <string>

using namespace std;

class itemCSV
{
    public:
        virtual string toCSV()=0;     /** ¡¡IMPORTANTE EXAMEN!!*/
        virtual void fromCSV( string s )=0;     /** ¡¡IMPORTANTE EXAMEN!!*/
        virtual ~itemCSV(){};     /** ¡¡IMPORTANTE EXAMEN!!*/
};

#endif // ITEMCSV_H
