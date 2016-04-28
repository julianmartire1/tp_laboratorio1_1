#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{
    char seguir='s';
    int opcion=0;
    EPersona lista[MAX];
    Estado(lista);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                Datos(lista);

                break;
            case 2:
                Baja(lista);
                break;
            case 3:
                Listado(lista);
                break;
            case 4:
                Grafico(lista);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
