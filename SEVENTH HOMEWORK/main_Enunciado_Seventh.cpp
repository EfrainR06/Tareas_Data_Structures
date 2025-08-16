//Efrain Retana Segura UNA
#include "paquetes.h"

int main() {
    Paquetes paq;
    paq.AbrirArchivo(); // Enter and save 3 packages
    cout << "Archivos sin ordenar: " << endl;
    mostrarDesdeArchivo("paquetes.dat");
    paq.ordenarPorPrioridad(); // Sort by priority
    paq.guardarOrdenados("Paquetes_ordenados.dat"); // Save sorted
    paq.liberarMemoria(); // Free memory
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "**********************************" << endl;
    cout << "Archivos despúes de ordenar: "<<endl;
    // Show sorted packages from file
    mostrarDesdeArchivo("Paquetes_ordenados.dat");

    return 0;
}