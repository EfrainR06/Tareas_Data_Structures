//Efrain Retana Segura UNA

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

//Documentos de Ejercicios de complejidad algoritmica - iterativos
//Todos los pasos estan etiquteados como "Paso A", "Paso B", etc.
//Complejidad expresada como polinomio sumando cada paso.


// Ejercicio 1:Recorrido + comparación de pares + constantes
//Complejidad
// Paso A: O(n)
// Paso B: O(n**2)
// Paso C: O(1)

//Polinomio: O(n) + O(n ** 2) + O(1) = O(n ** 2)

int ejercicio1(int arr[], int n) {
    int suma = 0;

    //Paso A: Recorrido Lineal
    for (int i = 0; i < n; i++)suma += arr[i];

    //Paso B: Comparación de todo los pares
    for (int i =0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j])suma++;

    //Paso C: Constante
    suma += 100;

    return suma;
}

/*
Ejercicio 2: Ciclo n/2 + doble bucle en segunda mitad
Complejidad:
Paso A: O(n/2) = O(n)

Paso B: O((n/2)^2)= O(n ** 2)

Paso C: O(1)

Polinomio: O(n) + O(n ** 2) + O(1) = O(n ** 2)
*/

int ejercicio2(int arr[], int n) {
    int total = 0;

    //Paso A: Recorrido hasta n/2
    for (int i = 0; i < n/2; i++)total += arr[i];

    //Paso B: Doble Bucle en la segunda mitad
    for (int i = n/2; i < n; i++)
        for (int j = n/2; j < n; j++)
            total += arr[i] * arr[j];

    //Paso C: Constante
    total += 5;

    return total;
}

/*
 Ejercicio 3: Logaritmico + lineal + cuadrático
 Complejidad:
 Paso A: O(log n)
 Paso B: O(n)
 Paso C: O(n ** 2)

 Polinomio: O(log n) + O(n) + O(n ** 2) = O(n ** 2)
 */

int ejercicio3(int arr[], int n) {
    int r = 0;

    //Paso A: Bucle logarítmico
    for (int i = 1; i < n; i *= 2)r += arr[i];

    //Paso B: Bucle lineal
    for (int i = 0; i < n; i++) r+= arr[i];

    //Paso C: Bucle cuadratico
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) r += arr[i] * arr[j];

    return r;
}

/*
 Ejercicio 4: Triple bucle anidado
 Complejidad:
 Paso A: O(n ** 3)
 Paso B: O(1)

 Polinomio: O(n ** 3) + O(1) = O(n ** 3)
*/

int ejercicio4(int arr[], int n) {
    int total = 0;

    //Paso A: Triple bucle
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                total += arr[i] + arr[j] + arr[k];

    //Paso B: Constante

    total += 1;

    return total;
}

/*
 Ejercicio 5: Lineal + logarítmico anidado
 Complejidad:
 Paso A: O(n)
 Paso B: O(n log n)
 Paso C: 1
 Polinomio:O(n) + O(n log n) + O(1) = O(n log n)
 */

int ejercicio5(int arr[], int n) {
    int total = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)total += arr[i];

    //Paso B: Logarítmico anidado
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j *=2)
            total += arr[i] + j;

    //Paso C: Constante
    total += 10;

    return total;
}

/*
Ejercicio 6: Mitad lineal + cuadrática en n/2
Complejidad:
Paso A: O(n/2) = O(n)
Paso B: O((n/2)^2) = O(n ** 2)
Paso C: O(1)

Polinomio: O(n) + O(n ** 2) + O(1) = O(n ** 2)
 */
int ejercicio6(int arr[], int n) {
    int suma = 0;

    //Paso A: Lineal sobre n/2
    for (int i = 0; i < n /2; i ++)suma += arr[i];

    //Paso B: Cuadrático en n/2
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < n /2 ; j++)
            suma += arr[i] * arr[j];

    //Paso C: Constante
    suma += 1;

    return suma;
}

/*
 Ejercicio 7: Lineal + cuadrático independientes
 Complejidad:
 Paso A: O(n)
 Paso B: O(n ** 2)
 Paso C: O(1)

 Polinomio: O(n) + O(n ** 2) + O(1) = O(n ** 2)
 */

int ejercicio7(int arr[], int n) {
    int t = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)t+=arr[i];

    //Paso B: Cuadratico
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            t += arr[i] * arr[j];

    //Paso C: Constante
    t += 42;

    return t;
}


/*
Ejercicio 8: Lineal + cuadratico + logaritmico
Complejidad:
Paso A: O(n)
Paso B: O(n ** 2)
Paso C: O(log n)

Polinomio: O(n) + O(n ** 2) + O(log n) = O(n ** 2)
 */

int ejercicio8(int arr[], int n) {
    int r = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)r += arr[i];

    //Paso B: Cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            r += arr[i] + arr[j];

    //Paso C: Logaritmico
    for (int i = 1; i < n; i *= 2) r+= i;

    return r;
}

/*
Ejercicio 9: Doble bucle con j dependiente de i
Complejidad:
    Paso A: O(n ** 2)
    Paso B: O(1)
    Polinomio: O(n ** 2) + O(1) = O(n**2)
 */

int ejercicio9(int arr[], int n) {
    int suma = 0;

    //Paso A: Bucle triangular
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            suma += arr[i] - arr[j];
        }
    }

    //Paso B:Constante
    suma += 1;

    return suma;
}


/*
 Ejercicio 10: Tres bucles independientes
Complejidad:

Paso A: O(n)
Paso B: O(n ** 2)
Paso C: O(n *** 3)

Polinomio: O(n) + O(n ** 2) + O(n *** 3) = O(n *** 3)
 */

int ejercicio10(int arr[], int n) {
    int total = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)total += arr[i];

    //Paso B: Cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)total += arr[i];

    //Paso C:Cúbico
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) total += arr[i];

    return total;
}

/*
 Ejercicio parte 2

Seccion 2: Ejercicios de complejidad algoritmicas - Ciclos variados y anidados

Ejercicio 11: Bucle hasta n/2 + doble bucle cuadrático

Complejidad:
Paso A: O(n/2) = O(n)
Paso B: O(n ** 2)
Paso C: O(1)

Polinomio: O(n) + O(n ** 2) + O(1) = O(n ** 2)
 */

int ejercicio11(int arr[], int n) {
    int suma = 0;

    //Paso A: Recorrido hasta n/2
    for (int i = 0; i < n/2; i++)suma += arr[i];

    //Paso B: Doble bucle cuadratico completo

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            suma += arr[i] * arr[j];

    //Paso C: Constante
    suma += 10;

    return suma;
}


/*
 Ejercicio 12: Triple bucle con límites variables(i*j*k)
 Complejidad:
 Paso A: O(n)
 Paso B: O(n ** 2)
 Paso C: O(1)

 Polinomio: O(n) + O(n ** 3) + O(1) = O(n ** 3)
 */

int ejercicio12(int arr[],int n) {
    int total = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)total += arr[i];

    //Paso B: Triple bucle anidado
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                total += arr[i] * arr[j] * arr[k];

    //Paso C:Constante
    total += 5;

    return total;
}

/*
 Ejercicio 13: Bucle anidado con logarítmico interno
 Complejidad:
 Paso A: O(n)
 Paso B: O(n log n)
 Paso C: O(1)

 Polinomio: O(n) + O(n log n) + O(1) = O(n log n)
 */

int ejercicio13(int arr[], int n) {
    int sum = 0;

    //Paso A: Lineal
    for (int i = 0; i < n; i++)sum += arr[i];

    //Paso B: Doble bucle con logarítmico interno
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j *= 2)
            sum += arr[i] * j;

    //Paso C:Constante
    sum += 100;

    return sum;
}

/*
 Ejercicio 14:Bucle con decremento y ciclo anidado lineal
 Complejidad:
 Paso A: O(n)
 Paso B: O(n ** 2)
 Paso C: O(1)

 Polinomio: O(n) + O(n ** 2) +  O(1) = O(n ** 2)
 */

int ejercicio14(int arr[],int n) {
    int total = 0;

    //Paso A: Bucle con decremento
    for (int i = n; i > 0;i--)total += i;

    //Paso B: Doble Bucle cuadratico
    for (int i = 0; i < n; i++)
        for (int j = 0; j <n; j++)
            total += arr[i] * arr[j];

    //Paso C: Constante
    total += 1;

    return total;
}

/*
 Ejercicio 15: Doble bucle con límites dependientes
 Complejidad:
 Paso A: O(n ** 2)
 Paso B: O(n)
 Paso C: O(1)

 Polinomio:O(n**2) + O(n) + O(1) = O(n ** 2)
 */

int ejercicio15(int arr[], int n) {
    int sum = 0;

    //Paso A: Doble bucle triangular(j depende de i)
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            sum += arr[i] * arr[j];

    //Paso B: Bucle lineal
    for (int i = 0; i < n; i++)sum += arr[i];

    //Paso C: Constante
    sum += 7;

    return sum;
}
/*
=============================================
Ejercicio 16: Ciclo con i^2 y logarítmico anidado
Complejidad:
  Paso A: O(n²)
  Paso B: O(log n)
  Paso C: O(1)
Polinomio: O(n²) + O(log n) + O(1) = O(n²)
*/
int ejercicio16(int arr[], int n) {
    int total = 0;

    // Paso A: Bucle cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total += arr[i] + arr[j];

    // Paso B: Logarítmico
    for (int i = 1; i < n; i *= 2) total += i;

    // Paso C: Constante
    total += 3;

    return total;
}

/*
=============================================
Ejercicio 17: Bucle con paso de 2 + doble bucle anidado
Complejidad:
  Paso A: O(n/2) = O(n)
  Paso B: O(n²)
  Paso C: O(1)
Polinomio: O(n) + O(n²) + O(1) = O(n²)
*/
int ejercicio17(int arr[], int n) {
    int total = 0;

    // Paso A: Bucle con paso 2
    for (int i = 0; i < n; i += 2) total += arr[i];

    // Paso B: Doble bucle cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total += arr[i] * arr[j];

    // Paso C: Constante
    total += 0;

    return total;
}

/*
=============================================
Ejercicio 18: Bucle con límite variable i*j + logarítmico
Complejidad:
  Paso A: O(n²)
  Paso B: O(log n)
  Paso C: O(1)
Polinomio: O(n²) + O(log n) + O(1) = O(n²)
*/
int ejercicio18(int arr[], int n) {
    int sum = 0;

    // Paso A: Doble bucle cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += arr[i] + arr[j];

    // Paso B: Logarítmico
    for (int i = 1; i < n; i *= 2) sum += i;

    // Paso C: Constante
    sum += 11;

    return sum;
}

/*
=============================================
Ejercicio 19: Bucle n/2 + bucle logarítmico + doble bucle anidado
Complejidad:
  Paso A: O(n/2) = O(n)
  Paso B: O(log n)
  Paso C: O(n²)
Polinomio: O(n) + O(log n) + O(n²) = O(n²)
*/
int ejercicio19(int arr[], int n) {
    int total = 0;

    // Paso A: Bucle hasta n/2
    for (int i = 0; i < n / 2; i++) total += arr[i];

    // Paso B: Logarítmico
    for (int i = 1; i < n; i *= 2) total += i;

    // Paso C: Doble bucle cuadrático
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total += arr[i] * arr[j];

    return total;
}

/*
=============================================
Ejercicio 20: Doble bucle con j dependiente y ciclo lineal
Complejidad:
  Paso A: O(n²)
  Paso B: O(n)
  Paso C: O(1)
Polinomio: O(n²) + O(n) + O(1) = O(n²)
*/
int ejercicio20(int arr[], int n) {
    int sum = 0;

    // Paso A: Bucle triangular (j depende de i)
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            sum += arr[i] * arr[j];

    // Paso B: Lineal
    for (int i = 0; i < n; i++) sum += arr[i];

    // Paso C: Constante
    sum += 2;

    return sum;
}
using namespace std;
using namespace std::chrono;

void generarArreglo(int arr[], int n, int max_val = 1000) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % max_val;
}

int main() {
    srand(time(0));  // Semilla para aleatorios

    const int N = 500;  // Tamaño del arreglo
    int arr[N];

    generarArreglo(arr, N);

    cout << "== Menú de Ejercicios (1 a 20) ==" << endl;
    cout << "Ingrese el número de ejercicio que desea ejecutar: ";
    int opcion;
    cin >> opcion;

    int resultado = 0;
    auto inicio = high_resolution_clock::now();

    switch(opcion) {
        case 1:  resultado = ejercicio1(arr, N); break;
        case 2:  resultado = ejercicio2(arr, N); break;
        case 3:  resultado = ejercicio3(arr, N); break;
        case 4:  resultado = ejercicio4(arr, N); break;
        case 5:  resultado = ejercicio5(arr, N); break;
        case 6:  resultado = ejercicio6(arr, N); break;
        case 7:  resultado = ejercicio7(arr, N); break;
        case 8:  resultado = ejercicio8(arr, N); break;
        case 9:  resultado = ejercicio9(arr, N); break;
        case 10: resultado = ejercicio10(arr, N); break;
        case 11: resultado = ejercicio11(arr, N); break;
        case 12: resultado = ejercicio12(arr, N); break;
        case 13: resultado = ejercicio13(arr, N); break;
        case 14: resultado = ejercicio14(arr, N); break;
        case 15: resultado = ejercicio15(arr, N); break;
        case 16: resultado = ejercicio16(arr, N); break;
        case 17: resultado = ejercicio17(arr, N); break;
        case 18: resultado = ejercicio18(arr, N); break;
        case 19: resultado = ejercicio19(arr, N); break;
        case 20: resultado = ejercicio20(arr, N); break;
        default:
            cout << "Opción no válida." << endl;
            return 1;
    }

    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    cout << "Resultado: " << resultado << endl;
    cout << "Tiempo de ejecución: " << duracion.count() << " ms" << endl;

    return 0;
}