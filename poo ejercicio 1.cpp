/*                  tarea 1.
dise�e un programa en C++ empleando para ello una clase que lleve por nombre SUMATORIAS, dada una lista de N enteros.
la clase debe considerar los miembros siguientes:

        atributos private:
                        int enteros

        m�todos publicos:
                        leer
                        suma_pares
                        prom_pares
                        suma_nones
                        prom_nones

declare en la funci�n principal un objeto para su implementaci�n.
*/


#include <iostream>

using namespace std;
         /*clase base*/
class sumatorias{
        /*atributos*/
    int enteros;
        /*m�todos*/
    public:

    void leer (sumatorias *p, int n);
    void suma_pares (sumatorias *p, int n);
    void prom_pares (sumatorias *p, int n);
    void suma_nones (sumatorias *p, int n);
    void prom_nones (sumatorias *p, int n);

};

        /*desarrollo del m�todo leer, tenemos como argumento el puntero *p y el int n, en este metodo pedimos datos */
   void sumatorias::leer (sumatorias *p, int n)
   {

     for(int t=0;t<n;t++){
       cout<< "ingresa el entero "<<t+1<<": "; cin>>p[t].enteros;
     }
   }

   /*desarrollo de m�todo suma_pares,en esta misma funcion agrege unos pasos para sacar el promedio */

   void sumatorias::suma_pares (sumatorias *p, int n)
   {
       int x=0, y=0, prom;

       for (int t=0; t<n; t++)
          {
              if (p[t].enteros%2==0)
                {
                x+=p[t].enteros;

                y++;
                }
          }
          prom=x/y;
          cout<<"la suma de numeros pares es "<<x<<endl;
          cout<<"el promedio de la suma de pares es "<<prom<<endl;


   }

      /*desarrollo de m�todo suma_nones,en esta misma funcion agrege unos pasos para sacar el promedio */


   void sumatorias::suma_nones (sumatorias *p, int n)
   {
       int x=0, y=0, prom;

       for (int t=0; t<n; t++)
          {
              if (p[t].enteros%2==!0)
                {
                x+=p[t].enteros;

                y++;

                }
           }
          prom=x/y;
          cout<<"la suma de numeros nones es "<<x<<endl;
          cout<<"el promedio de la suma de nones es "<<prom<<endl;

   }





int main()
{
    /*cantidad de elementos del arreglo*/
    int n;
    /*se solicita ingresar el numero de elementos*/
    cout<<"cuantos enteros desea ingresar: "; cin>>n;
    /*se crea un objeto dinamico (sumatorias *s)*/
    sumatorias *s;

    /*se solicita memoria dinamica con new*/
    s=new sumatorias[n];
    s->leer(s,n);
    s->suma_pares(s,n);
    s->suma_nones(s,n);
    /*se libera memoria dinamica*/
    delete[]s;

    return 0;
}
