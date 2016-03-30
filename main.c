#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0,band=0,band1=0;
    float x,y;
    while(seguir=='s')
    {

        printf("\n 1- Ingresar 1er operando (A=x)\n");
        printf("\n 2- Ingresar 2do operando (B=y)\n");
        printf("\n 3- Calcular la suma (A+B)\n");
        printf("\n 4- Calcular la resta (A-B)\n");
        printf("\n 5- Calcular la division (A/B)\n");
        printf("\n 6- Calcular la multiplicacion (A*B)\n");
        printf("\n 7- Calcular el factorial (A!)\n");
        printf("\n 8- Calcular todas las operacione\n");
        printf("\n 9- Salir\n");

        scanf("%d",&opcion);
        system("cls");


        switch(opcion)
        {
            case 1:
                printf("Ingrese primer operando: ");
                scanf("%f",&x);
                band=1;
                break;
            case 2:
                printf("Ingrese segundo operando: ");
                scanf("%f",&y);
                band1=1;
                break;
            case 3:
                if(band==1 && band1==1)
                {
                    printf("La suma es: %.2f  \n",suma(x,y));
                }
                break;


            case 4:
                if(band==1 && band1==1)
                {
                    printf("La resta es: %.2f  \n",resta(x,y));
                }

                break;
            case 5:
                if(band==1 && band1==1)
                {
                    printf("La division es: %.2f",division(x,y));
                }
                break;
            case 6:
                if(band==1 && band1==1)
                {
                    printf("La multiplicacion es : %.2f",multiplicacion(x,y));
                }
                break;
            case 7:

                if(band==1)
                {
                    printf("El factorial es: %.2f",factorial(x));
                }
                break;
            case 8:
                if(band==1 && band1==1)
                {
                    printf("La suma es: %.2f  \n",suma(x,y));
                    printf("La resta es: %.2f  \n",resta(x,y));
                    printf("La division es: %.2f \n",division(x,y));
                    printf("La multiplicacion es : %.2f \n",multiplicacion(x,y));
                }
                if(band==1)
                {
                    printf("El factorial es: %.2f",factorial(x));
                }

                break;
            case 9:
                seguir = 'n';
                break;
        }

    }


    return 0;
}
