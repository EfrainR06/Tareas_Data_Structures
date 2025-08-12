//Efrain Retana Segura UNA
#include "Archivo.h"
#include <string.h>

FILE *abrir_archivo(const char *nombre) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../FOURTH HOMEWORK/%s", nombre);
    FILE * archivo= fopen(ruta, "wb");
    if (archivo == NULL) {
        printf("Error al abrir.\n");
        exit(1);
    }
    return archivo;
}

// Use only ASCII in prompts to avoid encoding issues
MapaElectoral leerRegistro(const char *nombre) {
    MapaElectoral reg;

    printf("Ingrese la cedula: ");
    scanf("%d", &reg.cedula);
    getchar(); // Consume leftover newline

    printf("Ingrese la provincia que pertenece: ");
    fgets(reg.provincia, sizeof(reg.provincia), stdin);
    reg.provincia[strcspn(reg.provincia, "\n")] = 0; // Remove newline

    printf("Canton que pertenece: ");
    fgets(reg.canton, sizeof(reg.canton), stdin);
    reg.canton[strcspn(reg.canton, "\n")] = 0;

    printf("Distrito que pertenece: ");
    fgets(reg.distrito, sizeof(reg.distrito), stdin);
    reg.distrito[strcspn(reg.distrito, "\n")] = 0;

    return reg;
}
void esEscribirRegistro(FILE *archivo, MapaElectoral reg) {
    fwrite(&reg, sizeof(MapaElectoral), 1, archivo);
}

void cerrarMapaElectoral(FILE *archivo) {
    if (archivo != NULL) {
        fclose(archivo);
    }
}

void imprimirMapaElectoral(const char *mapa) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../FOURTH HOMEWORK/%s", mapa);
    FILE * f =fopen(ruta, "rb");
    if (!f) {
        printf("No se pudo abrir el archivo %s\n", mapa);
        return;
    }

    MapaElectoral reg;
    int i = 1;
    printf("Lista de registros en %s:\n", mapa);
    while (fread(&reg, sizeof(MapaElectoral), 1, f) == 1) {
        printf("Registro #%d:\n", i++);
        printf("  Cedula: %d\n", reg.cedula);
        printf("  Provincia: %s\n", reg.provincia);
        printf("  Canton: %s\n", reg.canton);
        printf("  Distrito: %s\n", reg.distrito);
    }
    fclose(f);
}
#include <stdio.h>
#include <string.h>
#include "Archivo.h"

void reporteTotales(const char* archivo) {
    char ruta[256];
    snprintf(ruta, sizeof(ruta), "../FOURTH HOMEWORK/%s", archivo);
    FILE* f = fopen(ruta, "rb");
    if (!f) {
        printf("No se pudo abrir el archivo %s\n", archivo);
        return;
    }

    // Read all records into an array
    MapaElectoral registros[1000];
    int n = 0;
    while (fread(&registros[n], sizeof(MapaElectoral), 1, f) == 1 && n < 1000) {
        n++;
    }
    fclose(f);

    // Province totals
    printf("Total habitantes por provincia:\n");
    for (int i = 0; i < n; ++i) {
        int count = 0, alreadyCounted = 0;
        for (int j = 0; j < i; ++j) {
            if (strcmp(registros[i].provincia, registros[j].provincia) == 0) {
                alreadyCounted = 1;
                break;
            }
        }
        if (!alreadyCounted) {
            for (int j = 0; j < n; ++j) {
                if (strcmp(registros[i].provincia, registros[j].provincia) == 0)
                    count++;
            }
            printf("  %s: %d\n", registros[i].provincia, count);
        }
    }

    // Canton totals
    printf("\nTotal habitantes por canton:\n");
    for (int i = 0; i < n; ++i) {
        int count = 0, alreadyCounted = 0;
        for (int j = 0; j < i; ++j) {
            if (strcmp(registros[i].canton, registros[j].canton) == 0 &&
                strcmp(registros[i].provincia, registros[j].provincia) == 0) {
                alreadyCounted = 1;
                break;
            }
        }
        if (!alreadyCounted) {
            for (int j = 0; j < n; ++j) {
                if (strcmp(registros[i].canton, registros[j].canton) == 0 &&
                    strcmp(registros[i].provincia, registros[j].provincia) == 0)
                    count++;
            }
            printf("  %s, %s: %d\n", registros[i].canton, registros[i].provincia, count);
        }
    }
    printf("\nTotal habitantes por distrito:\n");
    for (int i = 0; i < n; ++i) {
        int count = 0, alreadyCounted = 0;
        for (int j = 0; j < i; ++j) {
            if (strcmp(registros[i].distrito, registros[j].distrito) == 0 &&
                strcmp(registros[i].canton, registros[j].canton) == 0 &&
                strcmp(registros[i].provincia, registros[j].provincia) == 0) {
                alreadyCounted = 1;
                break;
            }
	        }
        if (!alreadyCounted) {
            for (int j = 0; j < n; ++j) {
                if (strcmp(registros[i].distrito, registros[j].distrito) == 0 &&
                    strcmp(registros[i].canton, registros[j].canton) == 0 &&
                    strcmp(registros[i].provincia, registros[j].provincia) == 0)
                    count++;
            }
            printf("  %s, %s, %s: %d\n", registros[i].distrito, registros[i].canton, registros[i].provincia, count);
        }
    }
}


