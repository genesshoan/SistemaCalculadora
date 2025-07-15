#include "ejecucion.h"

int main()
{
    boolean salir = FALSE;
    string str;
    Comando com;
    ABBEcuaciones abb;

    crearAbb(abb);
    crearLista(com);

    do {
        printf("Ingrese comando: ");
        strcrear(str);
        scan(str);
        partirString(com, str);

        string aux;

        if (ComadoVacio(com))
            printf("[ ERROR ]: Se ha ingresado una entrada vacia.\n");
        else
        {
            aux = obtenerStringComando(com, 0);

            if (streq(aux, "crear"))
                EjecutarCrear(com, abb);
            else
            {
                if (streq(aux, "mostrar"))
                    EjecutarMostrar(com, abb);
                else
                {
                    if (streq(aux, "resolver"))
                        EjecutarResolver(com, abb);
                    else
                    {
                        if (streq(aux, "sumar"))
                            EjecutarSumar(com, abb);
                        else
                        {
                            if (streq(aux, "guardar"))
                                EjecutarGuardar(com, abb);
                            else
                            {
                                if (streq(aux, "recuperar"))
                                    EjecutarRecuperar(com, abb);
                                else
                                {
                                    if (streq(aux, "salir"))
                                    {
                                        EjecutarSalir(com, abb, salir);
                                    }
                                    else
                                        printf("[ ERROR ]: No se ha ingresado un comando valido.\n");
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!salir)
            vaciarLista(com);
        aux = NULL;
        strdestruir(str);
    } while (!salir);
}
