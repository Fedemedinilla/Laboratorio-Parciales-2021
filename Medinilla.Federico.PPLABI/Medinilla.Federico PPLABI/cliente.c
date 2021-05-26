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
#include "cliente.h"

int initClientes(eCliente clientes[],int tam)
{
    int error=1;

    int idLista[]={300,301,302,303,304};
    char sexoLista[]={'h','m','m','h','m'};
    char nombreCliente[][55]={"Carlos","Juan","Ruben","Maria","Roberto"};
    if(clientes!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            clientes[i].id=idLista[i];
            clientes[i].sexo=sexoLista[i];
            strcpy(clientes[i].nombreCliente,nombreCliente[i]);
        }
        error=0;
    }
    return error;
}
int mostrarCliente(eCliente cliente)
{
    int error=1;

    printf("\n        %d = %s\n",cliente.id,cliente.nombreCliente);
    printf("-----------------------------\n");

    error=0;

    return error;
}
int mostrarClientes(eCliente clientes[],int tam)
{
    int error=1;

    if(clientes!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            mostrarCliente(clientes[i]);
        }
        error=0;
    }

    return error;
}
