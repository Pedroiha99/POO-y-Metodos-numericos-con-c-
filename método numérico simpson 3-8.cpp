#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    // Función a integrar
    return 5 + 3 * sin(x);
}

double metodoSimpson38(double a, double b, int n) {
    double h = (b - a) / n;
    double suma = f(a) + f(b);
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            suma += 2 * f(x);
        } else {
            suma += 3 * f(x);
        }
    }
    
    return (3 * h / 8.0) * suma;
}

int main() {
    double a = 0.0;  // Límite inferior de integración
    double b = M_PI;  // Límite superior de integración
    int n = 99;  // Número de subintervalos (debe ser múltiplo de 3)
    
    double resultado = metodoSimpson38(a, b, n);
    
    cout << "El resultado de la integral es: " << resultado << endl;
    
    return 0;
}
