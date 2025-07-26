//Efrain Retana Segura

#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "rectangulo.h"
#include "Circulo.h"
#include "fecha.h"
//Ejercicio documento 0.1
// int main() {
//     Punto* a = crear_punto(1.0, 2.0);
//     Punto* b = crear_punto(4.0, 6.0);
//     printf("Punto A: (%.2f, %.2f)\n", obtener_x(a), obtener_y(a));
//     printf("Punto B: (%.2f, %.2f)\n", obtener_x(b), obtener_y(b));
//     printf("Distancia entre A y B: %.2f\n", distancia(a, b));
//     destruir_punto(a);
//     destruir_punto(b);
//     return 0;
// }

//Ejercicio 1
// int main() {
//     //Crear puntos para el rectangulo
//     Punto * p1 = crear_punto(1.0,5.0); //Esquina superior izquierda
//     Punto * p2 = crear_punto(6.0, 2.0); // Esquina inferior derecha
//
//     //Crear rectangulo
//     Rectangulo* r = crear_rectangulo(p1, p2);
//
//     printf("Area del rectángulo: %.2f\n", area_rectangulo(r));
//     printf("Perimetro del rectángulo: %2f\n", perimetro_rectangulo(r));
//
//     //Comprobar si un punto esta dentro
//     Punto* p3 = crear_punto(3.0, 3.5);
//     if (punto_en_rectangulo(r, p3))
//         printf("El punto (%.2f, %.2f) está dentro del rectángulo.\n", obtener_x(p3), obtener_y(p3));
//     else
//         printf("El punto (%.2f, %.2f) NO está dentro del rectángulo.\n", obtener_x(p3), obtener_y(p3));
//
//     destruir_punto(p1);
//     destruir_punto(p2);
//     destruir_punto(p3);
//     destruir_rectangulo(r);
//
//     return 0;
// }

//Ejercicio 2

// int main() {
//     // Crear centro del círculo
//     Punto* centro = crear_punto(0.0, 0.0);
//     Circulo* c = crear_circulo(centro, 5.0);
//
//     printf("Area del circulo: %.2f\n", area_circulo(c));
//     printf("Perimetro del circulo: %.2f\n", perimetro_circulo(c));
//
//     // Verificar si un punto está dentro del círculo
//     Punto* p = crear_punto(3.0, 4.0);
//     if (punto_en_circulo(c, p))
//         printf("El punto (%.2f, %.2f) esta dentro del circulo.\n", obtener_x(p), obtener_y(p));
//     else
//         printf("El punto (%.2f, %.2f) NO esta dentro del circulo.\n", obtener_x(p), obtener_y(p));
//
//     // Liberar memoria
//     destruir_punto(p);
//     destruir_punto(centro);
//     destruir_circulo(c);
//
//     return 0;
// }

//Ejercicio 3 Fecha

// int main() {
//     Fecha* f1 = crear_fecha(15, 6, 2024);
//     Fecha* f2 = crear_fecha(10,7, 2023);
//
//     printf("Fecha 1: ");
//     imprimir_fecha(f1);
//
//     printf("Fecha 2: ");
//     imprimir_fecha(f2);
//
//     int cmp = comparar_fecha(f1, f2);
//     if(cmp == 0)
//         printf("Las fechas son iguales.\n");
//     else if (cmp > 0)
//         printf("Fecha 1 es mayor que Fecha 2.\n");
//     else
//         printf("Fecha 1 es menor que Fecha 2.\n");
//
//     free(f1);
//     free(f2);
//     return 0;
// }


