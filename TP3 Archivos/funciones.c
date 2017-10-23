#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

EMovie agregarPelicula(EMovie movie[])
{
    int i, ld; //ld = lugar disponible

    for(i = 0;i < 20;i ++)
    {
        if(movie[i].estadoAltaBaja == 0)
        {
            ld = i;
            break;
        }
    }

    printf("Ingrese los datos de la pelicula: \n");

    fflush(stdin);
    printf("Titulo: ");
    gets(movie[ld].titulo);

    fflush(stdin);
    printf("Genero: ");
    gets(movie[ld].genero);

    fflush(stdin);
    printf("Duracion: ");
    scanf("%f", &movie[ld].duracion);
    while(movie[ld].duracion < 1)
    {
        printf("Reingrese duracion (no puede ser menor a 1): ");
        scanf("%f", &movie[ld].duracion);
    }

    fflush(stdin);
    printf("Descripcion: ");
    gets(movie[ld].descripcion);

    fflush(stdin);
    printf("Puntaje: ");
    scanf("%f", &movie[ld].puntaje);
    while(movie[ld].puntaje < 1 || movie[ld].puntaje > 10)
    {
        printf("Reingrese puntaje (0-10): ");
        scanf("%f", &movie[ld].puntaje);
    }

    fflush(stdin);
    printf("Link de imagen (Portada de la pelicula): ");
    gets(movie[ld].linkImagen);

    movie[ld].estadoAltaBaja = 1;
    return movie[ld];
}

EMovie borrarPelicula(EMovie movie[])
{
    int i, flagFound;
    char titulo[20];
    char opcion;

    printf("Peliculas:\n");
    for(i = 0; i < 20;i ++)
    {
        if(movie[i].estadoAltaBaja == 1)
        {
            printf("(Pelicula: %s)(Genero: %s)(Duracion: %.2f)\n", movie[i].titulo, movie[i].genero, movie[i].duracion);
        }
    }

    printf("Ingrese el titulo de la pelicula que quiera borrar: \n");
    fflush(stdin);
    gets(titulo);

    for(i = 0; i < 20;i ++)
    {
        if(strcmp(movie[i].titulo, titulo)==0)
        {
            flagFound = 1;
            printf("Pelicula encontrada! Desea borrarla? (s/n)\n");
            fflush(stdin);
            opcion = getche();
            if(opcion == 's')
            {
                movie[i].estadoAltaBaja = 0;
                printf("Pelicula borrada!\n");
                system("cls");
                break;
            }
            else
            {
                if(opcion == 'n')
                {
                    printf("Accion cancelada!");
                    system("cls");
                    break;
                }
            }
        }
        else
        {
            flagFound = 0;
        }
    }
    if(flagFound == 0)
    {
        printf("No se encontro la pelicula!");
    }

    return movie[i];
}

void generarPagina(EMovie lista[], char nombre[])
{

}
