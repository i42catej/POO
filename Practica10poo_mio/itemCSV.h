#ifndef ITEMCSV_H
#define ITEMCSV_H

#include <string>

using namespace std;

class itemCSV
{
    public:
        virtual string toCSV()=0;     /** ˇˇIMPORTANTE EXAMEN!!*/
        virtual void fromCSV( string s )=0;     /** ˇˇIMPORTANTE EXAMEN!!*/
        virtual ~itemCSV(){};     /** ˇˇIMPORTANTE EXAMEN!!*/
};

#endif // ITEMCSV_H
