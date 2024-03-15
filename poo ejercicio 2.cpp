/*                                  tarea 2.
diseñar un programa en C++ empleando una clase llamada RADIO, dada una lista de N flotantes, la clase debe considerar
los miembros siguientes:

                    private:
                        float radio  (yo anexe volumen para guardarlos en otra lista los volumenes)

                    public:
                        leer
                        volumen_esfera
                        suma_volumen
                        menor_volumen

declare en la función principal un objeto para su implementación.
*/

#include <iostream>
#include <math.h>       /*se agrega esta libreria para utilizar POW al calcular el volumen*/
using namespace std;

class radio     /*clase*/
{
        float radios, volumen;      /*parametros*/

        public:     /*métodos*/

        void leer (radio *p, int n);
        void volumen_esfera (radio *p, int n);
        void suma_volumen (radio *p, int n);
        void menor_volumen (radio *p, int n);

};
/*método para ingresar los datos al arreglo*/
    void radio::leer (radio *p, int n)
{
    for (int t=0;t<n;t++)
    {
        cout<<"ingresa el radio de la esfera "<<t+1<<": "<<endl;   cin>>p[t].radios;
    }
}
/*método para calcular el volumen de cada esfera*/
    void radio::volumen_esfera (radio *p, int n)
{
    for(int t=0;t<n;t++)
    {

    p[t].volumen=4*3.1416*pow (p[t].radios,3)/3;
    cout<<"volumen de esfera "<<t+1<<": "<<p[t].volumen<<endl;
    }
}
/*método, suma de volumen de todas las esferas*/
    void radio::suma_volumen (radio *p, int n)
{
    float x=0;

    for(int t=0;t<n;t++)
    {
        x+=p[t].volumen;
    }

    cout<<"la suma del volumen de las esferas es: "<<x<<endl;
}
/* método, se busca el menor valor dentro del arreglo de volumen*/
    void radio::menor_volumen (radio *p, int n)
{
    float x=p[0].volumen;

    for(int t=0;t<n;t++)
        {
        if(p[0].volumen>p[t].volumen)

        x=p[t].volumen;

        }

    cout<<"la esfera con menor volumen "<<x<<endl;

}
int main()
{
    int n;

    cout<<"cuantas esferas desea ingresar: ";   cin>>n;     /*se solicita la cantidad de esferas*/
    radio *r;       /*se crea el objeto dinamico*/


    r=new radio[n];     /*se pide espacio de memoria de tamaño n*/
    r->leer(r,n);       /*se mandan a llamar los métodos*/
    r->volumen_esfera(r,n);
    r->suma_volumen(r,n);
    r->menor_volumen(r,n);
    delete []r;     /*se libera el espacio de memoria */

    return 0;
}
