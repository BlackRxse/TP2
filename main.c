#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funciones.h"

#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

int main()
{
    EPersona lista[20];
    init(lista);

    char seguir = 's';
    int opcion = 0;

    while (seguir == 's')
    {
        printf( "------------------------------------------------ \n");
        printf( "|---> BIENVENIDO A TU AGENDA CODIFICADA :3 <---| \n");
        printf( "------------------------------------------------ \n \n");

        printf(RED "1- Agregar persona\n" RESET);
        printf(YELLOW "2- Borrar persona\n" RESET);
        printf(GREEN "3- Imprimir lista ordenada por nombre\n" RESET);
        printf(CYAN "4- Imprimir lista activa\n" RESET);
        printf(BLUE "5- Imprimir grafico de edades\n" RESET);
        printf(MAGENTA "6- Buscar persona\n" RESET);
        printf("7- Salir\n\n");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            alta(lista);
            break;
        }
        case 2:
        {
            baja(lista);
            break;
        }
        case 3:
        {
            mostrarOrdenado(lista);
            break;
        }
        case 4:
        {
            mostrarActivos(lista);
            break;
        }
        case 5:
        {
            imprimirGrafico(lista);
            break;
        }
        case 6:
        {
            buscar(lista);
            break;
        }
        case 7:
        {
            seguir = 'n';
            break;
        }
        }
    }
    return 0;
}
