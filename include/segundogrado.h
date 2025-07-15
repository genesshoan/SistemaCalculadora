#ifndef _segundogrado_H
#define _segundogrado_H

#include <math.h>
#include <stdio.h>

/**
 * Definición del tipo SegundoGrado que representa una ecuación de segundo grado.
 */
typedef struct {
    int coefA, coefB, coefC;
} SegundoGrado;

/**
 * Descripción: Obtiene los coeficientes de la ecuación de segundo grado.
 * 
 * Esta función devuelve los coeficientes A, B y C de la ecuación.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado de la cual se extraerán los coeficientes.
 *   - coefa: Variable donde se almacenará el coeficiente A.
 *   - coefb: Variable donde se almacenará el coeficiente B.
 *   - coefc: Variable donde se almacenará el coeficiente C.
 */

void DevolverCoeficientesS (SegundoGrado segundo,  int &coefa, int &coefb, int &coefc);

/**
 * Descripción: Obtiene el coeficiente A de la ecuación de segundo grado.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado.
 * 
 * Retorna: El coeficiente A de la ecuación.
 */
int DevolverCoefSegundoA (SegundoGrado segundo);

/**
 * Descripción: Obtiene el coeficiente B de la ecuación de segundo grado.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado.
 * 
 * Retorna: El coeficiente B de la ecuación.
 */
int DevolverCoefSegundoB (SegundoGrado segundo);

/**
 * Descripción: Obtiene el coeficiente C de la ecuación de segundo grado.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado.
 * 
 * Retorna: El coeficiente C de la ecuación.
 */
int DevolverCoefSegundoC (SegundoGrado segundo);

/**
 * Descripción: Determina el número de soluciones reales de la ecuación de segundo grado.
 * 
 * Esta función calcula cuántas soluciones reales tiene la ecuación basándose en su discriminante.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado.
 * 
 * Retorna: El número de soluciones reales de la ecuación (0, 1 o 2).
 */
int NmroDeSoluciones (SegundoGrado segundo);

/**
 * Descripción: Resuelve la ecuación de segundo grado cuando tiene dos soluciones reales distintas.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado a resolver.
 *   - x1: Variable donde se almacenará la primera solución.
 *   - x2: Variable donde se almacenará la segunda solución.
 * 
 * Precondición: La ecuación debe estar correctamente inicializada y debe tener dos soluciones reales distintas.
 */
void ResolverSegundoGrado2Soluciones (SegundoGrado segundo, float &x1, float &x2);

/**
 * Descripción: Resuelve la ecuación de segundo grado cuando tiene una única solución real.
 * 
 * Parámetros:
 *   - segundo: La ecuación de segundo grado a resolver.
 * 
 * Precondición: La ecuación debe estar correctamente inicializada y debe tener una única solución real.
 * 
 * Retorna: La solución única de la ecuación.
 */
float ResloverSegundoGrado1Solucion (SegundoGrado segundo);

/**
 * Descripción: Muestra los coeficientes de una ecuación de segundo grado.
 * 
 * Esta función imprime en pantalla los coeficientes A, B y C de la ecuación
 * de segundo grado proporcionada.
 * 
 * Parámetros:
 *   - seg: La estructura de tipo SegundoGrado que contiene los coeficientes de la ecuación.
 */
void MostrarSegundoGrado (SegundoGrado seg);

/**
 * Descripción: Suma dos ecuaciones de segundo grado.
 * 
 * Esta función suma dos ecuaciones de segundo grado y devuelve el resultado.
 * 
 * Parámetros:
 *   - seg1: La primera ecuación de segundo grado.
 *   - seg2: La segunda ecuación de segundo grado.
 * 
 * Retorna: La ecuación de segundo grado resultante de la suma.
 */
SegundoGrado SumarSegundoGrado (SegundoGrado seg1, SegundoGrado seg2);

#endif