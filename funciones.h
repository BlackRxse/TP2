#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 20
#define VACIO 0
#define OCUPADO 1

#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define CYAN "\x1b[36m"
#define MAGENTA "\x1b[35m"
#define RESET "\x1b[0m"

typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int dni;
    int estado;
} EPersona;

void init(EPersona lista[20]);
void initMatriz(EPersona matriz[20][3]);
void alta(EPersona lista[20]);
int buscardni(EPersona lista[20]);
void baja(EPersona lista[20]);
void colocarAll(EPersona listaaux[20], EPersona lista[20]);
void ordenamiento(EPersona lista[20]);
void mostrarOrdenado(EPersona lista[20]);
void mostrarActivos(EPersona lista[20]);
void separarEnMatriz(EPersona persona, EPersona personas[20][3], int columna);
void separarEdad(EPersona lista[20], EPersona matriz[20][3]);
void imprimirPersona(EPersona persona);
void imprimirMatriz(EPersona personas[20][3]);
void imprimirGrafico(EPersona lista[20]);
int buscarnombre(EPersona lista[20]);
int buscarapellido(EPersona lista[20]);
int busquedanombre(EPersona lista[20]);
int busquedaapellido(EPersona lista[20]);
int buscar(EPersona lista[20]);

void init(EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(lista[i].nombre, "Vacio");
        strcpy(lista[i].apellido, "Vacio");
        lista[i].edad = 0;
        lista[i].dni = 0;
        lista[i].estado = VACIO;
    }
}

void initMatriz(EPersona matriz[20][3])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            strcpy(matriz[i][j].nombre, "Vacio");
            strcpy(matriz[i][j].apellido, "Vacio");
            matriz[i][j].edad = 0;
            matriz[i][j].dni = 0;
            matriz[i][j].estado = VACIO;
        }
    }
}

void alta(EPersona lista[20])
{
    printf(RED "Ingrese los datos correspondientes \n" RESET);

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == VACIO)
        {
            printf(YELLOW "Nombre: " RESET);
            scanf("%s", lista[i].nombre);

            printf(GREEN "Apellido: " RESET);
            scanf("%s", lista[i].apellido);

            printf(CYAN "Edad: " RESET);
            scanf("%d", &lista[i].edad);

            printf(BLUE "DNI: " RESET);
            scanf("%d", &lista[i].dni);

            lista[i].estado = OCUPADO;

            printf(MAGENTA "El contacto se ha agregado correctamente!\n" RESET);
            break;
        }
    }
}

int buscardni(EPersona lista[20])
{
    int posicion = -1;
    int buscDNI;

    printf(YELLOW "Ingrese el DNI: " RESET);
    scanf("%d", &buscDNI);

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == OCUPADO && lista[i].dni == buscDNI)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void baja(EPersona lista[20])
{
    int posicion = buscardni(lista);

    if (posicion != -1)
    {
        strcpy(lista[posicion].nombre, "Vacio");
        strcpy(lista[posicion].apellido, "Vacio");
        lista[posicion].edad = 0;
        lista[posicion].dni = 0;
        lista[posicion].estado = VACIO;
        printf(GREEN "El contacto se dio de baja correctamente!\n" RESET);
    }
    else
    {
        printf(RED "No se encuentra el contacto\n" RESET);
    }
}

void colocarAll(EPersona listaaux[20], EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(listaaux[i].nombre, lista[i].nombre);
        strcpy(listaaux[i].apellido, lista[i].apellido);
        listaaux[i].edad = lista[i].edad;
        listaaux[i].dni = lista[i].dni;
        listaaux[i].estado = lista[i].estado;
    }
}

void ordenamiento(EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (stricmp(lista[j].nombre, lista[j + 1].nombre) > 0)
            {
                char auxn[20];
                int aux;
                strcpy(auxn, lista[j].nombre);
                strcpy(lista[j].nombre, lista[j + 1].nombre);
                strcpy(lista[j + 1].nombre, auxn);
                strcpy(auxn, lista[j].apellido);
                strcpy(lista[j].apellido, lista[j + 1].apellido);
                strcpy(lista[j + 1].apellido, auxn);
                aux = lista[j].edad;
                lista[j].edad = lista[j + 1].edad;
                lista[j + 1].edad = aux;
                aux = lista[j].dni;
                lista[j].dni = lista[j + 1].dni;
                lista[j + 1].dni = aux;
                aux = lista[j].estado;
                lista[j].estado = lista[j + 1].estado;
                lista[j + 1].estado = aux;
            }
        }
    }
}

void mostrarOrdenado(EPersona lista[20])
{
    EPersona listaaux[20];
    colocarAll(listaaux, lista);
    ordenamiento(listaaux);
    for (int i = 0; i < MAX; i++)
    {
        printf("%s %s %d %d",
            listaaux[i].nombre,
            listaaux[i].apellido,
            listaaux[i].edad,
            listaaux[i].dni);
        printf(CYAN " %d \n" RESET, listaaux[i].estado);
    }
}

void mostrarActivos(EPersona lista[20])
{
    EPersona listaaux[20];
    colocarAll(listaaux, lista);
    ordenamiento(listaaux);
    for (int i = 0; i < MAX; i++)
    {
        if (listaaux[i].estado == OCUPADO)
        {
            printf("%s %s %d %d",
                listaaux[i].nombre,
                listaaux[i].apellido,
                listaaux[i].edad,
                listaaux[i].dni);
            printf(CYAN " %d \n" RESET, listaaux[i].estado);
        }
    }
}

void separarEnMatriz(EPersona persona, EPersona personas[20][3], int columna)
{
    for (int i = 0; i < MAX; i++)
    {
        if (personas[i][columna].estado == VACIO)
        {
            strcpy(personas[i][columna].nombre, persona.nombre);
            strcpy(personas[i][columna].apellido, persona.apellido);
            personas[i][columna].edad = persona.edad;
            personas[i][columna].dni = persona.dni;
            personas[i][columna].estado = persona.estado;
            break;
        }
    }
}

void separarEdad(EPersona lista[20], EPersona matriz[20][3])
{
    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].edad <= 18)
        {
            separarEnMatriz(lista[i], matriz, 0);
        }
        if (lista[i].edad > 18 && lista[i].edad <= 35)
        {
            separarEnMatriz(lista[i], matriz, 1);
        }
        if (lista[i].edad > 35)
        {
            separarEnMatriz(lista[i], matriz, 2);
        }
    }
}

void imprimirPersona(EPersona persona)
{
    if (strcmp(persona.nombre, "Vacio"))
    {
        printf(GREEN "  *  " RESET);
    }
    else
    {
        printf("     ");
    }
}

void imprimirMatriz(EPersona personas[20][3])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            imprimirPersona(personas[i][j]);
        }
        printf("\n");
    }
}

void imprimirGrafico(EPersona lista[20])
{
    EPersona personas[20][3];
    initMatriz(personas);
    separarEdad(lista, personas);

    printf("Grafico de edades\n\n");

    imprimirMatriz(personas);

    printf("<18  19-35  >35 \n\n");
}

int buscarnombre(EPersona lista[20])
{
    int posicion = -1;
    char buscNom[50];

    printf("Ingrese el nombre: ");
    scanf("%s", buscNom);

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == OCUPADO && strcmp(lista[i].nombre, buscNom) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

int buscarapellido(EPersona lista[20])
{
    int posicion = -1;
    char busc[50];

    printf("Ingrese el apellido: ");
    scanf("%s", busc);

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == OCUPADO && strcmp(lista[i].apellido, busc) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

int busquedanombre(EPersona lista[20])
{
    int posicion = buscarnombre(lista);

    if (posicion != -1)
    {
        printf("%s %s %d %d",
            lista[posicion].nombre,
            lista[posicion].apellido,
            lista[posicion].edad,
            lista[posicion].dni);
        printf(CYAN " %d \n" RESET, lista[posicion].estado);
    }
    else
    {
        printf("No se encontro a la persona\n");
    }
}

int busquedaapellido(EPersona lista[20])
{
    int posicion = buscarapellido(lista);

    if (posicion != -1)
    {
        printf("%s %s %d %d",
            lista[posicion].nombre,
            lista[posicion].apellido,
            lista[posicion].edad,
            lista[posicion].dni);
        printf(CYAN " %d \n" RESET, lista[posicion].estado);
    }
    else
    {
        printf("No se encontro a la persona\n");
    }
}

int buscar(EPersona lista[20])
{
    int opcion = 0;

    printf("1. Buscar por nombre: \n");
    printf("2. Buscar por apellido: \n");

    scanf("%d", &opcion);

    switch (opcion)
    {
        case 1:
        {
            busquedanombre(lista);
            break;
        }
        case 2:
        {
            busquedaapellido(lista);
            break;
        }
    }
}

#endif // FUNCIONES_H_INCLUDEDS
