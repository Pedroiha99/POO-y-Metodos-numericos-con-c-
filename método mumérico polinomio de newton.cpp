#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Función para calcular las diferencias divididas
double diferencia_dividida(double x1, double x2, double y1, double y2) {
    return (y2 - y1) / (x2 - x1);
}

// Función para evaluar el polinomio de Newton en un punto dado
double interpolacion_newton(double x, const vector<double>& valores_x, const vector<double>& valores_y) {
    int n = valores_x.size();

    // Calcular las diferencias divididas
    vector<vector<double>> diferencias(n, vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        diferencias[i][0] = valores_y[i];
    }
    
    for (int j = 1; j < n; j++) {
        
        for (int i = 0; i < n - j; i++) {
            
            diferencias[i][j] = diferencia_dividida(valores_x[i], valores_x[i + j], diferencias[i][j - 1], diferencias[i + 1][j - 1]);
     
        }
    }

    // Calcular el valor interpolado usando el polinomio de Newton
    double resultado = diferencias[0][0];
    double termino = 1.0;
    for (int i = 1; i < n; i++) {
        termino *= (x - valores_x[i - 1]);
        resultado += termino * diferencias[0][i];
    }

    return resultado;
}

// Calcular el error relativo entre el valor interpolado y el valor real
double error_relativo(double valor_interpolado, double valor_real) {
    return abs((valor_interpolado - valor_real) / valor_real) * 100.0;
}

int main() {
    // Datos de ejemplo usando ln de 1, 2, 3...6
    vector<double> valores_x(6);// = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    vector<double> valores_y(6);// = {0, 0.3010299957, 0.4771212547, 0.6020599913, 0.6989700043, 0.7781512504};
    
    for(int i=0;i<6;i++){
        valores_x[i]=i+1;
        valores_y[i]=log(i+1);
    }
    
    
    // Valor a interpolar
    double x = 2.5;

    // Calcular el valor interpolado usando el polinomio de Newton
    double valor_interpolado = interpolacion_newton(x, valores_x, valores_y);
    
     // Valor real de la función en el punto a interpolar
    double valor_real = log(x);
    
    // Calcular el error relativo
    double error = error_relativo(valor_interpolado, valor_real);

    // Imprimir el resultado
    cout << "El valor interpolado en x = " << x << " es " << valor_interpolado << endl;
    cout << "El valor real en x = " << x << " es " << valor_real << endl;
    cout << "El error relativo es " << error << "%" << endl;

    return 0;
}