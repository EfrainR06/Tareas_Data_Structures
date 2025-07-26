//Efrain Retana Segura

#include "recta.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


Recta *crear_recta(float A, float B, float C) {
    Recta* r = (Recta*)malloc(sizeof(Recta));
    if (r) {
        r->A = A;
        r->B = B;
        r->C = C;
    }
    return r;
}

float pendiente_recta(const Recta *r) {
    if (!r || r->B == 0) return 0.0f;
    return -r->A / r->B;
}

bool punto_en_recta(const Recta *r, float x, float y) {
    if (!r) return false;
    float val = r->A * x + r->B * y + r->C;
    return fabs(val) < 1e-6;
}



