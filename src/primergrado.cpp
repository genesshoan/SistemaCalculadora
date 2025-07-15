#include "primergrado.h"

void DevolverCoeficientesP(PrimerGrado primer, int &coefa, int &coefb) {
    coefa = primer.coefA;
    coefb = primer.coefB;
}

int DevolverCoefPrimerA(PrimerGrado primer) {
    return primer.coefA;
}

int DevolverCoefPrimerB(PrimerGrado primer) {
    return primer.coefB;
}

float ResolverPrimerGrado(PrimerGrado primer) {
    int a = DevolverCoefPrimerA(primer);
    int b = DevolverCoefPrimerB(primer);
    return ((-b) / (float)a);
}

void MostrarPrimerGrado (PrimerGrado primer){
    int coefA, coefB;
    DevolverCoeficientesP(primer, coefA, coefB);
    if(coefA==1)
        printf("x ");
    else
        if(coefA==-1)
            printf("-x");
        else
            printf("%dx", coefA);
        
    if(coefB>0)
        printf(" + %d", coefB);
    else
        if (coefB<0)
            printf(" - %d", -coefB);

    printf(" = 0\n");
}

PrimerGrado SumarPrimerGrado (PrimerGrado coef1, PrimerGrado coef2) {
    PrimerGrado sum;
    sum.coefA = coef1.coefA + coef2.coefA;
    sum.coefB = coef1.coefB + coef2.coefB;

    return sum;
}
