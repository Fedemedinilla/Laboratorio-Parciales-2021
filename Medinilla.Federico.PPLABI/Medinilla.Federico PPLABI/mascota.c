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

int initMascotas(eMascota mascotas[],int tam)
{
    int error=1;

	if(mascotas!=NULL&&tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			mascotas[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}
int getEmptyIndex(eMascota mascotas[],int tam)
{
	int indiceVacio=-1;

	if(mascotas!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].isEmpty==VACIO)
			{
				indiceVacio=i;
				break;
			}
		}
	}
	return indiceVacio;
}
int agregarMascota(eMascota mascotas[],int tam, int* idMascota)
{
    int error=1;

    int indiceVacio;
    eMascota auxiliar;

    if(mascotas!=NULL && tam>0 && idMascota>0)
    {
        indiceVacio=getEmptyIndex(mascotas,tam);
        if(getNombre(auxiliar.nombreMascota,"\nIngrese el nombre: ","\nERROR - Re-ingrese el nombre.",21)==0
           && getNumero(&auxiliar.id,"\nIngrese el ID: ","\nERROR - Re-ingrese el ID.",100,*idMascota)==0
           && getNumero(&auxiliar.idTipo,"\nIngrese el ID del TIPO(1000-1004): ","\nERROR - Re-ingrese el ID del TIPO.",1000,1004)==0
           && getNumero(&auxiliar.idColor,"\nIngrese el ID del COLOR(5000-5004): ","\nERROR - Re-ingrese el ID del COLOR.",5000,5004)==0
           && getNumero(&auxiliar.edad,"\nIngrese la EDAD(1-99): ","\nERROR - Re-ingrese la EDAD.",1,99)==0)
        {
            auxiliar.id=*idMascota;
            auxiliar.isEmpty=OCUPADO;
            mascotas[indiceVacio]=auxiliar;
            (*idMascota)++;
        }
    }
    return error;
}
int buscarxID(eMascota mascotas[],char msg[],char msgError[],int tam,int* idBuscado)
{
	int indexBuscado=-1;

    getNumero(&indexBuscado,msg,msgError,tam,*idBuscado);
	if(mascotas!=NULL && tam>0 && idBuscado>=0)
	{
		for(int i=0;i<tam;i++)
		{
			if(mascotas[i].id==*idBuscado)
			{
				indexBuscado=i;
				break;
			}
		}
	}
	return indexBuscado;
}
int bajaMascota(eMascota mascotas[], int tam, int* idBuscado)
{
	int error=-1;
    int indiceABorrar;

	if(mascotas!=NULL&&tam>0)
	{
        if((indiceABorrar=buscarxID(mascotas,"\nIngrese el ID: ","\nERROR - Reingrese el ID.",100,idBuscado))>=100)
        {
            for(int i=0;i<tam;i++)
            {
                if(i==indiceABorrar)
                {
                    mascotas[i].isEmpty=VACIO;
                    error=0;
                    break;
                }
            }
        }
	}
	return error;
}


