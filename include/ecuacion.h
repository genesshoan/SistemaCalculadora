#ifndef _ecuacion_H
#define _ecuacion_H

#include "string.h"
#include "grado.h"
#include "primergrado.h"
#include "segundogrado.h"

typedef struct {
    string ident;
    Grado discriminante;
    union {
        PrimerGrado primer;
        SegundoGrado segundo;
    } coeficientes;
}  Ecuacion;

/**
 * Descripción: Obtiene el grado de una ecuación.
 * 
 * Esta función devuelve el grado de la ecuación almacenado en la estructura.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion de la cual se obtendrá el grado.
 * 
 * Retorna:
 *   - El grado de la ecuación (primer o segundo grado).
 */
Grado DevolverGrado (Ecuacion ecu);

/**
 * Descripción: Obtiene el identificador de una ecuación.
 * 
 * Esta función devuelve el identificador de la ecuación en la variable pasada por referencia.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion que contiene el identificador.
 *   - str: Variable donde se almacenará el identificador de la ecuación.
 */
void DevolverIdentificador (Ecuacion ecu, string &str);

/**
 * Descripción: Obtiene los coeficientes de una ecuación de primer grado.
 * 
 * Esta función devuelve los coeficientes A y B de la ecuación de primer grado.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion que contiene los coeficientes.
 *   - coefa: Variable donde se almacenará el coeficiente A.
 *   - coefb: Variable donde se almacenará el coeficiente B.
 */
void DevolverCoeficientesPrimer (Ecuacion ecu, int &coefa, int &coefb);

/**
 * Descripción: Obtiene los coeficientes de una ecuación de segundo grado.
 * 
 * Esta función devuelve los coeficientes A, B y C de la ecuación de segundo grado.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion que contiene los coeficientes.
 *   - coefa: Variable donde se almacenará el coeficiente A.
 *   - coefb: Variable donde se almacenará el coeficiente B.
 *   - coefc: Variable donde se almacenará el coeficiente C.
 */
void DevolverCoeficientesSegundo (Ecuacion ecu, int &coefa, int &coefb, int &coefc);

/**
 * Descripción: Muestra la ecuación en pantalla.
 * 
 * Esta función imprime en pantalla la ecuación, ya sea de primer o segundo grado,
 * con su identificador y coeficientes correspondientes.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion que contiene la información de la ecuación.
 */
void mostrarEcuacion (Ecuacion ecu);

/**
 * Descripción: Compara si dos ecuaciones tienen el mismo grado.
 * 
 * Esta función verifica si dos ecuaciones tienen el mismo grado y devuelve un valor booleano.
 * 
 * Parámetros:
 *   - ecu1: Primera ecuación a comparar.
 *   - ecu2: Segunda ecuación a comparar.
 * 
 * Retorna:
 *   - `true` si ambas ecuaciones tienen el mismo grado, `false` en caso contrario.
 */
boolean mismoGrado (Ecuacion ecu1, Ecuacion ecu2);

/**
 * Descripción: Guarda una ecuación en un archivo.
 * 
 * Esta función almacena una ecuación en un archivo con el nombre especificado.
 * 
 * Parámetros:
 *   - ecu: La estructura de tipo Ecuacion que se desea guardar.
 *   - nombreArchivo: Nombre del archivo donde se almacenará la ecuación.
 */
void RespaldarEcuacion (Ecuacion ecu , string nombreArchivo);

/**
 * Descripción: Recupera una ecuación desde un archivo.
 * 
 * Esta función lee una ecuación desde un archivo con el nombre especificado y la devuelve.
 * 
 * Parámetros:
 *   - nomArch: Nombre del archivo del cual se recuperará la ecuación.
 * 
 * Retorna:
 *   - Una estructura de tipo Ecuacion con los datos recuperados.
 */
Ecuacion RecuperarEcuacion (string nomArch);

/**
 * Descripción: Crea una ecuación de primer grado.
 * 
 * Esta función crea una ecuación de primer grado con los coeficientes y el identificador especificados.
 * 
 * Parámetros:
 *   - coef: Estructura de tipo PrimerGrado con los coeficientes de la ecuación.
 *   - iden: Identificador de la ecuación.
 * 
 * Retorna:
 *   - Una estructura de tipo Ecuacion con los datos especificados.
 */
Ecuacion CrearEcuacionPrimerGrado (PrimerGrado coef, string iden);

/**
 * Descripción: Crea una ecuación de segundo grado.
 * 
 * Esta función crea una ecuación de segundo grado con los coeficientes y el identificador especificados.
 * 
 * Parámetros:
 *   - coef: Estructura de tipo SegundoGrado con los coeficientes de la ecuación.
 *   - iden: Identificador de la ecuación.
 * 
 * Retorna:
 *   - Una estructura de tipo Ecuacion con los datos especificados.
 */
Ecuacion CrearEcuacionSegundoGrado (SegundoGrado coef, string iden);

/**
 * Descripción: Suma dos ecuaciones de diferente grado.
 * 
 * Esta función suma dos ecuaciones de diferente grado y devuelve una nueva ecuación con el resultado.
 * 
 * Parámetros:
 *   - ecu1: Primera ecuación de segundo grado a sumar.
 *   - ecu2: Segunda ecuación de primer grado a sumar.
 *   - newident: Identificador de la nueva ecuación.
 * 
 * Retorna:
 *   - Una estructura de tipo Ecuacion con la suma de las dos ecuaciones.
 */
Ecuacion SumarEcucionesDiferenteGrado (SegundoGrado ecu1, PrimerGrado ecu2, string newident);



#endif