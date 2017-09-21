#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <windows.h>

int main()
{
    char seguir='s';
    int opcion=0;
    float numero1 = 0;
    float numero2 = 0;


    while(seguir=='s')
    {
        printf("\n===============================\n");
        printf("===== [CALCULADORA V2.6] ======\n");
        printf("===============================\n");
        printf("=== [A: %.2f] = [B: %.2f] ===== \n", numero1, numero2);
        printf("===============================\n\n");
        printf("1- Ingresar 1er operando. (A=x)\n");
        printf("2- Ingresar 2do operando. (B=y)\n");
        printf("3- Calcular la suma. (A+B)\n");
        printf("4- Calcular la resta. (A-B)\n");
        printf("5- Calcular la division. (A/B)\n");
        printf("6- Calcular la multiplicacion. (A*B)\n");
        printf("7- Calcular el factorial. (A!)\n");
        printf("8- Calcular todas las operaciones. \n");
        printf("9- Salir.\n\n");


        scanf("%d",&opcion);
        printf("\n");

        switch(opcion)
        {
            case 1:
                system("cls");
                numero1 = pedirNumeroFloat();
                break;

            case 2:
                system("cls");
                numero2 = pedirNumeroFloat();
                break;

            case 3:
                system("cls");
                sumar2Numeros(numero1, numero2);
                break;

            case 4:
                system("cls");
                restar2Numeros(numero1, numero2);
                break;

            case 5:
                system("cls");
                dividir2Numeros(numero1, numero2);
                break;

            case 6:
                system("cls");
                multiplicar2Numeros(numero1, numero2);
                break;

            case 7:
                system("cls");
                factorizar1Numero(numero1);
                factorizar1Numero(numero2);
                break;

            case 8:
                system("cls");
                sumar2Numeros(numero1, numero2);
                restar2Numeros(numero1, numero2);
                dividir2Numeros(numero1, numero2);
                multiplicar2Numeros(numero1, numero2);
                factorizar1Numero(numero1);
                factorizar1Numero(numero2);
                break;

            case 9:
                seguir = 'n';
                system("cls");
                break;

            default:
                system("cls");
                printf("Opcion incorrecta!");
                break;
        }

    }
    return 0;
}
