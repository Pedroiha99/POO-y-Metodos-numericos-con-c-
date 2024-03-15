#include <iostream>

using namespace std;

double f(double x, double y) {
    // Función derivada y' = f(x, y)
    return x + y;
}

double calcularSiguienteY(double x, double y, double h) {
    double k1 = h * f(x, y);
    double k2 = h * f(x + h, y + k1);
    
    return y + (k1 + k2) / 2.0;
}

void metodoHeun(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;
    
    cout << "x\t\ty" << endl;
    cout << x << "\t" << y << endl;
    
    for (int i = 1; i <= n; i++) {
        y = calcularSiguienteY(x, y, h);
        x = x + h;
        
        cout << x << "\t" << y << endl;
    }
}

int main() {
    double x0 = 0.0;  // Valor inicial de x
    double y0 = 1.0;  // Valor inicial de y
    double h = 0.1;   // Tamaño del paso
    int n = 10;       // Número de iteraciones
    
    metodoHeun(x0, y0, h, n);
    
    return 0;
}
