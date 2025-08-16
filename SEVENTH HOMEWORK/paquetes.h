//Efrain Retana Segura UNA

#ifndef PAQUETES_H
#define PAQUETES_H
#include <iostream>
#include <cstdio>
using namespace std;
struct Paquete {
    char remitente[256];
    char destinario[256];
    int localidad;
    char direccion[256];
    double peso;
    int prioridad;
};

class Paquetes {
private:
    Paquete* datos;
    int libre;
    int capacidad;
    int cantidad;

public:
    Paquetes() {
        capacidad = 10;
        libre = 0;
        cantidad = 0;
        datos = new Paquete[capacidad];
    }
    void agregar(const Paquete& p) {
        if (libre < capacidad) {
            datos[libre++] = p;
            cantidad++;
        }else {
            aumentarArreglo();
            datos[libre++] = p;
            cantidad++;
        }
    }
    void aumentarArreglo() {
        int nuevaCapacidad = capacidad * 2;
        Paquete* nuevosDatos = new Paquete[nuevaCapacidad];
        for (int i = 0; i < cantidad; i++) {
            nuevosDatos[i] = datos[i];
        }
        delete[] datos;
        datos = nuevosDatos;
        capacidad = nuevaCapacidad;
    }
    void AbrirArchivo() {
        FILE * archivo = fopen("paquetes.dat", "wb");
        if (archivo == NULL) {
            cout << "Error al abrir archivo" << endl;
        }
        //Solicitar 3
        Paquete registro;
        for (int i = 0; i < 3; i++) {
            cout << "\n----- Paquete " << i + 1 << " -----\n";
            cout << "Ingrese el remitente " << i + 1 << ": ";
            cin.getline(registro.remitente, 256); // Ignorar el salto de linea;
            cout << "Ingrese el destinario " << i + 1 << ": ";
            cin.getline(registro.destinario, 256);
            cout << "Ingrese la localidad (1,2,3,4,5,6,7) según primer número de provincia " << i + 1 << ": ";
            cin>> registro.localidad;
            cin.ignore(); //Ignorar el salto de linea
            cout << "Ingrese la direccion del envio " << i + 1 << ": ";
            cin.getline(registro.direccion, 256);
            cout << "Ingrese el peso del envio en KG " << i + 1 << ": ";
            cin>> registro.peso;
            cin.ignore();
            cout << "Ingrese la prioridad del envio (1: Importante, 2: Regular, 3: Falta de importancia ) " << i + 1 << ": ";
            cin >> registro.prioridad;
            cin.ignore();
            fwrite(&registro, sizeof(Paquete), 1, archivo);
            agregar(registro);
        }
        fclose(archivo);
    }
    void ordenarPorPrioridad() {
        if (cantidad < 2) return;
        int limite = cantidad - 1;
        while (limite > 0) {
            int nuevo_limite = 0;
            for (int j = 0; j < limite; j++) {
                if (datos[j].prioridad > datos[j + 1].prioridad) {
                    Paquete temp = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temp;
                    nuevo_limite = j;
                }
            }
            limite = nuevo_limite;
        }
    }

    //Metodo para guardar los paquetes ordenados
    void guardarOrdenados(const char* nombreArchivo) {
        FILE * archivo = fopen(nombreArchivo,  "wb");
        if (!archivo)return;
        for (int i = 0; i < cantidad; i++) {
            fwrite(&datos[i], sizeof(Paquete), 1, archivo);
        }
        fclose(archivo);
    }

    //Metodo para liberar memoria
    void liberarMemoria() {
        delete[] datos;
        datos = nullptr;
    }
};

void mostrarDesdeArchivo(const char* nombreArchivo) {
    FILE * archivo = fopen(nombreArchivo, "rb");
    if (!archivo) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    fseek(archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    int n = tam / sizeof(Paquete);
    rewind(archivo);

    Paquete* registros = new Paquete[n];
    fread(registros, sizeof(Paquete),n,archivo);
    fclose(archivo);

    for (int i = 0; i < n; i++) {
        cout << "Remitente: " << registros[i].remitente << endl;
        cout << "Destinatario: " << registros[i].destinario << endl;
        cout << "Localidad: " << registros[i].localidad << endl;
        cout << "Direccion: " << registros[i].direccion << endl;
        cout << "Peso: " << registros[i].peso << endl;
        cout << "Prioridad: " << registros[i].prioridad << endl;
        cout << "------------------------" << endl;
    }
    delete[] registros;
}

#endif //PAQUETES_H
