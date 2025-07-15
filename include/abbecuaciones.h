#ifndef _abbecuaciones_H
#define _abbecuaciones_H

#include "ecuacion.h"

/**
 * Descripción: Tipo de dato que representa un árbol de ecuaciones.
 * 
 * Este tipo de dato representa un árbol de ecuaciones, donde cada nodo contiene una ecuación.
 */
typedef struct NodoA {
    Ecuacion info;
    NodoA * hizq;
    NodoA * hder;
} NodoArbol;
        
typedef NodoArbol * ABBEcuaciones;

/**
 * Descripción: Verifica si un identificador existe en el árbol.
 * 
 * Esta función verifica si un identificador existe en el árbol de ecuaciones.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones donde se buscará el identificador.
 * - str: El identificador que se buscará en el árbol.
 * 
 * Retorna:
 * - TRUE si el identificador existe en el árbol, FALSE en caso contrario.
 */
boolean existeIdentificador (ABBEcuaciones abb, string str);

/**
 * Descripción: Inserta una ecuación en el árbol.
 * 
 * Esta función inserta una ecuación en el árbol de ecuaciones.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones donde se insertará la ecuación.
 * - ecu: La ecuación que se insertará en el árbol.
 * 
 * Precondición:
 * - Que no exista una ecuación con el mismo identificador en el árbol.
 */
void insertarEcuacion (ABBEcuaciones &abb, Ecuacion ecu);

/**
 * Descripción: Muestra todas las ecuaciones del árbol.
 * 
 * Esta función muestra todas las ecuaciones almacenadas en el árbol.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones que se mostrará.
 */
void mostrarABBEcuaciones (ABBEcuaciones abb);

/**
 * Descripción: Verifica si el árbol está vacío.
 * 
 * Esta función verifica si el árbol de ecuaciones está vacío.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones que se verificará.
 * 
 * Retorna:
 * - TRUE si el árbol está vacío, FALSE en caso contrario.
 */
boolean esVacio (ABBEcuaciones abb);

/**
 * Descripción: Crea un árbol de ecuaciones vacío.
 * 
 * Esta función crea un árbol de ecuaciones vacío, apuntando el puntero a NULL.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones que se creará.
 */
void crearAbb (ABBEcuaciones &abb);

/**
 * Descripción: Vacia un árbol de ecuaciones.
 * 
 * Esta función vacía un árbol de ecuaciones liberando la memoria utilizada.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones que se vaciará.
 */
void vaciarAbb (ABBEcuaciones &abb);

/**
 * Descripción: Obtiene una ecuación del árbol.
 * 
 * Esta función obtiene una ecuación del árbol de ecuaciones.
 * 
 * Parámetros:
 * - abb: El árbol de ecuaciones donde se buscará la ecuación.
 * - id: El identificador de la ecuación que se buscará en el árbol.
 * 
 * Retorna:
 * - La ecuación que se encuentra en el árbol con el identificador especificado.
 * 
 * Precondición:
 * - Que exista una ecuación con el identificador especificado en el árbol.
 */
Ecuacion obtenerEcuacion (ABBEcuaciones abb, string id);



#endif