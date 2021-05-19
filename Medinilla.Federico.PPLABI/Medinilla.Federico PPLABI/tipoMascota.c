#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "tipoMascota.h"

#define VACIO 1
#define OCUPADO 0

int initTipos(eTipoMascota tipos[],int tam)
{
    int error=1;

    int idLista[]={1000,1001,1002,1003,1004};
    char descripcionLista[][20]={"Ave","Perro","Gato","Roedor","Pez"};

    if(tipos!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            tipos[i].id=idLista[i];
            strcpy(tipos[i].descripcion,descripcionLista[i]);
        }
        error=0;
    }

    return error;
}
int mostrarTipo(eTipoMascota tipo)
{
    int error=1;

    printf("\n        %d = %s\n",tipo.id,tipo.descripcion);
    printf("-----------------------------\n");

    error=0;

    return error;
}
int mostrarTipos(eTipoMascota tipos[],int tam)
{
    int error=1;

    if(tipos!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            mostrarTipo(tipos[i]);
        }
        error=0;
    }

    return error;
}
