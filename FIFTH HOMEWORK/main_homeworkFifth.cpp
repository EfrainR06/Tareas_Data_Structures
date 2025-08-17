//Efrain Retana Segura UNA
#include "Archivo_students.h"

int main() {
    AbrirHistorial();
    AbrirMaterial();
    Historial historial[MAX];
    Material material[MAX];
    int nHist, nMat;

    leerHistorial(historial, nHist);
    leerMaterial(material, nMat);

    calcularPromedio(historial, nHist, material, nMat);

    return 0;
}