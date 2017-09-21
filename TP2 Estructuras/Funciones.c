#include "Funciones.h"
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <ctype.h>

 //operaciones matemàticas

int pedirNumeroInt(int num)
{
    printf("Ingrese un numero entero: ");
    scanf("%d", &num);
    return num;
}

int sumar2Numeros(int a, int b)
{
    int resultado;
    resultado = a + b;
    printf("La suma da: %d.\n", resultado);
    return resultado;
}

int restar2Numeros(int a, int b)
{
    int resultado;
    resultado = a - b;
    printf("La resta da: %d.\n", resultado);
    return resultado;
}

int dividir2Numeros(int a, int b)
{
    int resultado;

    if(b == 0)
    {
        printf("La division da error. (No se puede dividir entre 0)\n");
        return 0;
    }
    else
    {
        resultado = a / b;
        printf("La division da: %d.\n", resultado);
    }
    return resultado;
}

int multiplicar2Numeros(int a, int b)
{
    long long int resultado;
    resultado = a * b;
    printf("La multiplicacion da: %d.\n", resultado);
    return resultado;
}

int factorizar1Numero(int numIngr)
{
    int i;
    long long int resultado = 1;

    for(i = numIngr;i > 1;i --)
    {
        resultado = resultado * i;
    }

    if(resultado <= 0)
    {
        printf("La factorizacion de %d da error.\n", numIngr);
    }
    else
    {
        printf("La factorizacion de %d da %d.\n", numIngr, resultado);
    }
    return resultado;
}

 //boludeces

int mostrarTablaAscii()
{
    printf("TABLA ASCII\n");
    int i;
    for(i = 256;i > 0;i --)
    {
        printf("( %d = %c )\n",i ,i);
    }
    return 0;
}

int saludoDeApu()
{
    char saludoApu[50] = "Gracias, vuelva prontos!";
    int i;
    printf("*Voz de Apu*\n");
    for(i = 0;i < 24;i ++)
    {
        printf("%c", saludoApu[i]);
        Sleep(70);
    }
    printf("\n");
    return 0;
}

int pantallaDeCarga()
{
    int i;
    int time = 20;
    printf("Cargando programa... ");
    for(i = 0;i < 100;i ++)
    {
        printf("(%d)", i);
        Sleep(time);
        if(i > 9)
        {
            printf("\b\b\b\b");
        }
        else
        {
            printf("\b\b\b");
        }
    }
    system("cls");
    printf("============================\n");
    printf("      Cargado con exito!\n");
    printf("============================\n");
    printf("By: Juan Manuel Costas (1-C)\n");
    printf("============================\n");
    printf(" Profesor: German Scarafilo\n");
    printf("============================\n");
    printf("\n");
    system("pause");
    system("cls");
    return 0;
}

//estructuras

eCliente cargar1Cliente(eCliente cliente[])
{
    int i, lugarDisponible;

    for(i = 0; i < 20; i ++)
    {
        if(cliente[i].flagEstado == 0)
        {
            lugarDisponible = i;
            break;
        }
    }

    printf("Ingrese el codigo del cliente: ");
    fflush(stdin);
    scanf("%d", &cliente[lugarDisponible].codigo);

    //pendiente validacion


    printf("Ingrese nombre del cliente: ");
    fflush(stdin);
    gets(cliente[lugarDisponible].nombre);

    printf("Ingrese el DNI del cliente: ");
    fflush(stdin);
    gets(cliente[lugarDisponible].dni);

    printf("Ingrese la edad del cliente: ");
    fflush(stdin);
    scanf("%d", &cliente[lugarDisponible].edad);

    while(cliente[lugarDisponible].edad < 0 || cliente[lugarDisponible].edad > 100)
    {
        printf("Reingrese la edad del cliente (0-100): ");
        fflush(stdin);
        scanf("%d", &cliente[lugarDisponible].edad);
    }

    fflush(stdin);
    cliente[lugarDisponible].flagEstado = 1;

    return cliente[lugarDisponible];
}

void mostrarClientes(eCliente cliente[])
{
    int i;
    fflush(stdin);

    printf("=========\n");
    printf("Clientes: \n");
    printf("=========\n\n");

    for(i = 0; i < 20; i ++)
    {
        if(cliente[i].flagEstado == 1)
        {
            printf("(%d)(ID: %d) (Nombre: %s) (DNI: %s) (Edad: %d)\n", i, cliente[i].codigo, cliente[i].nombre, cliente[i].dni, cliente[i].edad);
        }
    }
}

eCliente borrar1Cliente(eCliente clientes[])
{
    int i, idIngresado;
    char opcionBorrar;
    int flagEncontro = 0;

    printf("Ingrese el ID del cliente que desee borrar: ");
    scanf("%d", &idIngresado);
    fflush(stdin);

    for(i = 0; i < 20; i ++)
    {
        if(idIngresado == clientes[i].codigo)
        {
            flagEncontro = 1;
            printf("ID encontrado, borrar? (s/n) ");
            opcionBorrar = getchar();
            if(opcionBorrar == 's')
            {
                printf("Cliente borrado!\n");
                Sleep(500);
                clientes[i].flagEstado = 0;
                break;
            }
            else
            {
                if(opcionBorrar == 'n')
                {
                    printf("Operacion cancelada.\n");
                    Sleep(500);
                    clientes[i].flagEstado = 1;
                    break;
                }
            }
        }
        else
        {
            flagEncontro = 0;
        }
    }

    if(flagEncontro == 0)
    {
        printf("\nNo se encontro el cliente solicitado.");
    }

    return clientes[i];
}

void graficoEdadesHorizontal(eCliente clientes[])
{
    int i;
    int cont18 = 0, cont1935 = 0, cont35 = 0;

    for(i = 0; i < 20; i ++)
    {
        if(clientes[i].flagEstado == 1)
        {
            if(clientes[i].edad <= 18)
            {
                cont18 ++;
            }
            else
            {
                if(clientes[i].edad <= 35 && clientes[i].edad >= 19)
                {
                    cont1935 ++;
                }
                else
                {
                    if(clientes[i].edad > 35)
                    {
                        cont35 ++;
                    }
                }
            }
        }
    }

    printf("============================\nGrafico horizontal de edades: \n============================\n");

    printf("(0-18)    ");
    for(i = 0; i < cont18; i ++)
    {
        Sleep(300);
        printf(" *");
    }
    printf("\n");

    printf("(19-35)   ");
    for(i = 0; i < cont1935; i ++)
    {
        Sleep(300);
        printf(" *");
    }
    printf("\n");

    printf("(36-100)  ");
    for(i = 0; i < cont35; i ++)
    {
        Sleep(300);
        printf(" *");
    }

    printf("\n\n");



}

void ordenarNombres(eCliente clientes[])
{
    int i, j;
    eCliente aux;

    for(i = 0; i < 20; i ++)
    {
        for(j = i+1; j < 20; j ++)
        {
            if(clientes[i].flagEstado == 1 && clientes[j].flagEstado == 1)
            {
                if(strcmp(clientes[i].nombre, clientes[j].nombre) == 1)
                {
                    strcpy(aux.nombre, clientes[i].nombre);
                    strcpy(clientes[i].nombre, clientes[j].nombre);
                    strcpy(clientes[j].nombre, aux.nombre);

                    aux.edad = clientes[i].edad;
                    clientes[i].edad = clientes[j].edad;
                    clientes[j].edad = aux.edad;

                    strcpy(aux.dni, clientes[i].dni);
                    strcpy(clientes[i].dni, clientes[j].dni);
                    strcpy(clientes[j].dni, aux.dni);

                    aux.codigo = clientes[i].codigo;
                    clientes[i].codigo = clientes[j].codigo;
                    clientes[j].codigo = aux.codigo;
                }
            }

        }
    }
}




