#include "Funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//operaciones matemàticas

float pedirNumeroFloat()
{
    float num;
    printf("Ingrese un numero entero o decimal: ");
    scanf("%f", &num);
    return num;
}

float sumar2Numeros(float a, float b)
{
    float resultado;
    resultado = a + b;
    printf("Suma de %.2f y %.2f: %.2f.\n", a, b, resultado);
    return resultado;
}

float restar2Numeros(float a, float b)
{
    float resultado;
    resultado = a - b;
    printf("Resta de %.2f y %.2f: %.2f.\n", a, b, resultado);
    return resultado;
}

float dividir2Numeros(float a, float b)
{
    float resultado;
    char opcion;

    if(b == 0)
    {
        printf("Division de %.2f por %.2f: ERR0R! (No se puede dividir por 0)\n", a, b);
        printf("Desea intentar con otro numero? (s/n)");
        opcion = getche();
        opcion = tolower(opcion);
        printf("\n");

        switch(opcion)
        {
        case 's':
            b = pedirNumeroFloat();
            dividir2Numeros(a, b);
            break;

        case 'n':
            break;

        default:
            printf("\nOpcion incorrecta!");
            break;
        }
    }
    else
    {
        resultado = a / b;
        printf("Division de %.2f por %.2f: %.2f.\n", a, b, resultado);
    }
    return resultado;
}

float multiplicar2Numeros(float a, float b)
{
    float resultado;
    resultado = a * b;
    printf("Multiplicacion de %.2f por %.2f: %.2f.\n", a, b, resultado);
    return resultado;
}

int factorizar1Numero(float numIngr)
{
    int i;
    int numeroInt;
    char opcion;
    unsigned long long int resultado = 1;

    if(verificarNumFloat(numIngr)==0)
    {
        numeroInt = numIngr;
        for(i = numeroInt; i > 1; i --)
        {
            resultado = resultado * i;
        }

        if(numeroInt > 20)
        {
            printf("Factorial de %d: ERR0R! (solo se puede de 0 a 20)\n", numeroInt);
        }
        else
        {
            printf("Factorial de %d: %llu\n", numeroInt, resultado);
        }
    }
    else
    {
        printf("\nNo se puede calcular el factorial de %f (tiene decimales).\n", numIngr);
        printf("Desea ingresar otro numero? (s/n) (0 - 20, solo enteros).\n");
        opcion = getche();
        opcion = tolower(opcion);
        printf("\n");

        switch(opcion)
        {
        case 's':
            numIngr = pedirNumeroFloat();
            factorizar1Numero(numIngr);
            break;

        case 'n':
            break;

        default:
            printf("\nOpcion incorrecta!");
            break;
        }
    }
    return resultado;
}

int verificarNumFloat(float num)
{
    int numInt = num;
    int tieneDecimales = 0;

    if(num > numInt)
    {
        tieneDecimales = 1;
    }
    return tieneDecimales;
}

