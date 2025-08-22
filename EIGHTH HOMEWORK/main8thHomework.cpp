//Efrain Retana Segura UNA
//Testeo del main con el package with vectors
#include "PackagesWithVectors.h"


int main() {
    //Prueba sin el archivo .dat
    // Paquetes paq;
    // Paquete p1 = {"Juan", "Maria", 1, "Calle 1", 2.5, 1};
    // Paquete p2 = {"Luis", "Ana", 2, "Calle 2", 1.2, 2};
    // Paquete p3 = {"Sofia", "Carlos", 3, "Calle 3", 3.0, 3};
    //
    // paq.agregar(p1);
    // paq.agregar(p2);
    // paq.agregar(p3);
    //
    // paq.mostrar();
    //
    // Paquete modificado = {"Luis M.", "Ana", 2, "Calle 2", 1.5, 2};
    // paq.modificar(1, modificado);
    //
    // paq.eliminar(0);
    //
    // paq.ampliar(5);
    //
    // paq.mostrar();

    //Pruebas con el archivo .dat
        Paquetes paq;
        paq.AbrirArchivo(); // Enter and save 3 packages
        cout << "Archivos sin ordenar: " << endl;
        paq.mostrarDesdeArchivo("../EIGHTH HOMEWORK/paquetes.dat");
        paq.ordenarPorPrioridad(); // Sort by priority
        paq.guardarOrdenados("../EIGHTH HOMEWORK/Paquetes_ordenados.dat"); // Save sorted
        paq.liberarMemoria(); // Free memory
        cout << "**********************************" << endl;
        cout << "Archivos después de ordenar: " << endl;
        paq.mostrarDesdeArchivo("../EIGHTH HOMEWORK/Paquetes_ordenados.dat");
    return 0;
}