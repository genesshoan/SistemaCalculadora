#include "abbecuaciones.h"

boolean existeIdentificador(ABBEcuaciones abb, string str) {
    if (abb == NULL)
        return FALSE;
    else 
        if (streq(str, abb->info.ident))
            return TRUE;
        else
            if (strmen(str, abb->info.ident))
                return existeIdentificador(abb->hizq, str);
            else
                return existeIdentificador(abb->hder, str);
}

void insertarEcuacion (ABBEcuaciones &abb, Ecuacion ecu) {
    if(abb==NULL) {
        abb = new NodoArbol;
        abb->info = ecu;
        abb->hizq = NULL;
        abb->hder = NULL;
    }
    else 
        if(strmen(ecu.ident, abb->info.ident))
            insertarEcuacion(abb->hizq, ecu);
        else
            insertarEcuacion(abb->hder, ecu);
}

void mostrarABBEcuaciones (ABBEcuaciones abb){
    if (abb != NULL){
        mostrarABBEcuaciones(abb -> hizq);
        mostrarEcuacion(abb -> info);
        mostrarABBEcuaciones(abb -> hder);
    }
}

boolean esVacio(ABBEcuaciones abb) {
    return (boolean)(abb == NULL);
}

void crearAbb (ABBEcuaciones &abb){
    abb = NULL;
}

void vaciarAbb (ABBEcuaciones &abb){
    if (abb != NULL){
        vaciarAbb(abb -> hizq);
        vaciarAbb(abb -> hder);
        strdestruir (abb -> info.ident);
        delete abb;
        abb = NULL;
    }
}

Ecuacion obtenerEcuacion(ABBEcuaciones abb, string id) {
    if (streq(id, abb->info.ident))
        return abb->info;
    else
        if (strmen(id, abb->info.ident))
            return obtenerEcuacion(abb->hizq, id);
        else
            return obtenerEcuacion(abb->hder, id);
}
