#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "mascota.h"
#include "tipoMascota.h"
#include "colorMascota.h"
#include "servicio.h"
#include "trabajo.h"

#define VACIO 1
#define OCUPADO 0

int initServicios(eServicio servicios[],int tam)
{
    int error=1;

    int idLista[]={20000,20001,20002};
    char descripcionLista[][20]={"Corte","Desparacitado","Castrado"};
    float precioLista[]={250,300,400};

    if(servicios!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            servicios[i].id=idLista[i];
            strcpy(servicios[i].descripcion,descripcionLista[i]);
            servicios[i].precio=precioLista[i];
        }
        error=0;
    }

    return error;
}
int mostrarServicio(eServicio servicio)
{
    int error=1;

    printf("\n        %d = %s  $%.2f\n",servicio.id,servicio.descripcion,servicio.precio);
    printf("--------------------------------------------\n");

    error=0;

    return error;
}
int mostrarServicios(eServicio servicios[],int tam)
{
    int error=1;

    if(servicios!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            mostrarServicio(servicios[i]);
        }
        error=0;
    }

    return error;
}
