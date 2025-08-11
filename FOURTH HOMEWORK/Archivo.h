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

FILE * abrir_archivo(const char* nombre, const char* modo);

MapaElectoral leerRegistro(const char* nombre);

void esEscribirRegistro(FILE* archivo, MapaElectoral reg);

void cerrarMapaElectoral(FILE* archivo);

void imprimirMapaElectoral(const char* mapa);

void organizarMapaElectoral(const char* mapa);

#endif //ARCHIVO_H
