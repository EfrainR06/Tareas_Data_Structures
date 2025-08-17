//Efrain Retana Segura UNA
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#ifndef ARCHIVO_STUDENTS_H
#define ARCHIVO_STUDENTS_H

struct Historial {
    int carnet;
    char codigoMaterial[20];
    float nota;
    int periodo;
    int annio;
};

struct Material {
    char escuela[50];
    char carrera[50];
    char codigo[20];
    int creditos;
};

void AbrirHistorial() {
    FILE * archivo = fopen("../FIFTH HOMEWORK/Historial.dat", "wb");
    if (archivo == NULL) {
        cout << "Error al abrir archivo" << endl;
    }
    Historial registro;
    for (int i = 0; i < 3; i++) {
        cout << "\n----- Estudiante " << i + 1 << "----\n";
        cout << "Ingrese el carnet " << i + 1 << ": ";
        cin >> registro.carnet;
        cin.ignore();
        cout << "Ingrese el nombre de la materia " << i + 1 << ": ";
        cin.getline(registro.codigoMaterial, 20);
        cout << "Digite la nota obtenida " << i + 1 << ": ";
        cin >> registro.nota;
        cin.ignore();
        cout << "Digite el periodo (1: Primer semestre, 2: Segundo semestre) " << i + 1 << ": ";
        cin >> registro.periodo;
        cin.ignore();
        cout << "Digite el annio " << i + 1 << ": ";
        cin >> registro.annio;
        cin.ignore();
        fwrite(&registro, sizeof(Historial), 1, archivo);
    }
    fclose(archivo);
}

void AbrirMaterial() {
    FILE * archivo = fopen("../FIFTH HOMEWORK/RegistroStudents.dat", "wb");
    if (archivo == NULL) {
        cout << "Error al abrir archivo" << endl;
    }
    Material registro;
    for (int i = 0; i < 3; i++) {
        cout << "\n----- Registro " << i + 1 << "----\n";
        cout << "Ingrese la escuela " << i + 1 << ": ";
        cin.getline(registro.escuela, 50);
        cout << "Ingrese la carrera " << i + 1 << ": ";
        cin.getline(registro.carrera, 50);
        cout << "Digite el código de la materia " << i + 1 << ": ";
        cin.getline(registro.codigo, 20);
        cout << "Digite los créditos de la materia " << i + 1 << ": ";
        cin >> registro.creditos;
        cin.ignore();
        fwrite(&registro, sizeof(Material), 1, archivo);
    }
    fclose(archivo);
}
const int MAX = 100;
void leerHistorial(Historial historial[], int &n) {
    FILE* archivo = fopen("../FIFTH HOMEWORK/Historial.dat", "rb");
    if (!archivo) {
        cout << "Error al abrir archivo de materias" << endl;
        n = 0;
        return;
    }
    n = 0;
    while (fread(&historial[n], sizeof(Historial), 1, archivo)) {
        n++;
    }
    fclose(archivo);
}

void leerMaterial(Material material[], int &n) {
    FILE * archivo = fopen("../FIFTH HOMEWORK/RegistroStudents.dat","rb");
    if (!archivo) {
        cout << "Error al abrir archivo de materias " << endl;
        n = 0;
        return;
    }
    n = 0;
    while (fread(&material[n], sizeof(Material), 1, archivo)) {
        n++;
    }
    fclose(archivo);
}

int BuscarMaterial(Material material[], int nMat, const char* codigo) {
    for (int i = 0; i < nMat; i++) {
        if (strcmp(material[i].codigo, codigo) == 0)
            return i;
    }
    return -1;
}

struct PromedioEstudiante {
    int carnet;
    char carrera[50];
    char escuela[50];
    float promedioPonderado;
};

void calcularPromedio(Historial historial[], int nHist, Material material[], int nMat) {
    PromedioEstudiante estudiantes[MAX];
    int nEst = 0;

    for (int i = 0; i < nHist; i++) {
        int carnet = historial[i].carnet;
        int idx = -1;
        for (int j  = 0; j < nEst; j++) {
            if (estudiantes[j].carnet == carnet) { // Fixed typo here
                idx = j;
                break;
            }
        }
        float nota = historial[i].nota;
        int matIdx = BuscarMaterial(material, nMat, historial[i].codigoMaterial);
        if (matIdx == -1) continue;
        int creditos = material[matIdx].creditos;

        if (idx == -1) {
            estudiantes[nEst].carnet = carnet;
            strcpy(estudiantes[nEst].carrera, material[matIdx].carrera);
            strcpy(estudiantes[nEst].escuela, material[matIdx].escuela);
            float sumaNotas = nota * creditos;
            float sumaCreditos = creditos;
            for (int k = i + 1; k < nHist; k++) {
                if (historial[k].carnet == carnet) {
                    int matIdx2 = BuscarMaterial(material, nMat, historial[k].codigoMaterial);
                    if (matIdx2 == -1) continue;
                    sumaNotas += historial[k].nota * material[matIdx2].creditos;
                    sumaCreditos += material[matIdx2].creditos;
                }
            }
            estudiantes[nEst].promedioPonderado = sumaNotas / sumaCreditos;
            nEst++;
        }
    }
    struct PromCarrera {
        char carrera[50];
        float suma;
        int cuenta;
    }carreras[MAX];
    int nCarr = 0;

    struct PromEscuela {
        char escuela[50]; // Fixed type here
        float suma;
        int cuenta;
    }escuelas[MAX];
    int nEsc = 0;

    for (int i = 0; i < nEst; i++) {
        int idxC = -1;
        for (int j = 0; j < nCarr; j++) {
            if (strcmp(carreras[j].carrera, estudiantes[i].carrera) == 0) {
                idxC = j;
                break;
            }
        }
        if (idxC == -1) {
            strcpy(carreras[nCarr].carrera, estudiantes[i].carrera);
            carreras[nCarr].suma = estudiantes[i].promedioPonderado;
            carreras[nCarr].cuenta = 1;
            nCarr++;
        } else {
            carreras[idxC].suma += estudiantes[i].promedioPonderado;
            carreras[idxC].cuenta++;
        }
        int idxE = -1;
        for (int j = 0; j < nEsc; j++) {
            if (strcmp(escuelas[j].escuela, estudiantes[i].escuela) == 0) {
                idxE = j;
                break;
            }
        }
        if (idxE == - 1) {
            strcpy(escuelas[nEsc].escuela, estudiantes[i].escuela);
            escuelas[nEsc].suma = estudiantes[i].promedioPonderado;
            escuelas[nEsc].cuenta = 1;
            nEsc++;
        } else {
            escuelas[idxE].suma += estudiantes[i].promedioPonderado;
            escuelas[idxE].cuenta++;
        }
    }
    cout << "\n--- Reporte por estudiante ---\n";
    for (int i = 0; i < nEst; i++) {
        cout << "Carnet: " << estudiantes[i].carnet
             << ", Escuela: " << estudiantes[i].escuela
             << ", Carrera: " << estudiantes[i].carrera
             << ", Promedio ponderado: " << estudiantes[i].promedioPonderado << endl;
    }
    cout << "\n--- Promedio por carrera ---\n";
    for (int i = 0; i < nCarr; i++) {
        cout << "Carrera: " << carreras[i].carrera
             << ", Promedio de promedios ponderados: " << (carreras[i].suma / carreras[i].cuenta) << endl;
    }
    cout << "\n--- Promedio por escuela ---\n";
    for (int i = 0; i < nEsc; i++) {
        cout << "Escuela: " << escuelas[i].escuela
             << ", Promedio de los promedios de los promedios ponderados: " << (escuelas[i].suma / escuelas[i].cuenta) << endl;
    }
}

#endif //ARCHIVO_STUDENTS_H