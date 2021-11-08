//4. Agenda version normal

//Librerias
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//Estructura de datos
typedef struct{
	int dia,mes,anyo;
}Fecha;
typedef struct{
	char nombre[15];
	char apellido[30];
	char telefono[15];
	char correo[40];
	Fecha fecha;
}agenda;
agenda agen[100];
int cont=0;
//Prototipos
void nota();
void alta();
void eliminar();
void buscar();
void lista();
void final(char *,int);
//Principal
int main (){
	int op,error;
	char op2;
	do{
		do{
			error=0;
			printf ("\t\t%c\t\t        %c\n",201,187);
			printf ("\t\t%c Opciones en la agenda %c",186,186);
			printf ("\n\t\t%c\t\t        %c\n",200,188);
			printf ("\n%c Seleccione la opci%cn a realizar:\n",219,162);
			printf ("\n\t%c[1] Dar de alta a una persona.",175);
			printf ("\n\t%c[2] Eliminar a una persona.",175);
			printf ("\n\t%c[3] Buscar a una persona.",175);
			printf ("\n\t%c[4] Listar a todos en la agenda.",175);
			printf ("\n\t%c[5] Salir.",175);
			printf ("\n\n=");
			scanf ("%d",&op);
			if (op<1 || op>5){
				printf ("\n[!] ERROR: Opci%cn no v%clida [!]",162,160);
				error=1;
				getch();
				system("cls");
			}
		}while(error!=0);
		switch(op){
			case 1:
				alta();
				break;
			case 2:
				eliminar();
				break;
			case 3:
				buscar();
				break;
			case 4:
				lista();
				break;	
		}
		final(&op2,op);
	}while(op2 == 's' || op2 == 'S');
	getch();
	return 0;
}
void nota (){
	printf("Ingresando los datos de la persona n%cmero %d\n",163,cont+1);	
}
void alta (){
	system("cls");
	int error;
	nota();
	printf("\n%c Nombre de la persona: ",219);
	fflush(stdin);
	gets(agen[cont].nombre);
	system("cls");
	nota();  
	printf("\n%c Apellidos de la persona: ",219);
	fflush(stdin);
	gets(agen[cont].apellido);
	system("cls");
	nota();
	do{
		error=0;	
		printf("\n%c N%cmero telef%cnico: ",219,163,162);
		fflush(stdin);
		gets(agen[cont].telefono);
		if (strlen(agen[cont].telefono)==10){
		system("cls");
		}else{
			error=1;
			printf("[!] ERROR: N%cmero telef%cnico inv%clido [!]",163,162,160);
		}
	}while(error!=0);
	nota();
	printf("\n%c Correo electr%cnico: ",219,162);
	fflush(stdin);
	gets(agen[cont].correo);
	system("cls");
	nota();
	printf("\n%c Fecha de Nacimiento:",219);
	do{
		error=0;
		printf("\n\n%c D%ca: ",175,161);
		scanf("%d",&agen[cont].fecha.dia);
		if (agen[cont].fecha.dia<1 || agen[cont].fecha.dia>31){
			printf("[!] ERROR: D%ca ingresado inv%clido [!]",161,160);
			error=1;
		}
	}while(error!=0);
	do{
		error=0;
		printf("\n\n%c Mes: ",175);
		scanf("%d",&agen[cont].fecha.mes);
		if (agen[cont].fecha.mes<1 || agen[cont].fecha.mes>12){
			printf("[!] ERROR: Mes ingresado inv%clido [!]",160);
			error=1;
		}
	}while(error!=0);
	do{
		error=0;
		printf("\n\n%c A%co: ",175,164);
		scanf("%d",&agen[cont].fecha.anyo);
		if (agen[cont].fecha.anyo<1941 || agen[cont].fecha.anyo>2013){
			printf("[!] ERROR: A%co ingresado inv%clido [!]",164,160);
			error=1;
		}
	}while(error!=0);
	
	cont++;
}
void eliminar(){
	system("cls");
	int pos;
	int i;
	if (cont == 0){
		printf("\n\t[!] ERROR: No hay contactos registrados [!]\n");
	}
	else{
		printf("\n\tNOTA:Puedes consultar el n%cmero que necesitas en la opci%cn %clistar...%c\n",163,162,34,34);
		printf("\nIngrese el n%cmero de contacto en la agenda para eliminar: ",163,162);
		scanf("%d",&pos);
		if (pos-1 < cont){
			if (pos-1 == cont-1){
				cont -=1;
			}
			else{
				for (i = pos-1; i < cont; i++){
					strcpy(agen[i].nombre,agen[i+1].nombre);
					strcpy(agen[i].apellido,agen[i+1].apellido);
					strcpy(agen[i].telefono,agen[i+1].telefono);
					strcpy(agen[i].correo,agen[i+1].correo);
					agen[i].fecha.dia=agen[i+1].fecha.dia;
					agen[i].fecha.mes=agen[i+1].fecha.mes;
					agen[i].fecha.anyo=agen[i+1].fecha.anyo;
				}		
				cont-=1;
			}
			printf("\n%c Datos ingresados eliminados.\n",219);
		}
		else
		{
			printf("\n\t[!] ERROR: No hay contactos registrados [!]\n");
		}
	}
}
void buscar (){
	system ("cls");
	char num [10];
	int i,aux=0;
	printf("Ingrese el n%cmero telef%cnico de la persona a buscar: ",163,162);
	fflush(stdin);
	gets(num);
	for(i = 0; i < cont; i++){
		if (strcmp(num,agen[i].telefono)==0){
			printf("\n%c%c%c%c Persona registrada #%d %c%c%c%c",205,205,205,205,i+1,205,205,205,205);
			printf("\nNombre completo: %s %s\n",agen[i].nombre,agen[i].apellido);
			printf("N%cmero Tel%cfonico: %s\n",163,162,agen[i].telefono);
			printf("Correo electr%cnico: %s\n",162,agen[i].correo);
			printf("Fecha de Nacimiento: %02d/%02d/%04d\n",agen[i].fecha.dia,agen[i].fecha.mes,agen[i].fecha.anyo);	
			aux=1;			
		}	
	}
	if(aux==0){
		printf("\n%c Datos ingresados no registrados.\n",219);
	}
}
void lista (){
	system ("cls");
	int i;
	printf("\n	    %CAGENDA%C\n",207,207);
	if (cont == 0){
		printf("\n\t[!] ERROR: No hay contactos registrados [!]\n");
	}
	else{
		for(i=0;i<cont;i++){
			printf("\n%c%c%c%c Persona registrada #%d %c%c%c%c",205,205,205,205,i+1,205,205,205,205);
			printf("\nNombre completo: %s %s\n",agen[i].nombre,agen[i].apellido);
			printf("N%cmero Tel%cfonico: %s\n",163,162,agen[i].telefono);
			printf("Correo electr%cnico: %s\n",162,agen[i].correo);
			printf("Fecha de Nacimiento: %02d/%02d/%04d\n",agen[i].fecha.dia,agen[i].fecha.mes,agen[i].fecha.anyo);	
		}
	}
}
void final(char *op2,int op){
    int error;
    do{
        error = 0;
        if (op == 5){
            *op2 = 'N'; 
        }
        else{
            printf("\n%cDesea realizar otra operaci%cn dentro de la agenda? (s/n) %c ",168,162,175);
            scanf("%s",op2);
        }
        if (*op2 == 's' || *op2 == 'S'){
            system("cls");
        }
        else{
            if (*op2 == 'n' || *op2 == 'N'){
                system("cls");
                printf("\n\n\tGRACIAS POR USAR NUESTROS SERVICIOS");
                printf("\n\n\t   Equipo 8\t-\tBUAP");
            }
            else{
                printf("\n[!] ERROR: Ingresa una opci%cn valida [!]",162);
                error = 1;
            }
        }
    } while (error!=0); 
}