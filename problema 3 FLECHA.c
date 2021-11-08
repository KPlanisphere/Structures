//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo.
/* 3. Escriba un programa en C que lea los dos puntos por lo que pasa
una recta e imprima la pendiente de la recta y su ecuación en la forma pendiente
- ordenada al origen. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct 
{
     int x;
     int y;
}punto;

typedef struct
{
     punto p1;
     punto p2;
}recta;

void lectura(recta*);
float pendienterecta(recta*);
void ecuacionrecta(recta* ,float);

int main(){
     recta r;
     float m;
     lectura(&r);
     m = pendienterecta(&r);
     printf("La pendiente es %.2f",m);
     ecuacionrecta(&r,m);
     getch();
     return 0;
}
void lectura(recta *r){
     printf("Ingrese los valores del punto 1 x ");
     scanf("%d", &r->p1.x);
     printf("Ingrese los valores del punto 1 y ");
     scanf("%d", &r->p1.y);
     printf("Ingrese los valores del punto 2 x ");
     scanf("%d", &r->p2.x);
     printf("Ingrese los valores del punto 2 y ");
     scanf("%d", &r->p2.y);
     printf("\nLa formula de la pendiente es: ");
     printf("\nm=(y2)-(y1)/(x2)-(x1) ----> m=(%d)-(%d)/(%d)-(%d)",r->p2.y,r->p1.y,r->p2.x,r->p1.x);
}
float pendienterecta(recta *r){
     float pendiente;
     return pendiente = (float)(r->p2.y - r->p1.y)/(r->p2.x - r->p1.x);
}
void ecuacionrecta(recta *r,float m){
     float b;
     printf("\n\nLa formula de b de pendiente interseccion es: ");
     printf("\nb=(y1)-((m)(x1)) ----> b=(%d)-((%.2f)(%d))",r->p1.y,m,r->p1.x);
     b=(r->p1.y-(m*r->p1.x));
     printf("\nLa ecuacion de forma pendiente ordenada al origen es:");
     if (b >= 0)
     {
          printf(" y = %.2fx+%.2f",m,b);
     }else
     {
          printf(" y = %.2fx%.2f",m,b);
     }
}