#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "estructuras.h"

ePersona agregarPersona(ePersona lista[], int tam)
{
    int ld;

    ld = buscarLugar(lista, tam);

    if(ld != -1)
    {
        lista[ld].edad = pedirDatoEnteroValidado(1,"edad",100);
        strcpy(lista[ld].dni, pedirCadenaNumerosValidada("DNI", 8));
        strcpy(lista[ld].nombre, pedirDatoCadenaValidado("nombre", 50));
        strlwr(lista[ld].nombre);
        lista[ld].estado = 1;
    }
    else
    {
        printf("No hay mas espacio en el array.");
    }
    return lista[ld];
}


int buscarLugar(ePersona lista[], int tam)
{
    int i, retorno = -1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int pedirDatoEnteroValidado(int limite1, char tipo[], int limite2)
{
    int entero;
    printf("Ingrese %s:\n", tipo);
    scanf("%d", &entero);
    while(entero < limite1 || entero > limite2)
    {
        printf("%s no valido/a, reingrese:\n", tipo);
        scanf("%d", &entero);
    }
    return entero;
}


const char* pedirCadenaNumerosValidada(char mensaje[], int lar)
{
    char numero[15];
    int i, largo;
    int flagNumero = 0, flagLargo = 0, flagVeces = 0;

    do
    {
        flagLargo = 0;
        flagNumero = 0;
        if(flagVeces == 0)
        {
            printf("Ingrese %s: ", mensaje);
            flagVeces = 1;
        }
        else
        {
            printf("Reingrese %s (%d numeros): ", mensaje, lar);
        }
        fflush(stdin);
        gets(numero);
        largo = strlen(numero);

        if(largo != lar)
        {
            flagLargo = 1;
        }
        else
        {
            for(i=0; i<largo; i++)
            {
                if(isdigit(numero[i])==0)
                {
                    flagNumero = 1;
                }
            }
        }
    }while(flagNumero == 1 || flagLargo == 1);

    return numero;
}


const char* pedirDatoCadenaValidado(char tipo[], int tam)
{
    char dato[15];
    int i, largo;
    int flagNumero = 0, flagLargo = 0, flagVeces = 0;

    do
    {
        flagLargo = 0;
        flagNumero = 0;
        if(flagVeces == 0)
        {
            printf("Ingrese %s: ", tipo);
            flagVeces = 1;
        }
        else
        {
            printf("Reingrese %s (maximo %d letras): ", tipo, tam);
        }
        fflush(stdin);
        gets(dato);
        largo = strlen(dato);

        if(largo > tam)
        {
            flagLargo = 1;
        }
        else
        {
            for(i=0; i<largo; i++)
            {
                if(isdigit(dato[i])!=0)
                {
                    flagNumero = 1;
                }
            }
        }
    }while(flagNumero == 1 || flagLargo == 1);
    return dato;
}


ePersona borrarPersona(ePersona lista[], int tam)
{
    int lugar = buscarxDNI(lista, tam);
    char opcion;

    if(lugar != -1)
    {
        printf("Persona encontrada, desea borrarla? (s/n)\n");
        opcion = getche();
        switch(opcion)
        {
        case 's':
            lista[lugar].estado = 0;
            printf("Persona borrada.\n");
            break;

        case 'n':
            printf("Accion cancelada.\n");
            break;
        }
    }
    else
    {
        printf("No se encontro el DNI solicitado.");
    }
    return lista[lugar];
}


void ordenarYMostrarPorNombre(ePersona lista[], int tam)
{
    int i, j;
    ePersona aux;

    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)==1)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == 1)
        {
            printf("Nombre: %s, DNI: %s, Edad: %d\n", lista[i].nombre, lista[i].dni, lista[i].edad);
        }
    }
}


void hardcodePersonas(ePersona lista[], int tam)
{
    int i;
    char dni[][10] = {"10000000", "10000001", "10000002", "10000003", "10000004", "10000005", "10000006", "10000007", "10000008", "10000009", "10000010", "10000011", "10000012", "10000013", "10000014", "10000015", "100000016", "10000017", "10000018", "10000019", "10000020"};
    char nombre[][50] = {"Juan","Pedro","Maria","Marcelo","Abril","Monica","Roberto","Nahuel","Augusto","Leonardo","Joaquin","Pablo","Mauro","Mario","German","Octavio","Ruben","Gabriel","Valeria","Sol"};


    for(i=0;i<tam;i++)
    {
        lista[i].estado = 1;
        lista[i].edad = i*2;
        strcpy(lista[i].dni, dni[i]);
        strcpy(lista[i].nombre, nombre[i]);
    }
}


void grafico(ePersona lista[], int tam)
{
    int i,contador0_18=0,contador19_35=0,contador36_o_mas=0,mayor,flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].edad<19)
        {
            contador0_18++;
        }
        else
        {
            if(lista[i].edad<36)
            {
                contador19_35++;
            }
            else
            {
                contador36_o_mas++;
            }
        }
    }
    if(contador0_18 >= contador19_35 && contador0_18 >= contador36_o_mas)
    {
        mayor=contador0_18;
    }
    else
    {
        if(contador19_35 >= contador0_18 && contador19_35 >= contador36_o_mas)
        {
            mayor=contador19_35;
        }
        else
        {
            mayor=contador36_o_mas;
        }
    }
        for(i=mayor; i>0; i--)
        {
            if(i<=contador0_18)
            {
                printf("%c", 14);
            }
            if(i<=contador19_35)
            {
                printf("\t%c", 14);
                flag=1;
            }
            if(i<=contador36_o_mas)
            {
                if(flag==0)
                {
                    printf("\t\t%c", 14);
                }
                else
                {
                    printf("\t%c", 14);
                }
            }
            printf("\n");
        }

       printf("<18\t19-35\t>35");

return 0;
}


int buscarxDNI(ePersona lista[], int tam)
{
    int i;
    char dni[10];
    int retorno = -1;

    strcpy(dni, pedirCadenaNumerosValidada("DNI de la persona a buscar", 8));

    for(i=0;i<tam;i++)
    {
        if(strcmp(lista[i].dni, dni)==0 && lista[i].estado == 1)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
















