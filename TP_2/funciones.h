#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MAX 20


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    long int dni;

}EPersona;



void Estado(EPersona lista[]);
int buscarPorDni(EPersona lista[]);
void Datos(EPersona lista[]);
void Listado(EPersona lista[]);
void Grafico(EPersona lista[]);
void Baja(EPersona lista[]);
int validaS_N();
int rangos(EPersona lista[]);
int mayor(int,int,int);





#endif // FUNCIONES_H_INCLUDED

