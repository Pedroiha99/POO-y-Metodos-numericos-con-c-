#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    // Función a integrar
    return 5 + 3 * sin(x);
}

double metodoSimpson13(double a, double b, int n) {
    double h = (b - a) / n;
    double suma = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            suma += 2 * f(x);
        } else {
            suma += 4 * f(x);
        }
    }
    
    return (h / 3.0) * suma;
}

int main() {
    double a = 0.0;  // Límite inferior de integración
    double b = M_PI;  // Límite superior de integración
    int n = 100;  // Número de subintervalos
    
    double resultado = metodoSimpson13(a, b, n);
    
    cout << "El resultado de la integral es: " << resultado << endl;
    
    return 0;
}
