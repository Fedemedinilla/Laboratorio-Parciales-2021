#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "colorMascota.h"

#define VACIO 1
#define OCUPADO 0

int initColores(eColorMascota colores[],int tam)
{
    int error=1;

    int idLista[]={5000,5001,5002,5003,5004};
    char nombreColor[][20]={"Negro","Blanco","Gris","Rojo","Azul"};

    if(colores!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            colores[i].id=idLista[i];
            strcpy(colores[i].nombreColor,nombreColor[i]);
        }
        error=0;
    }

    return error;
}
int mostrarColor(eColorMascota color)
{
    int error=1;

    printf("\n        %d = %s\n",color.id,color.nombreColor);
    printf("-----------------------------\n");

    error=0;

    return error;
}
int mostrarColores(eColorMascota colores[],int tam)
{
    int error=1;

    if(colores!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            mostrarColor(colores[i]);
        }
        error=0;
    }

    return error;
}
