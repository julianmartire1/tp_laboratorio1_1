#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"



void Estado(EPersona lista[])
{
    int i;
    for(i=0; i<MAX; i++)
    {
        lista[i].estado=1;
    }
}
void Baja(EPersona lista[])
{
    int i,auxDni;
    char rta;
    auxDni=buscarPorDni(lista);

    for(i=0; i<MAX; i++)
    {
        if(auxDni == i && lista[auxDni].estado==0)
        {
            printf("Desea eliminar ");
            rta=validaS_N();
            if(rta==1)
            lista[i].estado=1;

            break;
        }

    }
    if(i==MAX)
    {
       printf("No existe el dni buscado");
    }



}


void Datos(EPersona lista[])
{
    int i;

    for(i=0; i<MAX; i++)
    {
        if(lista[i].estado==1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);

            printf("Ingrese edad: ");
            scanf("%d",&lista[i].edad);




            printf("Ingrese dni: ");
            scanf("%li", &lista[i].dni);




            lista[i].estado=0;
            break;
        }
    }
    if(i==MAX)
    {
        printf("Capacidad agotada!!!");
    }
}





void Listado(EPersona lista[])
{
    int i, j;
    EPersona auxP;

    for(i=0; i<MAX-1; i++)
    {
        for(j=i+1; j<MAX; j++)
        {
            if(lista[j].estado!=1)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxP=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxP;
                }
            }

        }
    }







    for(i=0;i<MAX; i++)
    {
        if(lista[i].estado==0)
            printf("Nomb: %s  DNI: %li  Edad:  %d\n",lista[i].nombre, lista[i].dni,lista[i].edad);
    }
}
int buscarPorDni(EPersona lista[])
{
    int indice=0,i;
    long int auxdni;
    printf("Ingrese DNI a buscar: ");
    scanf("%li",&auxdni);
    for(i=0;i<MAX;i++)
    {
        if (auxdni==lista[i].dni)
        {
            indice=i;
            break;
        }


    }
    return indice;
}
void Grafico(EPersona lista[])
{

    int rango1 = 0 ,rango2 = 0,rango3 = 0,i,maximo=0,flag=0;




    for(i=0;i<MAX;i++)
    {
        if(lista[i].estado == 0)
        {
            if(lista[i].edad < 19 )
           {
            rango1++;
           }
        if(lista[i].edad > 18 && lista[i].edad < 36)
            {
                rango2++;
            }
        if(lista[i].edad > 35)
            {
                    rango3++;
            }

        }

    }

    if(rango1 > rango2 && rango1 > rango3)
    {
        maximo = rango1;
    }
    else
    {
                if( rango2 > rango1 && rango2 >= rango3)
                    {
                        maximo = rango2;
                    }
                     else
                       {

                        maximo = rango3;
                       }
     }
     for(i=maximo; i>0; i--)
        {
        if(i<= rango1){
            printf("*");
        }
        if(i<= rango2)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= rango3)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("<18\t19-35\t>35\n");





}







int validaS_N()
{
    char respuesta;

    printf("S/N?");
    fflush(stdin);
    scanf("%c", &respuesta);
    respuesta = toupper(respuesta);

    //Validacion de char S o N como validos
    while(respuesta != 'S' && respuesta != 'N'){
        printf("ERROR REINGRESE, Continua S/N?");
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta = toupper(respuesta);
    }

    if(respuesta == 'S'){
        return 1;
    }
    else{
        return 0;
    }
}


