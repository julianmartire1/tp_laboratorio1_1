#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

double suma(double a,double b);
double resta(double a,double b);
double division(double a,double b);
double multiplicacion(double a,double b);
double factorial(double a);

double suma(double a,double b)
{
    double suma;
    suma=a+b;
    return suma;

}
double resta(double a,double b)
{
    double resta;
    resta=a-b;
    return resta;
}
double division(double a, double b)
{
    double division;
    if(b == 0)
    {
        printf("Error, no se puede dividir por cero. Reingrese los numeros \n");
        return 0;
    }
    else
    {
        division = (a / b);
        return division;
    }
}
double multiplicacion(double a, double b)
{
    double multiplicacion;
    multiplicacion=a*b;
    return multiplicacion;
}
double factorial(double a)
{
    double resultado;
    if(a == 1)
        return 1;
    resultado = a * factorial (a - 1);
    return resultado;
}





#endif // FUNCIONES_H_INCLUDED
