#include <iostream>
#include <cmath>

using namespace std;
// Función diferencial para los utimos métodos
double funcionDiferencial(double t, double y)
{
    return -2 * t * y; // Cambia esta función por la ecuación diferencial deseada
}

// Funciones de los métodos numéricos 1,2 y 3
double f(double x) {
    // Función a aproximar
    return x * x - 4;
}
///////////////////////////////////////////////////biseccion//////////////////////////////////////////////////////
double biseccion(double a, double b, double tol) {
    cout<<"Método de bisección para encontrar una raíz de la función"<<endl;
    double c;
    while (abs(b - a) > tol) {
        c = (a + b) / 2.0;
        if (f(c) == 0) {
            return c;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}
//////////////////////////////////////////////////secante//////////////////////////////////////////////////////////
double secante(double x0, double x1, double tol) {
    cout<<"Método de la secante para encontrar una raíz de la función"<<endl;
    double x;
    double fx0 = f(x0);
    double fx1 = f(x1);
    double fx;
    do {
        x = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
        fx = f(x);
        x0 = x1;
        x1 = x;
        fx0 = fx1;
        fx1 = fx;
    } while (abs(fx) > tol);
    return x;
}
////////////////////////////////////////////////////tangente////////////////////////////////////////////////////////
double tangente(double x0, double tol) {
    cout<<"Método de la tangente (Newton-Raphson) para encontrar una raíz de la función"<<endl;
    double x = x0;
    double fx = f(x);
    double fprime;
    do {
        fprime = (f(x + tol) - fx) / tol;
        x = x - (fx / fprime);
        fx = f(x);
    } while (abs(fx) > tol);
    return x;
}
/////////////////////////////////////////////////////////gauss///////////////////////////////////////////////////////
void metodoGauss(double matriz[3][3], double b[3])
{
    // Eliminación hacia adelante
    for (int k = 0; k < 2; k++)
    {
        for (int i = k + 1; i < 3; i++)
        {
            double factor = matriz[i][k] / matriz[k][k];
            for (int j = k; j < 3; j++)
            {
                matriz[i][j] -= factor * matriz[k][j];
            }
            b[i] -= factor * b[k];
        }
    }

    // Sustitución hacia atrás
    double x[3];
    x[2] = b[2] / matriz[2][2];
    x[1] = (b[1] - matriz[1][2] * x[2]) / matriz[1][1];
    x[0] = (b[0] - matriz[0][1] * x[1] - matriz[0][2] * x[2]) / matriz[0][0];

    // Imprimir la solución
    cout << "La solución utilizando el método de Gauss es: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}
////////////////////////////////////////////////////////////////////Gauss-Jordan//////////////////////////////////
void metodoGaussJordan(double matriz[3][3], double b[3])
{
    // Combinar matriz A y vector b en una matriz extendida
    double matrizExtendida[3][4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrizExtendida[i][j] = matriz[i][j];
        }
        matrizExtendida[i][3] = b[i];
    }

    // Transformar la matriz extendida a su forma escalonada reducida
    for (int k = 0; k < 3; k++)
    {
        double pivot = matrizExtendida[k][k];

        for (int j = 0; j < 4; j++)
        {
            matrizExtendida[k][j] /= pivot;
        }

        for (int i = 0; i < 3; i++)
        {
            if (i != k)
            {
                double factor = matrizExtendida[i][k];
                for (int j = 0; j < 4; j++)
                {
                    matrizExtendida[i][j] -= factor * matrizExtendida[k][j];
                }
            }
        }
    }

    // Extraer la solución del sistema
    double x[3];
    for (int i = 0; i < 3; i++)
    {
        x[i] = matrizExtendida[i][3];
    }

    // Imprimir la solución
    cout << "La solución utilizando el método de Gauss-Jordan es: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }
}
///////////////////////////////////////////////////////////Gauss-Seidel/////////////////////////////////////////////
void metodoGaussSeidel(double matriz[3][3], double b[3])
{
    double x[3] = {0}; // Inicialización de las incógnitas a cero

    // Iteraciones del método de Gauss-Seidel
    int iteracionesMaximas = 100;
    double tolerancia = 1e-6;
    int iteracion = 0;
    double error = tolerancia + 1;

    while (error > tolerancia && iteracion < iteracionesMaximas)
    {
        double xAnterior[3];
        for (int i = 0; i < 3; i++)
        {
            xAnterior[i] = x[i];
        }

        for (int i = 0; i < 3; i++)
        {
            double suma = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                {
                    suma += matriz[i][j] * x[j];
                }
            }
            x[i] = (b[i] - suma) / matriz[i][i];
        }

        error = 0;
        for (int i = 0; i < 3; i++)
        {
            error += abs(x[i] - xAnterior[i]);
        }

        iteracion++;
    }

    // Imprimir la solución
    if (iteracion >= iteracionesMaximas)
    {
        cout << "El método de Gauss-Seidel no convergió después de " << iteracionesMaximas << " iteraciones." << endl;
    }
    else
    {
        cout << "La solución utilizando el método de Gauss-Seidel es: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
    }
}
//////////////////////////////////////////////////////polinomioNewton//////////////////////////////////////////////
double polinomioNewton(double x, double xData[], double yData[], int n)
{
    // Calcular las diferencias divididas
    double coeficientes[n];
    for (int i = 0; i < n; i++)
    {
        coeficientes[i] = yData[i];

        for (int j = i - 1; j >= 0; j--)
        {
            coeficientes[j] = (coeficientes[j + 1] - coeficientes[j]) / (xData[i] - xData[j]);
        }
    }

    // Evaluar el polinomio de Newton en el punto x
    double resultado = coeficientes[0];
    double producto = 1.0;
    for (int i = 1; i < n; i++)
    {
        producto *= (x - xData[i - 1]);
        resultado += coeficientes[i] * producto;
    }

    return resultado;
}
///////////////////////////////////////////////////////polinomioLagrange///////////////////////////////////////////////////
// Función para calcular el polinomio de Lagrange
double polinomioLagrange(double x, double xData[], double yData[], int n)
{
    double resultado = 0.0;

    for (int i = 0; i < n; i++)
    {
        double producto = 1.0;

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                producto *= (x - xData[j]) / (xData[i] - xData[j]);
            }
        }

        resultado += producto * yData[i];
    }

    return resultado;
}
//////////////////////////////////////////////////////////minimosCuadrados////////////////////////////////////////
// Función para calcular los mínimos cuadrados
void minimosCuadrados(double xData[], double yData[], int n)
{
    double sumaX = 0.0, sumaY = 0.0, sumaXY = 0.0, sumaX2 = 0.0;

    for (int i = 0; i < n; i++)
    {
        sumaX += xData[i];
        sumaY += yData[i];
        sumaXY += xData[i] * yData[i];
        sumaX2 += xData[i] * xData[i];
    }

    double a = (n * sumaXY - sumaX * sumaY) / (n * sumaX2 - sumaX * sumaX);
    double b = (sumaY - a * sumaX) / n;

    cout << "La ecuación de mínimos cuadrados es: y = " << a << "x + " << b << endl;
}
////////////////////////////////////////////////////trapecio///////////////////////////////////////////////////////
// Método del trapecio
double metodoTrapecio(double a1, double b1, int n1)
{
    double h = (b1 - a1) / n1;
    double suma = 0.0;

    for (int i = 1; i < n1; i++)
    {
        double x = a1 + i * h;
        suma += f(x);
    }

    double integral = h * (0.5 * (f(a1) + f(b1)) + suma);
    return integral;
}
/////////////////////////////////////////////////////metodoSimpson13///////////////////////////////////////////////////
// Método de Simpson 1/3
double metodoSimpson13(double a1, double b1, int n1)
{
    if (n1 % 2 != 0)
    {
        cout << "El número de subintervalos debe ser par para el método de Simpson 1/3." << endl;
        return 0.0;
    }

    double h = (b1 - a1) / n1;
    double sumaPar = 0.0;
    double sumaImpar = 0.0;

    for (int i = 1; i < n1; i++)
    {
        double x = a1 + i * h;

        if (i % 2 == 0)
        {
            sumaPar += f(x);
        }
        else
        {
            sumaImpar += f(x);
        }
    }

    double integral = h / 3.0 * (f(a1) + 4.0 * sumaImpar + 2.0 * sumaPar + f(b1));
    return integral;
}
/////////////////////////////////////////////////////metodoSimpson38/////////////////////////////////////
// Método de Simpson 3/8
double metodoSimpson38(double a1, double b1, int n1)
{
    if (n1 % 3 != 0)
    {
        cout << "El número de subintervalos debe ser múltiplo de 3 para el método de Simpson 3/8." << endl;
        return 0.0;
    }

    double h = (b1 - a1) / n1;
    double suma1 = 0.0;
    double suma2 = 0.0;
    double suma3 = 0.0;

    for (int i = 1; i < n1; i++)
    {
        double x = a1 + i * h;

        if (i % 3 == 0)
        {
            suma3 += f(x);
        }
        else if (i % 3 == 1)
        {
            suma1 += f(x);
        }
        else
        {
            suma2 += f(x);
        }
    }

    double integral = 3.0 * h / 8.0 * (f(a1) + 3.0 * suma1 + 3.0 * suma2 + 2.0 * suma3 + f(b1));
    return integral;
}
////////////////////////////////////////////////////Euler///////////////////////////////////////////////////
// Método de Euler
double metodoEuler(double t0, double y0, double h, double tf)
{
    int n = static_cast<int>((tf - t0) / h);
    double t = t0;
    double y = y0;

    for (int i = 0; i < n; i++)
    {
        double f = funcionDiferencial(t, y);
        y = y + h * f;
        t = t + h;
    }

    return y;
}
///////////////////////////////////////////////////Heun/////////////////////////////////////////////////////////
// Método de Heun
double metodoHeun(double t0, double y0, double h, double tf)
{
    int n = static_cast<int>((tf - t0) / h);
    double t = t0;
    double y = y0;

    for (int i = 0; i < n; i++)
    {
        double f1 = funcionDiferencial(t, y);
        double f2 = funcionDiferencial(t + h, y + h * f1);
        y = y + 0.5 * h * (f1 + f2);
        t = t + h;
    }

    return y;
}
////////////////////////////////////////////////Runge-Kutta//////////////////////////////////////////////////////
// Método de Runge-Kutta de cuarto orden
double metodoRungeKutta(double t0, double y0, double h, double tf)
{
    int n = static_cast<int>((tf - t0) / h);
    double t = t0;
    double y = y0;

    for (int i = 0; i < n; i++)
    {
        double k1 = h * funcionDiferencial(t, y);
        double k2 = h * funcionDiferencial(t + 0.5 * h, y + 0.5 * k1);
        double k3 = h * funcionDiferencial(t + 0.5 * h, y + 0.5 * k2);
        double k4 = h * funcionDiferencial(t + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        t = t + h;
    }

    return y;
}
/////////////////////////////////////////////////

// Implementa el resto de los métodos numéricos aquí

int main() {
    int opcion;
    double resultado;
    
    cout << "Bienbenido, en este programa podras calcular distintas operaciones con métodos numericos " << endl;
    cout << "Seleccione un método numérico:" << endl;
    cout << "1. Bisección" << endl;
    cout << "2. Secante" << endl;
    cout << "3. Tangente (Newton-Raphson)" << endl;
    
    // Agrega el resto de las opciones aquí

    cout << "escoge cualquier otro numero para continuar con los métodos " <<endl;
    cin >> opcion;

    switch (opcion) {
        case 1:
            resultado = biseccion(0, 2, 0.001);
            cout << "El resultado de la bisección es: " << resultado << endl;
            break;
        case 2:
            resultado = secante(0, 2, 0.001);
            cout << "El resultado de la secante es: " << resultado << endl;
            break;
        case 3:
            resultado = tangente(0, 0.001);
            cout << "El resultado de la tangente es: " << resultado << endl;
            break;
           
        // Agrega el resto de los casos para los otros métodos numéricos aquí

        default:
            cout << "..." << endl;
            break;
    }
    
    cout <<"para los siguientes métodos debes de ingresar la matriz a calcular"<< endl;
    
     double matriz[3][3];
    double b[3];

    cout << "Ingrese los coeficientes de la matriz A: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Ingrese el elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    cout << "Ingrese los coeficientes del vector b: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingrese el elemento b[" << i + 1 << "]: ";
        cin >> b[i];
    }

    
     int opciona;
    cout << "Seleccione un método numérico:" << endl;
    cout << "1. Gauss" << endl;
    cout << "2. Gauss-Jordan" << endl;
    cout << "3. Gauss-Seidel" << endl;
    cout << "escoge cualquier otro numero para continuar con los métodos ";
    cin >> opciona;

    switch (opciona)
    {
    case 1:
        metodoGauss(matriz, b);
        break;
    case 2:
        metodoGaussJordan(matriz, b);
        break;
    case 3:
        metodoGaussSeidel(matriz, b);
        break;
    default:
        cout << "..." << endl;
        break;
    }    
    
    cout <<"para los siguientes métodos se usan una lista de datos para aproximar al punto deseado"<< endl;
    cout <<"puedes cambiar la cantidad de datos a ingresar y el valor de los mismos"<< endl;
    const int n = 5;
    double xData[n] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double yData[n] = {1.0, 4.0, 9.0, 16.0, 25.0};

    int opcionb;
    cout << "Seleccione un método numérico:" << endl;
    cout << "1. Polinomio de Newton" << endl;
    cout << "2. Polinomio de Lagrange" << endl;
    cout << "3. Mínimos Cuadrados" << endl;
    cout << "escoge cualquier otro numero para continuar con los métodos ";
    cin >> opcionb;
    
        switch (opcionb)
    {
    case 1:
    {
        double x;
        cout << "Ingrese el valor de x para evaluar el polinomio de Newton: ";
        cin >> x;

        double resultado = polinomioNewton(x, xData, yData, n);
        cout << "El resultado del polinomio de Newton para x = " << x << " es: " << resultado << endl;

        break;
    }
    case 2:
    {
        double x;
        cout << "Ingrese el valor de x para evaluar el polinomio de Lagrange: ";
        cin >> x;

        double resultado = polinomioLagrange(x, xData, yData, n);
        cout << "El resultado del polinomio de Lagrange para x = " << x << " es: " << resultado << endl;

        break;
    }
    case 3:
    {
        minimosCuadrados(xData, yData, n);
        break;
    }
    default:
        cout << "..." << endl;
        break;
    }
    
    cout <<"para los siguientes métodos necesitas ingresar los rangos de x (a,b)"<< endl;
    cout <<""<< endl;
    double a1, b1;
    int n1;
    int opcionc;

    cout << "Ingrese el límite inferior de integración: ";
    cin >> a1;

    cout << "Ingrese el límite superior de integración: ";
    cin >> b1;

    cout << "Ingrese el número de subintervalos (n): ";
    cin >> n1;

    cout << "Seleccione un método numérico:" << endl;
    cout << "1. Método del trapecio" << endl;
    cout << "2. Método de Simpson 1/3" << endl;
    cout << "3. Método de Simpson 3/8" << endl;
    cout << "escoge cualquier otro numero para continuar con los métodos";
    cin >> opcionc;

    switch (opcionc)
    {
    case 1:
    {
        double integralTrapecio = metodoTrapecio(a1, b1, n1);
        cout << "El valor aproximado de la integral utilizando el método del trapecio es: " << integralTrapecio << endl;
        break;
    }
    case 2:
    {
        double integralSimpson13 = metodoSimpson13(a1, b1, n1);
        cout << "El valor aproximado de la integral utilizando el método de Simpson 1/3 es: " << integralSimpson13 << endl;
        break;
    }
    case 3:
    {
        double integralSimpson38 = metodoSimpson38(a1, b1, n1);
        cout << "El valor aproximado de la integral utilizando el método de Simpson 3/8 es: " << integralSimpson38 << endl;
        break;
    }
    default:
        cout << "..." << endl;
        break;
    }
    
    cout <<"estos son los ultimos 3 métodos"<< endl;
    
    double t0, y0, h, tf;
    int opciond;

    cout << "Ingrese el valor inicial de t: ";
    cin >> t0;

    cout << "Ingrese el valor inicial de y(" << t0 << "): ";
    cin >> y0;

    cout << "Ingrese el tamaño del paso (h): ";
    cin >> h;

    cout << "Ingrese el valor final de t: ";
    cin >> tf;

    cout << "Seleccione un método numérico:" << endl;
    cout << "1. Método de Euler" << endl;
    cout << "2. Método de Heun" << endl;
    cout << "3. Método de Runge-Kutta de cuarto orden" << endl;
    cout << "Ingrese el número correspondiente al método deseado: ";
    cin >> opciond;
    
        switch (opciond)
    {
    case 1:
    {
        double yEuler = metodoEuler(t0, y0, h, tf);
        cout << "El valor aproximado de y(" << tf << ") utilizando el método de Euler es: " << yEuler << endl;
        break;
    }
    case 2:
    {
        double yHeun = metodoHeun(t0, y0, h, tf);
        cout << "El valor aproximado de y(" << tf << ") utilizando el método de Heun es: " << yHeun << endl;
        break;
    }
    case 3:
    {
        double yRungeKutta = metodoRungeKutta(t0, y0, h, tf);
        cout << "El valor aproximado de y(" << tf << ") utilizando el método de Runge-Kutta de cuarto orden es: " << yRungeKutta << endl;
        break;
    }
    default:
        cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        break;
    }


    
    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Echo por Hernandez Ayala Pedro Ivan y Andrik Guillermo Guevara Toriz Grupo 3FV1" << endl;
    cout << "pudes cambiar la funcion para calcular cualquier f(x) desde el codigo" << endl;
    cout << "y cambiar los valores de entrada desde el main en el area de llamado de la funcion" << endl;
    return 0;
}        
