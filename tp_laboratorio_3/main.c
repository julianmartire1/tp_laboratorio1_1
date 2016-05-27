#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"



int main()
{
    EMovie movie[MAX];

    FILE *P;
    P=fopen("datos.dat","rb+");
    if(P==NULL)
    {
        P=fopen("datos.dat","wb+");
    }



    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(movie,P);
                break;
            case 2:
                system("cls");
                borrarPelicula(movie,P);
                break;
            case 3:
                system("cls");
                ModificarPelicula(movie,P);
               break;
            case 4:
                system("cls");
                generarPagina(movie);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }

    fclose(P);
    return 0;
}
