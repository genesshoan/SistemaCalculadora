#include "comando.h"


void InsertarString (Comando &com, string str) {
    if (com == NULL) {
        Comando nuevo = new Nodo;
        strcrear(nuevo->info);
        strcop(nuevo->info, str);
        nuevo -> sig = com;
        com = nuevo;
    }
    else
        if (com -> sig == NULL){
            Comando nuevo = new Nodo;
            strcrear(nuevo->info);
            strcop(nuevo->info, str);
            nuevo -> sig = NULL;
            com -> sig = nuevo;
        }
        else
            InsertarString(com -> sig, str);
}

void partirString (Comando &com, string str) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            string straux;
            strcrear(straux);
            while (str[i] != ' ' && str[i] != '\0') {
                AgregarCaracter(straux, str[i]);
                i++;
            }
            InsertarString(com, straux);
            strdestruir(straux);
        }
        else
            i++;
    }
}

boolean restoListaesNumerica(Comando com) {
    boolean numerica = TRUE;
    com = com->sig;
    while (com != NULL && numerica) {
        if (!esNumerico(com->info))
            numerica = FALSE;
        com = com->sig;
    }
    return numerica;
}

int cantidadStrings (Comando com){
    int contador = 0;
    while (com != NULL)
    {
        contador++;
        com = com->sig;
    }
    return contador;
}

string obtenerStringComando (Comando com, int pos){
    int cont = 0;
    while (cont != pos) {
        com = com->sig;
        cont++;
    }
    return com->info;
}

void crearLista (Comando &com){
    com = NULL;
}

void vaciarLista (Comando &com){
    Comando aux;
    while (com != NULL)
    {
        strdestruir(com->info);
        aux = com;
        com = com->sig;
        delete aux;
    }
    com = NULL;
}


void MostrarComando (Comando com) {
    printf("Comando:\n");
    while (com != NULL) {
        print(com->info);
        printf("\n");
        com = com->sig;
    }
}

boolean ComadoVacio (Comando com) {
    return (boolean)(com == NULL);
}

