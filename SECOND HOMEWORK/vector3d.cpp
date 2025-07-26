//Efrain Retana Segura UNA

#include "vector3d.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Vector3D *crear_vector3d(float x, float y, float z) {
    Vector3D* v = (Vector3D*)malloc(sizeof(Vector3D));
    if (v) {
        v->x = x;
        v->y = y;
        v->z = z;
    }
    return v;
}

float magnitud_vector3d(const Vector3D *v) {
    if (!v) return 0.0f;
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

Vector3D *sumar_vector3d(const Vector3D *v1, const Vector3D *v2) {
    if (!v1 || !v2) return NULL;
    return crear_vector3d(v1->x + v2->x, v1->y + v2->y,v1->z + v2->z);
}

float producto_escalar(const Vector3D *v1, const Vector3D *v2) {
    if (!v1 || !v2) return 0.0f;
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void imprimir_vector3d(const Vector3D *v) {
    if (v)
        printf("Vector: (%.2f, %.2f, %.2f)\n", v->x, v->y, v->z);
}


