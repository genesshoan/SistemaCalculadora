#ifndef _comando_H
#define _comando_H

#include "string.h"

typedef struct NodoL {
    string info;
    NodoL * sig;
} Nodo;
typedef Nodo * Comando;


void InsertarString (Comando &com, string str);

void partirString (Comando &com, string str);

boolean restoListaesNumerica (Comando com);

int cantidadStrings (Comando com);

string obtenerStringComando (Comando com, int pos);

void crearLista (Comando &com);

void vaciarLista (Comando &com);

void MostrarComando (Comando com);

boolean ComadoVacio (Comando com);


#endif
