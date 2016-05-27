#include "funciones.h"


void estadoPeli(EMovie movie[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        movie[i].estado=0;
    }
}

void agregarPelicula(EMovie movie[],FILE *p)
{
    int i;
    estadoPeli(movie);
    for(i=0;i<MAX;i++)
    {
        if(movie[i].estado==0)
        {
            printf("Ingrese Titulo: ");
            fflush(stdin);
            gets(movie[i].titulo);
            while(!v_letras(movie[i].titulo))
            {
                printf("Error, reingrese titulo, solo letras por favor: ");
                fflush(stdin);
                gets(movie[i].titulo);
            }
            strlwr(movie[i].titulo);
            printf("Ingrese genero: ");
            fflush(stdin);
            gets(movie[i].genero);
            while(!v_letras(movie[i].genero))
            {
                printf("Error, reingrese genero, solo letras por favor: ");
                fflush(stdin);
                gets(movie[i].genero);

            }
            printf("Ingrese duracion: ");
            scanf("%d",&movie[i].duracion);
            while(movie[i].duracion<0)
            {
                printf("Error, reingrese de 0 en adelante: ");
                scanf("%d",&movie[i].duracion);
            }

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(movie[i].descripcion);
            while(!v_letras(movie[i].descripcion))
            {
                printf("Error, reingrese descripcion, solo letras por favor: ");
                fflush(stdin);
                gets(movie[i].descripcion);

            }
            printf("Ingrese puntaje: ");
            scanf("%d",&movie[i].puntaje);
            while(movie[i].puntaje<1 || movie[i].puntaje>10)
            {
                printf("Error, solo puntaje del 1 al 10. Reingrese: ");
                scanf("%d",&movie[i].puntaje);
            }
            printf("Link de imagen: ");
            fflush(stdin);
            gets(movie[i].linkImagen);

            movie[i].estado=1;
            fseek(p,0l,SEEK_END);
            fwrite(&movie,sizeof(EMovie),1,p);
            break;
        }


    }


}

void borrarPelicula(EMovie movie[],FILE *p)
{
    char auxpeli[50];
    int i=0;
    printf("Ingrese Titulo de Pelicula a eliminar: ");
    fflush(stdin);
    gets(auxpeli);
    strlwr(auxpeli);

    rewind(p);
    while(!feof(p))
    {
        fread(&movie,sizeof(movie),1,p);
        if(strcmp(auxpeli,movie[i].titulo)==0 && movie[i].estado==1)
        {
            movie[i].estado=0;
            fseek(p,(-1)*sizeof(movie),SEEK_CUR);
            fwrite(&movie,sizeof(movie),1,p);
            break;
        }
    }




}

void ModificarPelicula(EMovie movie[],FILE *p)
{
    char auxpeli[50];
    int i=0;
    printf("Ingrese Titulo de Pelicula a modificar: ");
    fflush(stdin);
    gets(auxpeli);
    strlwr(auxpeli);

    rewind(p);
    while(!feof(p))
    {
        fread(&movie,sizeof(movie),1,p);
        if(strcmp(auxpeli,movie[i].titulo)==0 && movie[i].estado==1)
        {

            printf("Ingrese genero a modificar: ");
            fflush(stdin);
            gets(movie[i].genero);
            while(!v_letras(movie[i].genero))
            {
                printf("Error, reingrese genero, solo letras por favor: ");
                fflush(stdin);
                gets(movie[i].genero);

            }
            printf("Ingrese duracion a modificar: ");
            scanf("%d",&movie[i].duracion);
            while(movie[i].duracion<0)
            {
                printf("Error, reingrese de 0 en adelante: ");
                scanf("%d",&movie[i].puntaje);
            }

            printf("Ingrese descripcion a modificar: ");
            fflush(stdin);
            gets(movie[i].descripcion);
            while(!v_letras(movie[i].descripcion))
            {
                printf("Error, reingrese descripcion, solo letras por favor: ");
                fflush(stdin);
                gets(movie[i].descripcion);

            }
            printf("Ingrese puntaje a modificar: ");
            scanf("%d",&movie[i].puntaje);
            while(movie[i].puntaje<1 || movie[i].puntaje>10)
            {
                printf("Error, solo puntaje del 1 al 10. Reingrese: ");
                scanf("%d",&movie[i].puntaje);
            }
            printf("Link de imagen a modificar: ");
            fflush(stdin);
            gets(movie[i].linkImagen);

            fseek(p,(-1)*sizeof(movie),SEEK_CUR);
            fwrite(&movie,sizeof(movie),1,p);
            break;
        }
    }

    }




void generarPagina(EMovie movie[])
{
     FILE *P;
    int i;

    P = fopen("Pelicula.html", "w");

    if(P==NULL)
    {
        printf("No se puede abrir el archivo\n");
    }
    else
    {
        rewind(P);
    }



    fprintf(P, "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>\n");

    for(i=0; i<MAX; i++){
        if(movie[i].estado==1)
        fprintf(P, "<article class='col-md-4 article-intro'><a href='#'><img class='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>\n",movie[i].linkImagen,movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion);
    }

    fprintf(P, "</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    printf("Archivo creado con exito\n");


}

int v_letras(char vect[])
{
    int i=0;
    while(vect[i]!= '\0')
    {
        if((vect[i]!=' ')&&(vect[i]< 'a' || vect[i]>'z')&&(vect[i]<'A' || vect[i]>'Z'))
            return 0;
        i++;
    }
    return 1;


}


