#include "ecuacion.h"

Grado DevolverGrado(Ecuacion ecu) {
    return ecu.discriminante;
}

void DevolverIdentificador (Ecuacion ecu, string &str) {
    strcrear(str);
    strcop(str, ecu.ident);
}

void DevolverCoeficientesPrimer (Ecuacion ecu, int &coefa, int &coefb){
    coefa = ecu.coeficientes.primer.coefA;
    coefb = ecu.coeficientes.primer.coefB;
}

void DevolverCoeficientesSegundo (Ecuacion ecu, int &coefa, int &coefb, int &coefc) {
    coefa = ecu.coeficientes.segundo.coefA;
    coefb = ecu.coeficientes.segundo.coefB;
    coefc = ecu.coeficientes.segundo.coefC;
}

void mostrarEcuacion(Ecuacion ecu) {
    print(ecu.ident);
    printf(": ");
    if(DevolverGrado(ecu)==PRIMER)
        MostrarPrimerGrado(ecu.coeficientes.primer);
    else  
        MostrarSegundoGrado(ecu.coeficientes.segundo);
}

boolean mismoGrado(Ecuacion ecu1, Ecuacion ecu2) {
    return (boolean)(DevolverGrado(ecu1) == DevolverGrado(ecu2));
}


void RespaldarEcuacion(Ecuacion ecu, string nombreArchivo) {
    FILE * file = fopen(nombreArchivo, "wb");
    
    Bajar_String(ecu.ident, file);
    fwrite(&ecu.discriminante, sizeof(Grado), 1, file);
    if (DevolverGrado(ecu) == PRIMER)
        fwrite(&ecu.coeficientes.primer, sizeof(PrimerGrado), 1, file);
    else
        fwrite(&ecu.coeficientes.segundo, sizeof(SegundoGrado), 1, file);
    fclose(file);
}
    

Ecuacion RecuperarEcuacion (string nomArch){
    Ecuacion ecu;
    FILE * f = fopen(nomArch, "rb");
    strcrear(ecu.ident);
    Levantar_String(ecu.ident, f);
    fread(&ecu.discriminante, sizeof(Grado), 1, f);
    if(DevolverGrado(ecu) == PRIMER)
        fread(&ecu.coeficientes.primer, sizeof(PrimerGrado), 1, f);
    else 
        fread(&ecu.coeficientes.segundo, sizeof(SegundoGrado), 1, f);
    fclose(f);
    return ecu;         
}

Ecuacion CrearEcuacionPrimerGrado (PrimerGrado coef, string iden) {
    Ecuacion nueva;
    nueva.discriminante = PRIMER;
    nueva.coeficientes.primer = coef;
    strcrear(nueva.ident);
    strcop(nueva.ident, iden);

    return nueva;
}

Ecuacion CrearEcuacionSegundoGrado (SegundoGrado coef, string iden) {
    Ecuacion nueva;
    nueva.discriminante = SEGUNDO;
    nueva.coeficientes.segundo = coef;
    strcrear(nueva.ident);
    strcop(nueva.ident, iden);

    return nueva;
}

Ecuacion SumarEcucionesDiferenteGrado (SegundoGrado ecu1, PrimerGrado ecu2, string newident) {
    Ecuacion nuevaEcu;
    nuevaEcu.discriminante = SEGUNDO;
    nuevaEcu.coeficientes.segundo.coefA = ecu1.coefA;
    nuevaEcu.coeficientes.segundo.coefB = DevolverCoefSegundoB(ecu1) + DevolverCoefPrimerA(ecu2);
    nuevaEcu.coeficientes.segundo.coefC = DevolverCoefSegundoC(ecu1) + DevolverCoefPrimerB(ecu2);
    strcrear(nuevaEcu.ident);
    strcop(nuevaEcu.ident, newident);

    return nuevaEcu;
}
