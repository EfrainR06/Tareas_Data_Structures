//Efrain Retana Segura UNA

#ifndef PUNTO_H
#define PUNTO_H

typedef struct Punto Punto; // Decalaración opaca
// Funciones del ADT
Punto* crear_punto(float x, float y);
void destruir_punto(Punto* p);
float obtener_x(Punto* p);
float obtener_y(Punto* p);
void establecer_x(Punto* p, float x);
void establecer_y(Punto* p, float y);
float distancia(Punto* p1, Punto* p2);


#endif //PUNTO_H
