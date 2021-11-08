//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo.
/* 1. Escriba un programa que lea dos fracciones e imprima la suma, resta,
multiplicación y división de ambas fracciones. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
     int n;
     int d;
}fraccion;

void lectura(fraccion*,fraccion*);
fraccion suma(fraccion,fraccion,fraccion);
fraccion resta(fraccion,fraccion,fraccion);
fraccion producto(fraccion,fraccion,fraccion);
fraccion division(fraccion,fraccion,fraccion);
fraccion duroweon(fraccion);

int main(){
     fraccion f1, f2, f;
     lectura(&f1,&f2);
     f = suma(f1,f2,f);
     printf("La suma de fracciones es: %d/%d\n", f.n, f.d);
     f = resta(f1,f2,f);
     printf("La resta de fracciones es: %d/%d\n", f.n, f.d);
     f = producto(f1,f2,f);
     printf("El producto de fracciones es: %d/%d\n", f.n, f.d);
     f = division(f1,f2,f);
     printf("La division de fracciones es: %d/%d\n", f.n, f.d);
     getch();
     return 0;
}
void lectura(fraccion *f1, fraccion *f2){
     printf("Fraccion A");
     printf("\nIngrese el valor del numerador en A: ");
     scanf("%d", &f1->n);
     printf("Ingrese el valor del denominador en A: ");
     scanf("%d", &f1->d);
     printf("\nFraccion B");
     printf("\nIngrese el valor del numerador en B: ");
     scanf("%d", &f2->n);
     printf("Ingrese el valor del denominador en B: ");
     scanf("%d", &f2->d);
     system("cls");
}
fraccion suma(fraccion f1,fraccion f2,fraccion f){
     int menor, aux, i, multiplo;
     f.n=(f1.n*f2.d)+(f1.d*f2.n);
     f.d=(f1.d*f2.d);
     duroweon(f);
}
fraccion resta(fraccion f1,fraccion f2,fraccion f){
     int menor, aux, i, multiplo;
     f.n=(f1.n*f2.d)-(f1.d*f2.n);
     f.d=(f1.d*f2.d);
     duroweon(f);
}
fraccion producto(fraccion f1,fraccion f2,fraccion f){
     int menor, aux, i, multiplo;
     f.n=(f1.n*f2.n);
     f.d=(f1.d*f2.d);
     duroweon(f);
}
fraccion division(fraccion f1, fraccion f2,fraccion f){
     int menor, aux, i, multiplo;
     f.n=(f1.n*f2.d);
     f.d=(f1.d*f2.n);
     duroweon(f);
}
fraccion duroweon(fraccion f){
     int menor, aux, i, multiplo;
     do
     {
          if (f.n < f.d)
          {
               menor=f.n;
          }else
          {
               menor=f.d;
          }
          i=2;
          multiplo=0;
          while (i <= menor && multiplo ==0)
          {
               if (f.n%i==0 && f.d%i==0)
               {
                    aux=i;
                    multiplo=1;
               }
               i++;  
          }
          if (multiplo==1)
          {
               f.n=f.n/aux;
               f.d=f.d/aux;
          }
     }while (multiplo==1);
     return f;
}