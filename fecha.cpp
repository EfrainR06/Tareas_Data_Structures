//Efrain Retana Segura UNA
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>

Fecha *crear_fecha(int dia, int mes, int anio) {
    Fecha *f = (Fecha *) malloc(sizeof(Fecha));
    if (f) {
        f->dia = dia;
        f->mes = mes;
        f->anio = anio;
    }
    return f;
}

void imprimir_fecha(const Fecha *f) {
    if (f)
        printf("%02d/%02d/%04d\n", f->dia, f->mes, f->anio);
}

int comparar_fecha(const Fecha *f1, const Fecha *f2) {
    if (!f1 || !f2) return 0;
    if (f1->anio != f2->anio) return (f1->anio > f2->anio) ? 1 : -1;
    if (f1->mes != f2->mes) return (f1->mes > f2->mes) ? 1 : -1;
    if (f1->dia != f2->dia) return (f1->dia > f2->dia) ? 1 : -1;
    return 0;
}



