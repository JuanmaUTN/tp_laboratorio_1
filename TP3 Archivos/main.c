#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <windows.h>


int main()
{
    char seguir='s';
    int opcion=0, i;

    EMovie peliculas[20];

    for(i = 0;i < 20; i ++)
    {
        peliculas[i].estadoAltaBaja = 0;
    }

    FILE* Archivo;

    while(seguir=='s')
    {
        printf("======\n MENU \n======\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");
        printf("\nElija una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(peliculas);
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                borrarPelicula(peliculas);
                system("pause");
                system("cls");
                break;

            case 3:
               break;

            case 4:
                seguir = 'n';
                break;

            default:
                printf("\nOpcion incorrecta!");
                break;
        }
    }
    return 0;
}
