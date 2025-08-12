//Efrain Retana Segura UNA

#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cedula;
    char canton[256];
    char provincia[256];
    char distrito[256];

}MapaElectoral;

FILE * abrir_archivo(const char* nombre);

MapaElectoral leerRegistro(const char* nombre);

void esEscribirRegistro(FILE* archivo, MapaElectoral reg);

void cerrarMapaElectoral(FILE* archivo);

void imprimirMapaElectoral(const char* mapa);

void reporteTotales(const char* archivo);
// void organizarMapaElectoral(const char* mapa);

#endif //ARCHIVO_H
