#ifndef _primergrado_H
#define _primergrado_H

#include <stdio.h>

/**
 * Definición del tipo PrimerGrado que representa una ecuación de primer grado.
 */
typedef struct {
    int coefA, coefB;
} PrimerGrado;

/**
 * Descripción: Obtiene los coeficientes de la ecuación de primer grado.
 * 
 * Esta función devuelve los coeficientes A y B de la ecuación.
 * 
 * Parámetros:
 *   - primer: La estructura de tipo PrimerGrado que contiene los coeficientes.
 *   - coefa: Variable donde se almacenará el coeficiente A.
 *   - coefb: Variable donde se almacenará el coeficiente B.
 */
void DevolverCoeficientesP (PrimerGrado primer,  int &coefa, int &coefb);

/**
 * Descripción: Obtiene el coeficiente A de la ecuación de primer grado.
 * 
 * Esta función devuelve el coeficiente A de la estructura PrimerGrado.
 * 
 * Parámetros:
 *   - primer: La estructura de tipo PrimerGrado que contiene el coeficiente A.
 * 
 * Retorna:
 *   - El coeficiente A de la ecuación.
 */
int DevolverCoefPrimerA (PrimerGrado primer);

/**
 * Descripción: Obtiene el coeficiente B de la ecuación de primer grado.
 * 
 * Esta función devuelve el coeficiente B de la estructura PrimerGrado.
 * 
 * Parámetros:
 *   - primer: La estructura de tipo PrimerGrado que contiene el coeficiente B.
 * 
 * Retorna:
 *   - El coeficiente B de la ecuación.
 */
int DevolverCoefPrimerB (PrimerGrado primer);


/**
 * Descripción: Resuelve la ecuación de primer grado ax + b = 0.
 * 
 * Esta función calcula la solución de la ecuación de primer grado utilizando
 * los coeficientes A y B de la estructura PrimerGrado.
 * 
 * Parámetros:
 *   - primer: La estructura de tipo PrimerGrado que contiene los coeficientes A y B.
 * 
 * Retorna:
 *   - El valor de la solución de la ecuación.
 */
float ResolverPrimerGrado (PrimerGrado primer);

/**
 * Descripción: Muestra los coeficientes de la ecuación de primer grado.
 * 
 * Esta función imprime los coeficientes A y B de la ecuación de primer grado.
 * 
 * Parámetros:
 *   - primer: La estructura de tipo PrimerGrado que contiene los coeficientes.
 */
void MostrarPrimerGrado (PrimerGrado primer);

/**
 * Descripción: Suma dos ecuaciones de primer grado.
 * 
 * Esta función suma dos ecuaciones de primer grado y devuelve una nueva ecuación
 * con los coeficientes resultantes.
 * 
 * Parámetros:
 *   - coef1: La estructura de tipo PrimerGrado que contiene los coeficientes de la primera ecuación.
 *   - coef2: La estructura de tipo PrimerGrado que contiene los coeficientes de la segunda ecuación.
 * 
 * Retorna:
 *   - Una nueva estructura de tipo PrimerGrado con los coeficientes de la suma.
 */
PrimerGrado SumarPrimerGrado (PrimerGrado coef1, PrimerGrado coef2);


#endif