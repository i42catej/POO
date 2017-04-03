#ifndef MAYOR_H_INCLUDED
#define MAYOR_H_INCLUDED

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 1 */

//Utilizable SOLO por aquellos objetos que tengan definidos el operator> y operator=

template <typename T>
T& mayorVector (T v[], int tam) {
    T mayor=v[0];
    for (int i=1;i<tam; i++) {
        if (v[i]>mayor)
            mayor=v[i];
    }
    return mayor;
}

/** ¡¡IMPORTANTE EXAMEN!! PRACTICA 10. apto. 4 */

//Utilizable SOLO por aquellos objetos que tengan definidos el operator> y operator=
template <typename T>
T& mayorVectorSTL (vector<T> v) {
    T mayor=v.at(0);
    for (int i=1;i<v.size(); i++) {
        if (v.at(i)>mayor)
            mayor=v.at(i);
    }
    return mayor;
}

#endif // MAYOR_H_INCLUDED
