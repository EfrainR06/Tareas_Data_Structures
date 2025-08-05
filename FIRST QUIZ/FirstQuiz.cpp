//Efrain Retana Segura UNA
#include <iostream>
//Enunciado del Quiz
//1) Suponga un TDA con
//estructura Typedef struct {int n,m; int * vals;}M, donde vals
//es un arreglo de dimensiones n,m. El TDA entre sus funciones(interfaz) cuenta,
//con la siguiente función: int * H(M * m),  la función H devuelve un puntero
//a un arreglo dinámico(int * hist) que tiene tamannio max_val + 1;
//el cual debe ser considerado en tiempo de ejecucíon de forma int * hist = new int[max_val  + 1]().
//Cada posición hist[i] contiene la frecuencia del valor i en el arreglo bidimensional.
typedef struct {
    int n, m;
    int * vals; // arreglo de tamanno n * m
}M;

int * H(M * m) {

    int total = m->n * m->m;
    int max_val = m->vals[0];
    for (int i = 1; i < total; i++) {
        if (m->vals[i] > max_val)
            max_val = m->vals[i];
    }
    int * hist = new int[max_val + 1]();

    for (int i = 0; i < total; i++) {
        hist[m->vals[i]]++;
    }
    return hist;
}

//Ejemplo de uso
int main() {
    M matriz;
    matriz.n = 2;
    matriz.m = 3;
    int datos[] = {1,2,2,3,1,0};
    matriz.vals = datos;

    int * histograma = H(&matriz);

    for (int i = 0; i <= 3; i++) {
        std::cout << "Valor " << i << " aparece " << histograma[i] << " veces \n";
    }

    delete[] histograma;
    return 0;
}