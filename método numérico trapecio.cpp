#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el valor de ln(x)
double ln(double x) {
    return 0.2+25*x-200*pow((x),2)+675*pow((x),3)-900*pow((x),4)+400*pow((x),5);
}

// Función para calcular el área bajo la curva utilizando el método del trapecio
double trapecio(double a, double b, int n) {
    double h = (b - a) / n;  // Tamaño del intervalo

    double suma = 0.0;
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += ln(x);
    }

    double area = h * ((ln(a) + ln(b)) / 2.0 + suma);
    return area;
}

int main() {
    // Valores iniciales
    double a = 0.0;  // Límite inferior del intervalo
    double b = 0.8;  // Límite superior del intervalo
    int n = 100;
    // Calcular el valor de ln(x) utilizando el método del trapecio
    double resultado = trapecio(a, b, n);

    // Imprimir el resultado
    cout << "El valor de ln(6) es aproximadamente: " << resultado << endl;

    return 0;
}