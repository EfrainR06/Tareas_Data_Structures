//Efrain Retana Segura UNA

#include "Archivo.h"

int main() {
    // FILE* archivo = abrir_archivo("mapa_electoral.dat");
    // int n, i;
    // printf("Cuantos registros quiere ingresar? ");
    // scanf("%d", &n);
    //
    // for (i = 0; i < n; ++i) {
    //     printf("\nRecord #%d:\n", i + 1);
    //     MapaElectoral reg = leerRegistro("mapa_electoral.dat");
    //     esEscribirRegistro(archivo, reg);
    // }
    //
    // cerrarMapaElectoral(archivo);
    //
    // printf("\n--- Records in file ---\n");
    // imprimirMapaElectoral("mapa_electoral.dat");

    reporteTotales("mapa_electoral.dat");
    return 0;
}

