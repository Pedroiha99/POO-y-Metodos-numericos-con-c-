#include <iostream>
#include <cmath>

using namespace std;

// Función para calcular el polinomio de Lagrange
double polinomio_lagrange(double x, const double valores_x[], const double valores_y[], int n) {
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {
        double termino = 1.0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                termino *= (x - valores_x[j]) / (valores_x[i] - valores_x[j]);
            }
        }

        resultado += termino * valores_y[i];
    }

    return resultado;
}

// Función para calcular el error relativo
double error_relativo(double valor_interpolado, double valor_real) {
    return abs((valor_interpolado - valor_real) / valor_real) * 100.0;
}

int main() {
    // Datos de ejemplo
    const double valores_x[] = {1, 2, 3, 4, 5};
    const double valores_y[] = {log(1), log(2), log(3), log(4), log(5)};
    int n = sizeof(valores_x) / sizeof(valores_x[0]);

    // Valor a interpolar (x=2.5)
    double x_interpolado = 2.5;

    // Calcular el valor interpolado usando el polinomio de Lagrange
    double valor_interpolado = polinomio_lagrange(x_interpolado, valores_x, valores_y, n);

    // Valor real en x=2.5
    double valor_real = log(2.5);

    // Calcular el error relativo
    double error = error_relativo(valor_interpolado, valor_real);

    // Imprimir el resultado
    cout << "El valor interpolado en x=2.5 es " << valor_interpolado << endl;
    cout << "El valor real en x=2.5 es " << valor_real << endl;
    cout << "El error relativo es " << error << "%" << endl;

    return 0;
}
