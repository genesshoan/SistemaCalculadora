#include "segundogrado.h"

void DevolverCoeficientesS(SegundoGrado segundo, int &coefa, int &coefb, int &coefc) {
    coefa = segundo.coefA;
    coefb = segundo.coefB;
    coefc = segundo.coefC;
}

int DevolverCoefSegundoA(SegundoGrado segundo) {
    return segundo.coefA;
}

int DevolverCoefSegundoB(SegundoGrado segundo) {
    return segundo.coefB;
}

int DevolverCoefSegundoC(SegundoGrado segundo) {
    return segundo.coefC;
}

int NmroDeSoluciones(SegundoGrado segundo) {
    int a, b, c, sol;
    DevolverCoeficientesS(segundo, a, b, c);
    float discriminante = (b * b) - (4 * a * c);
    if (discriminante > 0)
        sol = 2;
    else 
        if (discriminante == 0)
            sol = 1;
        else
            sol = 0;

    return sol;
}

void ResolverSegundoGrado2Soluciones(SegundoGrado segundo, float &x1, float &x2) {
    int a, b, c; 
    float raizdiscriminante;
    DevolverCoeficientesS(segundo, a, b, c);

    raizdiscriminante = sqrt((b * b) - (4 * a * c));
    
    x1 = (-b + raizdiscriminante) / (2.0f * a);
    x2 = (-b - raizdiscriminante) / (2.0f * a);
}

float ResloverSegundoGrado1Solucion(SegundoGrado segundo) {
    int a = DevolverCoefSegundoA(segundo);
    int b = DevolverCoefSegundoB(segundo);

    return (-b) / (2.0f * a);
}

void MostrarSegundoGrado (SegundoGrado seg){
    int coefA, coefB, coefC;
        DevolverCoeficientesS(seg, coefA, coefB, coefC);
        if(coefA==1)
            printf("x^2 ");
        else
            if(coefA==-1)
                printf("-x^2 ");
            else   
                printf("%dx^2", coefA);
                
        if(coefB==1)
            printf("+ x ");
        else
            if (coefB==-1)
                printf("- x ");
            else 
                if (coefB>0)
                    printf(" + %dx", coefB);
                else
                    if (coefB<0)
                        printf(" - %dx", -coefB);
        
        if (coefC>0)
            printf(" + %d",coefC);    
        else
            if (coefC<0)
                printf(" - %d", -coefC);

    printf(" = 0\n");
    }    

SegundoGrado SumarSegundoGrado (SegundoGrado seg1, SegundoGrado seg2) {
    int a1, b1, c1, a2, b2, c2;
    DevolverCoeficientesS(seg1, a1, b1, c1);
    DevolverCoeficientesS(seg2, a2, b2, c2);
    SegundoGrado nuevo;
    nuevo.coefA = a1 + a2;
    nuevo.coefB = b1 + b2;
    nuevo.coefC = c1 + c2;

    return nuevo;
}
