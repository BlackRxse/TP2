#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

#define MAX 20
#define VACIO 0
#define OCUPADO 1
#define BORRADO 2

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
    int edad;
    int dni;
    int estado;
} EPersona;

void init(EPersona lista[20]);
void alta(EPersona lista[20]);
void baja(EPersona lista[20]);
void mostrarOrdenado(EPersona lista[20]);
void imprimirgrafico(EPersona lista[20]);
void ordenamiento(EPersona lista[20]);
void colocarAll(EPersona listaaux[20], EPersona lista[20]);
int buscardni(EPersona lista[20]);
void imprimirPersona(EPersona persona);
void listasPorEdades(EPersona lista[20], EPersona lista18[20], EPersona lista19_35[20], EPersona lista35[20]);
void separarPersona(EPersona lista[20], EPersona persona);

void init(EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(lista[i].nombre, "Vacio");
        lista[i].edad = 0;
        lista[i].dni = 0;
        lista[i].estado = VACIO;
    }
}

void alta(EPersona lista[20])
{
    char aux1 [50];
    char aux2 [50];

    printf(RED "Ingrese los datos correspondientes \n" RESET);

    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == VACIO)
        {
            printf(YELLOW "Nombre: " RESET);
            scanf("%s", lista[i].nombre);

            printf(GREEN "Edad: " RESET);
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
        lista[posicion].estado = BORRADO;
        printf(GREEN "El contacto se dio de baja correctamente!\n" RESET);
    }
    else
    {
        printf(RED "No se encuentra el contacto\n" RESET);
    }
}

void mostrarOrdenado(EPersona lista[20])
{
    EPersona listaaux[20];
    colocarAll(listaaux, lista);
    ordenamiento(listaaux);
    for (int i = 0; i < MAX; i++)
    {
        printf("%s %d %d",
            listaaux[i].nombre,
            listaaux[i].edad,
            listaaux[i].dni);
        printf(CYAN " %d \n" RESET, listaaux[i].estado);
    }
}

void colocarAll(EPersona listaaux[20], EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(listaaux[i].nombre, lista[i].nombre);
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

void separarPersona(EPersona lista[20], EPersona persona)
{
    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].estado == VACIO)
        {
            strcpy(lista[i].nombre, persona.nombre);
            lista[i].edad = persona.edad;
            lista[i].dni = persona.dni;
            lista[i].estado = persona.estado;
            break;
        }
    }
}

void imprimirPersona(EPersona persona)
{
    if (strcmp(persona.nombre, "Vacio"))
    {
        printf(GREEN "   *   " RESET);
    }
    else
    {
        printf(" ");
    }
}

void listasPorEdades(EPersona lista[20], EPersona lista18[20], EPersona lista19_35[20], EPersona lista35[20])
{
    for (int i = 0; i < MAX; i++)
    {
        if (lista[i].edad <= 18)
        {
            separarPersona(lista18, lista[i]);
        }
        if (lista[i].edad > 18 && lista[i].edad <= 35)
        {
            separarPersona(lista19_35, lista[i]);
        }
        if (lista[i].edad > 35)
        {
            separarPersona(lista35, lista[i]);
        }
    }
}

void imprimirgrafico(EPersona lista[20])
{
    EPersona lista1[20];
    EPersona lista2[20];
    EPersona lista3[20];
    init(lista1);
    init(lista2);
    init(lista3);
    listasPorEdades(lista, lista1, lista2, lista3);

    printf("Grafico de edades\n\n");
    printf("  <18   19-35   >35 \n");

    for (int i = 0; i < MAX; i++)
    {
        imprimirPersona(lista1[i]);
        imprimirPersona(lista2[i]);
        imprimirPersona(lista3[i]);
        printf("\n");
    }
}

void validarDNIs(EPersona lista[20])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if(i == j)
            {
                return 1;
            }

            if(lista[i].dni == lista[j].dni)
            {
                printf("No pueden existir dos contactos con el mismo DNI");
                return 0;
            }
        }
    }
}

#endif // FUNCIONES_H_INCLUDEDS