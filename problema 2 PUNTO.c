//Jesús Huerta Aguilar, Javier de La Luz Ruiz, Ernesto Flores Cesareo
//Programación I - "Programa: Distancia entre dos puntos y punto medio"
///////////////////////   VERSIÓN PUNTO   /////////////////////////
//CARGAR LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
//ESTRUCTURAS
typedef struct{
    float x;
    float y;
}valores;
//PROTOTIPOS
void super();
void lect(valores,valores,valores);
float dist(valores,valores);
valores medio(valores,valores,valores);
void cont(char *);
//PRINCIPAL
int main(){
    char op;
    valores a,b,m;
    do{
        lect(a,b,m);
        cont(&op);
    } while (op == 'S' || op == 's');
    getch();
    return 0;
}
//NOTAS
void super(){
    int i;
    printf("\t\t");
    for ( i = 0; i < 53; i++){
        printf("=");
    }
    printf("\n");
    printf("\t\t\t   PROGRAMACI%cN I     -     EQUIPO 8\n",224);
    printf("\n\t\t - - - DISTANCIA Y PUNTO MEDIO ENTRE DOS PUNTOS - - -\n");
    printf("\t\t\t\t     VERSI%cN PUNTO\n",224);
    printf("\t\t");
    for ( i = 0; i < 53; i++){
        printf("=");
    }
    printf("\n");
}
//LECTURA
void lect(valores a,valores b,valores m){
    int i;
    char l;
    for (i = 0; i < 2; i++){
        super();
        printf("\n%c %c %c %c INGRESA LOS VALORES DE LOS PUNTOS\n",219,219,219,219,219);
        switch (i){
        case 0:
            l = 'A';
            break;
        case 1:
            l = 'B';
            break;
        }
        printf("\n\tVALORES DEL PUNTO %c:\n\n",l);
        printf("\t\tX = ");
        if (i == 0){
            scanf("%f",&a.x);
            printf("\t\tY = ");
            scanf("%f",&a.y);
            
        }
        else{
            scanf("%f",&b.x);
            printf("\t\tY = ");
            scanf("%f",&b.y);
        }
        system("cls");
    }
    super();
    printf("\n\t\t\t %c%c A(%.2f,%.2f)\tB(%.2f,%.2f) %c%c\n",219,219,a.x,a.y,b.x,b.y,219,219);
    printf("\n\n\tDISTANCIA ENTRE A Y B:\tD = %f\n",dist(a,b));
    m = medio(a,b,m);
    printf("\n\tPUNTO MEDIO A Y B:\tC(%.2f,%.2f)\n\n",m.x,m.y);
}
//CALCULAR DISTANCIA
float dist(valores a,valores b){
    float res;
    res = sqrt(((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y)));
    return res;
}
//CALCULAR PUNTO MEDIO
valores medio(valores a,valores b,valores med){
    med.x = (a.x+b.x)/2;
    med.y = (a.y+b.y)/2;
    return med;
}
//CONTINUAR
void cont(char *op){
    int error;
    do{
        error = 0;
        printf("\n%c %c %c %c %cDESEA CONTINUAR? [S/N] >> ",219,219,219,219,168);
        scanf("%s",op);
        if (*op == 's' || *op == 'S'){
            system("cls");
        }
        else{
            if (*op == 'n' || *op == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n\t\t\t[!] ERROR: Ingresa una opci%cn valida [!]\n",162);
                error = 1;
            }
        }
    } while (error == 1);
}