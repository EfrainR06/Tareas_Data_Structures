//Efrain Retana Segura UNA

#ifndef VECTOR3D_H
#define VECTOR3D_H

struct Vector3D {
    float x;
    float y;
    float z;
};

Vector3D* crear_vector3d(float x, float y, float z);
float magnitud_vector3d(const Vector3D* v);
Vector3D* sumar_vector3d(const Vector3D* v1, const Vector3D* v2);
float producto_escalar(const Vector3D* v1,const Vector3D* v2);
void imprimir_vector3d(const Vector3D* v);
#endif //VECTOR3D_H
