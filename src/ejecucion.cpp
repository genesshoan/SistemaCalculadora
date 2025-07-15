#include "ejecucion.h"

boolean existeArchivo(string nombreArchivo) {
    boolean existe = TRUE;
    FILE * file = fopen(nombreArchivo, "rb");

    if (file == NULL)
        existe = FALSE;
    else
        fclose(file);

    return existe;
}

void EjecutarCrear(Comando parametros, ABBEcuaciones &abb)
{
    int cantparametros = cantidadStrings(parametros);
    if (!(cantparametros >= 4 && cantparametros <= 5))
        printf("[ ERROR ]: La cantidad de parametros es incorrecta.\n");
    else
    {
        if (!esAlfabetico(obtenerStringComando(parametros, 1)))
        {
            printf("[ ERROR ]: El identificador o nombre de la ecuacion solo debe contener letras.\n");
        }
        else
        {
            if (!restoListaesNumerica(parametros->sig))
            {
                printf("[ ERROR ]: Solo se admiten coeficientes enteros.\n");
            }
            else
            {
                if (!distintoCero(obtenerStringComando(parametros, 2)))
                {
                    printf("[ ERROR ]: El coeficiente principal de la ecuacion no puede ser cero.\n");
                }
                else
                {
                    if (existeIdentificador(abb, obtenerStringComando(parametros, 1)))
                    {
                        printf("[ ERROR ]: Ya existe una ecuacion con el mismo identificador cargado en el programa, por favor intente con uno diferente.\n");
                    }
                    else
                    {
                        Ecuacion ecu;
                        strcrear(ecu.ident);
                        strcop(ecu.ident, obtenerStringComando(parametros, 1));

                        if (cantparametros == 4)
                        {
                            ecu.discriminante = PRIMER;
                            ecu.coeficientes.primer.coefA = convertirStringNumerico(obtenerStringComando(parametros, 2));
                            ecu.coeficientes.primer.coefB = convertirStringNumerico(obtenerStringComando(parametros, 3));
                        }
                        else
                        {
                            ecu.discriminante = SEGUNDO;
                            ecu.coeficientes.segundo.coefA = convertirStringNumerico(obtenerStringComando(parametros, 2));
                            ecu.coeficientes.segundo.coefB = convertirStringNumerico(obtenerStringComando(parametros, 3));
                            ecu.coeficientes.segundo.coefC = convertirStringNumerico(obtenerStringComando(parametros, 4));
                        }

                        insertarEcuacion(abb, ecu);
                        mostrarEcuacion(ecu);
                    }
                }
            }
        }
    }
}

void EjecutarMostrar (Comando parametros, ABBEcuaciones abb){
    int cantparametros = cantidadStrings(parametros);
    if(cantparametros != 1)
        printf("[ ERROR ]: La cantidad de parametros es incorrecta.\n");
    else
    {
        if(esVacio(abb))
            printf("[ ERROR ]: No existen ecuciones en el sistema.\n");
        else
            mostrarABBEcuaciones(abb);
    }
}

void EjecutarResolver(Comando parametros, ABBEcuaciones abb) {
    string auxident;
    strcrear(auxident);
    strcop(auxident, obtenerStringComando(parametros, 1));
    if (cantidadStrings(parametros) != 2)
        printf("[ ERROR ]: La cantidad de parametros en incorrecta. Deben de ser dos, tal que \"resolver ident\".\n");
    else
    {
        if (!esAlfabetico(auxident))
        {
            printf("[ ERROR ]: El identificador debe contener solo letras y asegurese de no utilizar acentos.\n");
        }
        else
        {
            if (!existeIdentificador(abb, auxident))
            {
                printf("[ ERROR ]: No existe ecuacion cargada con el identificador ingresado, ingrese \"mostrar\" para ver las ecuaciones disponibles actualmente.\n");
            }
            else
            {
                Ecuacion auxecu = obtenerEcuacion(abb, auxident);
                if (DevolverGrado(auxecu) == PRIMER)
                {
                    printf("[ Resultado ]: x = %.2f\n", ResolverPrimerGrado(auxecu.coeficientes.primer));
                }
                else
                {
                    int numerosoluciones = NmroDeSoluciones(auxecu.coeficientes.segundo);
                    switch (numerosoluciones)
                    {
                    case 0:
                        printf("[ Resultado ]: No existen soluciones en los reales para esta ecuacion.\n");
                        break;
                    case 1:
                        printf("[ Resultado ]: x = %.2f.\n", ResloverSegundoGrado1Solucion(auxecu.coeficientes.segundo));
                        break;
                    case 2:
                        float x1, x2;
                        ResolverSegundoGrado2Soluciones(auxecu.coeficientes.segundo, x1, x2);
                        printf("[ Resultado ]: x1 = %.2f, x2 = %.2f.\n", x1, x2);
                    }
                }
            }
        }
    }
    strdestruir(auxident);
}

void EjecutarSumar (Comando parametros, ABBEcuaciones &abb)
{
    string ident1, ident2, ident3;
    strcrear(ident1);
    strcrear(ident2);
    strcrear(ident3);

    boolean SumadoConExito = FALSE;

	if(cantidadStrings(parametros) !=4)
		printf("[ ERROR ] La cantidad de Parametros es incorrecta. Debe ingresar dos parametros tal que \"sumar ident1 ident2 ident3\".\n");
	else
	{
        strcop(ident1, obtenerStringComando(parametros, 1));
        strcop(ident2, obtenerStringComando(parametros, 2));
        strcop(ident3, obtenerStringComando(parametros, 3));
		if(!esAlfabetico(ident1) || !esAlfabetico(ident2) || !esAlfabetico(ident3))
			printf("[ ERROR ]: Hay al menos un identificador que no es alfabetico, verifique que los identificadores tengan solo letras y sin acentos.\n");
		else
		{
			if(!existeIdentificador(abb, ident1) || !existeIdentificador(abb, ident2))
				printf("[ ERROR ]: No se ha encontrado al menos una de las dos ecuacioness al sumar.\n");
			else
			{
				if (existeIdentificador(abb, ident3))
					printf("[ ERROR ]: El 3er itentificador ya existe en memoria. Ingrese \"mostrar\" para ver las ecuaciones existentes.\n");
				else
				{
					Ecuacion nuevaEcu;
                    Ecuacion ecu1, ecu2;
                    ecu1 = obtenerEcuacion(abb, ident1);
					ecu2 = obtenerEcuacion(abb, ident2);
                    if(mismoGrado(ecu1, ecu2))
					{
						Grado grado = DevolverGrado(ecu1);
						if(grado == PRIMER)
						{
							PrimerGrado suma = SumarPrimerGrado(ecu1.coeficientes.primer, ecu2.coeficientes.primer);
							if(DevolverCoefPrimerA(suma) == 0)
								printf("[ ERROR ]: la suma de los coeficientes principales es 0.\n");
							else
							{
							    nuevaEcu = CrearEcuacionPrimerGrado(suma, ident3);
                                insertarEcuacion(abb, nuevaEcu);
                                SumadoConExito = TRUE;
							}
                        }
						else
                        {
							SegundoGrado suma = SumarSegundoGrado(ecu1.coeficientes.segundo, ecu2.coeficientes.segundo);

							if(DevolverCoefSegundoA(suma) == 0)
                            {
                                if (DevolverCoefSegundoB(suma) == 0)
                                {
                                    printf("[ ERROR ]: La suma de los coeficientes principales es 0.\n");
                                }
                                else
                                {
                                    PrimerGrado nueva = { DevolverCoefSegundoB(suma), DevolverCoefSegundoC(suma) };
                                    nuevaEcu = CrearEcuacionPrimerGrado(nueva, ident3);
                                    insertarEcuacion(abb, nuevaEcu);
                                    SumadoConExito = TRUE;
                                }
                            }
							else
							{
								nuevaEcu = CrearEcuacionSegundoGrado(suma, ident3);
                                insertarEcuacion(abb, nuevaEcu);
                                SumadoConExito = TRUE;
							}
                        }
                    }
					else
					{
						Grado gradoecu1 = DevolverGrado(ecu1);
						if(gradoecu1 == SEGUNDO)
						{
                            nuevaEcu = SumarEcucionesDiferenteGrado(ecu1.coeficientes.segundo, ecu2.coeficientes.primer, ident3);
						}
						else
						{
            				nuevaEcu = SumarEcucionesDiferenteGrado(ecu2.coeficientes.segundo, ecu1.coeficientes.primer, ident3);
						}
                        insertarEcuacion(abb, nuevaEcu);
                        SumadoConExito = TRUE;
					}
				}
			}
		}
    }

    if(SumadoConExito)
    {
        printf("[ MENSAJE ]: La suma de las ecuaciones se ha realizado con exito.\n");
        mostrarEcuacion(obtenerEcuacion(abb, ident3));
    }

    strdestruir(ident1);
    strdestruir(ident2);
    strdestruir(ident3);
}


void EjecutarGuardar (Comando parametros, ABBEcuaciones abb){
    string iden, nomArch;
    strcrear(iden);
    strcrear(nomArch);
    strcop(nomArch, obtenerStringComando(parametros, 1));
    strcop(iden, obtenerStringComando(parametros, 1));

    if(cantidadStrings(parametros) != 2)
        printf("[ ERROR ] La cantidad de Parametros es incorrecta. Debe ingresar dos parametros tal que \"guardar ident\".\n");
    else{
        if(!esAlfabetico(iden))
            printf("[ ERROR ] El idetificador tiene que ser alfabetico, verifique que el identificador tenga solo letras y sin acentos.\n");
        else{
            if(!existeIdentificador(abb, iden))
                printf("[ ERROR ] No existe una ecuacion con el identificador.\n");
            else{
                agregarExtencion(nomArch);
                if(existeArchivo(nomArch))
                    printf("[ ERROR ] Ya existe una ecuacion en disco con este identifocador. \n");
                else{
                    Ecuacion ecu = obtenerEcuacion(abb, iden);
                    RespaldarEcuacion(ecu, nomArch);
                    printf("[ MENSAJE ]: Ecuacion guardada exitosamente.\n");
                }
            }
        }
    }
    strdestruir(nomArch);
    strdestruir(iden);
}

void EjecutarRecuperar(Comando parametros, ABBEcuaciones &abb) {
    string iden, nomArch;
    strcrear(iden);
    strcrear(nomArch);
    strcop(nomArch, obtenerStringComando(parametros, 1));
    strcop(iden, obtenerStringComando(parametros, 1));
    if (cantidadStrings(parametros) != 2)
    {
        printf("[ ERROR ] La cantidad de Parametros es incorrecta. Debe ingresar dos parametros tal que \"recuperar ident\".\n");
    }
    else
    {
        if (!esAlfabetico(iden))
        {
            printf("[ ERROR ]: El identificador debe contener solo letras y asegurese de no utilizar acentos.\n");
        }
        else
        {
            agregarExtencion(nomArch);
            if (!existeArchivo(nomArch))
            {
                printf("[ ERROR ]: No se encontro ninguna ecuacion en disco con ese identificador.\n");
            }
            else
            {
                if (existeIdentificador(abb, iden))
                {
                    printf("[ ERROR ]: No se puede recuperar, porque ya exite una ecuacion con el mismo identificador en el programa.\n");
                }
                else
                {
                    Ecuacion ecu = RecuperarEcuacion(nomArch);
                    insertarEcuacion(abb, ecu);
                    mostrarEcuacion(ecu);
                }
            }
        }
    }
    strdestruir(nomArch);
    strdestruir(iden);
}

void EjecutarSalir(Comando &parametros, ABBEcuaciones &abb, boolean &salir) {
    if (cantidadStrings(parametros) != 1)
    {
        printf("[ ERROR ] La cantidad de Parametros es incorrecta. Debe ingresar un parametro tal que \"salir\".\n");
    }
    else
    {
        vaciarAbb(abb);
        vaciarLista(parametros);
        printf("[ MENSAJE ]: Hasta la proxima!\n");
        salir = TRUE;
    }
}
