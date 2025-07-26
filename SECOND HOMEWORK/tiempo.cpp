//Efrain Retana Segura UNA

#include "tiempo.h"
#include <stdlib.h>
#include <stdio.h>

Tiempo *crear_tiempo(int h, int m, int s) {
    Tiempo* t = (Tiempo*)malloc(sizeof(Tiempo));
    if (t) {
        t->horas = h;
        t->minutos = m;
        t->segundos = s;
    }
    return t;
}

Tiempo* sumar_tiempo(const Tiempo* t1, const Tiempo* t2) {
    if (!t1 || !t2) return NULL;
    int s = t1->segundos + t2->segundos;
    int m = t1->minutos + t2->minutos + s / 60;
    int h = t1->horas + t2->horas + m / 60;
    s %= 60;
    m %= 60;
    return crear_tiempo(h, m, s);
}
Tiempo *restar_tiempo(const Tiempo *t1, const Tiempo *t2) {
    if (!t1 || !t2) return NULL;
    int s1 = t1->horas * 3600 + t1->minutos * 60 + t1->segundos;
    int s2 = t2->horas * 3600 + t2->minutos * 60 + t2->segundos;
    int diff = s1 - s2;
    if (diff < 0) diff = 0;
    int h = diff / 3600;
    int m  = (diff % 3600) / 60;
    int s = diff % 60;
    return crear_tiempo(h,m,s);
}

int comparar_tiempo(const Tiempo *t1, const Tiempo *t2) {
    if (!t1 || !t2) return 0;
    int s1 = t1->horas * 3600 + t1->minutos * 60 + t1->segundos;
    int s2 = t2->horas * 3600 + t2->minutos * 60 + t2->segundos;
    if (s1 == s2) return 0;
    return (s1 > s2) ? 1 : -1;
}
void imprimir_tiempo(const Tiempo *t) {
    if (t)
        printf("%02d:%02d:%02d\n", t->horas, t->minutos, t->segundos);
}


