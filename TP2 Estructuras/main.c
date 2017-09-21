#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

#define tamI 3
#define tamC 3




int main()
{
    char seguir='s';
    int opcion=0, i, contLoaded;
    ePersona personas[20];

    for(i=0;i<20;i++)
    {
        personas[i].estado = 0;
    }

    hardcodePersonas(personas, 20);

    while(seguir=='s')
    {
        contLoaded = 0;
        for(i=0;i<20;i++)
        {
            if(personas[i].estado == 1)
                contLoaded++;
        }
        printf("\n========[ MENU ]========\n");
        printf("====[%d/20 cargados]====\n", contLoaded);
        printf("(1) Agregar persona.\n");
        printf("(2) Borrar persona.\n");
        printf("(3) Imprimir lista ordenada por nombre.\n");
        printf("(4) Imprimir grafico de edades.\n");
        printf("(5) Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPersona(personas, 20);
                break;
            case 2:
                system("cls");
                borrarPersona(personas, 20);
                break;
            case 3:
                system("cls");
                ordenarYMostrarPorNombre(personas, 20);
                break;
            case 4:
                system("cls");
                grafico(personas, 20);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
