#ifndef _ejecucion_H
#define _ejecucion_H

#include "abbecuaciones.h"
#include "comando.h"

boolean existeArchivo (string nombreArchivo);
void EjecutarCrear (Comando parametros, ABBEcuaciones &abb);
void EjecutarMostrar (Comando parametros, ABBEcuaciones abb);
void EjecutarResolver (Comando parametros, ABBEcuaciones abb);
void EjecutarSumar (Comando parametros, ABBEcuaciones &abb);
void EjecutarGuardar (Comando parametros, ABBEcuaciones abb);
void EjecutarRecuperar (Comando parametros, ABBEcuaciones &abb);
void EjecutarSalir (Comando &parametros, ABBEcuaciones &abb, boolean &salir);



#endif
