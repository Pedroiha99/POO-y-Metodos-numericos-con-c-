#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return (1.0/x + 4.0) + 8.0*x;
}

double biseccion(double a, double b, double tol) {
    double c;
    while (abs(b - a) > tol) {
        c = (a + b) / 2.0;
        if (f(c) == 0) {
            return c;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a = -1.0;  // límite inferior del intervalo
    double b = 1.0;  // límite superior del intervalo
    double tol = 0.01;  // tolerancia
    double raiz = biseccion(a, b, tol);
    cout << "La raiz de la funcion es: " << raiz << endl;
    return 0;
}
